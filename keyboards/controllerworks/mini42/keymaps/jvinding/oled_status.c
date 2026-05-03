#include QMK_KEYBOARD_H
#include "jvinding.h"
#include <stdio.h>

#ifdef OLED_ENABLE

// mini42.c::oled_init_kb handles rotation (master=0°, slave=180°) and does
// not chain into oled_init_user, so this is intentionally a pass-through.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

// ---------------------------------------------------------------------------
// Status board — rendered on the slave (left) half.
//
// All state used here is synced by the split transport:
//   layer_state       SPLIT_LAYER_STATE_ENABLE  (keyboard.json)
//   get_mods()        SPLIT_MODS_ENABLE         (keyboard.json)
//   get_current_wpm() SPLIT_WPM_ENABLE           (config.h)
//   timer_read32()    runs locally on each half
// ---------------------------------------------------------------------------

static void render_layer_line(void) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    oled_write_P(PSTR("LYR "), false);
    if (layer < (JV_FUN + 1) && jv_layer_names[layer]) {
        oled_write_ln(jv_layer_names[layer], false);
    } else {
        oled_write_ln_P(PSTR("?"), false);
    }
}

static void render_mods_line(void) {
    uint8_t m = get_mods();
    char buf[5];
    buf[0] = (m & MOD_MASK_SHIFT) ? 'S' : '.';
    buf[1] = (m & MOD_MASK_CTRL)  ? 'C' : '.';
    buf[2] = (m & MOD_MASK_ALT)   ? 'A' : '.';
    buf[3] = (m & MOD_MASK_GUI)   ? 'G' : '.';
    buf[4] = '\0';
    oled_write_P(PSTR("MOD "), false);
    oled_write_ln(buf, false);
}

static void render_wpm_line(void) {
    char buf[8];
    snprintf(buf, sizeof(buf), "%3u", get_current_wpm());
    oled_write_P(PSTR("WPM "), false);
    oled_write_ln(buf, false);
}

static void render_uptime_line(void) {
    uint32_t s  = timer_read32() / 1000;
    uint16_t h  = (uint16_t)(s / 3600);
    uint8_t  m  = (uint8_t)((s % 3600) / 60);
    uint8_t  ss = (uint8_t)(s % 60);
    char buf[12];
    snprintf(buf, sizeof(buf), "%uh%02um%02u", h, m, ss);
    oled_write_P(PSTR("UP  "), false);
    oled_write_ln(buf, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        jv_oled_draw_layer_caps();
    } else {
        render_layer_line();
        render_mods_line();
        render_wpm_line();
        render_uptime_line();
    }
    return false;
}

#endif
