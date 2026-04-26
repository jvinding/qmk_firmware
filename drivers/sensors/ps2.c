// PS/2 pointing device driver for QMK's pointing_device subsystem.
// Bridges ps2_mouse_init() into pointing_device_driver_t, then reads
// mouse data directly from the PS/2 bus on each get_report() call.
#include "ps2.h"
#include "drivers/ps2/ps2_mouse.h"
#include "quantum/pointing_device/pointing_device.h"

static bool        ps2_driver_init(void);
static report_mouse_t ps2_driver_read(report_mouse_t mouse_report);
static void        ps2_driver_set_cpi(uint16_t cpi);
static uint16_t    ps2_driver_get_cpi(void);

const pointing_device_driver_t ps2_pointing_device_driver = {
    .init       = ps2_driver_init,
    .get_report = ps2_driver_read,
    .set_cpi    = ps2_driver_set_cpi,
    .get_cpi    = ps2_driver_get_cpi,
};

static bool ps2_driver_init(void) {
    ps2_mouse_init();
    return true;
}

static uint16_t ps2_driver_get_cpi(void) { return 0; }
static void     ps2_driver_set_cpi(uint16_t cpi) {}

static report_mouse_t ps2_driver_read(report_mouse_t mouse_report) {
    // Remote-mode poll: send READ_DATA and read 3 bytes (buttons, X, Y).
    uint8_t rcv = ps2_host_send(PS2_MOUSE_READ_DATA);
    if (rcv != PS2_ACK) {
        return mouse_report;
    }

    uint8_t btn = ps2_host_recv_response();
    uint8_t xr  = ps2_host_recv_response();
    uint8_t yr  = ps2_host_recv_response();

    bool x_neg = btn & (1 << PS2_MOUSE_X_SIGN);
    bool y_neg = btn & (1 << PS2_MOUSE_Y_SIGN);

#ifdef MOUSE_EXTENDED_REPORT
    mouse_report.x = (mouse_xy_report_t)(x_neg ? ((int16_t)xr | ~0xFF) : xr);
    mouse_report.y = (mouse_xy_report_t)(y_neg ? ((int16_t)yr | ~0xFF) : yr);
#else
    bool x_ovf = btn & (1 << PS2_MOUSE_X_OVFLW);
    bool y_ovf = btn & (1 << PS2_MOUSE_Y_OVFLW);
    mouse_report.x = x_neg ? ((!x_ovf && xr >= 1) ? -(int8_t)(256 - xr) : -127) : ((!x_ovf && xr <= 127) ? (int8_t)xr : 127);
    mouse_report.y = y_neg ? ((!y_ovf && yr >= 1) ? -(int8_t)(256 - yr) : -127) : ((!y_ovf && yr <= 127) ? (int8_t)yr : 127);
#endif

    mouse_report.x *= PS2_MOUSE_X_MULTIPLIER;
    mouse_report.y *= PS2_MOUSE_Y_MULTIPLIER;

    // QMK mouse coords: positive X = right, positive Y = down.
    // PS/2: positive Y = up — invert unless explicitly set to PS2 convention.
#ifndef PS2_MOUSE_INVERT_Y
    mouse_report.y = -mouse_report.y;
#endif
#ifdef PS2_MOUSE_INVERT_X
    mouse_report.x = -mouse_report.x;
#endif

    return mouse_report;
}
