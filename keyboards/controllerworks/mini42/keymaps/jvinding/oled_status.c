#include QMK_KEYBOARD_H
#include "jvinding.h"
#include <stdio.h>

#ifdef OLED_ENABLE

// mini42.c::oled_init_kb handles rotation (both halves at 90°) and does
// not chain into oled_init_user, so this is intentionally a pass-through.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

// ---------------------------------------------------------------------------
// Per-finger keystroke histogram — rendered on the master (right) half.
//
// The right OLED is a 128x32 SSD1306 rotated 90°, giving a portrait layout
// of 32 px wide × 128 px tall.
//
// Layout:
//   y  0.. 7  "KEYS" label
//   y  8..15  total keystroke count (5-char right-aligned field)
//   y 16..23  blank gap
//   y 24..119 histogram bars (96 px tall, auto-scaled to tallest finger)
//
// 10 bins left→right: L pinky, ring, middle, index, thumb |
//                     R thumb, index, middle, ring, pinky
//
// Bar geometry (x 0..31):
//   1-px margin, 2-px bars, 1-px gaps within each hand, 2-px divider centre.
//   x positions: 1,4,7,10,13 | divider 15-16 | 17,20,23,26,29
// ---------------------------------------------------------------------------

#define KS_FINGERS 10

enum { F_LP = 0, F_LR, F_LM, F_LI, F_LT, F_RT, F_RI, F_RM, F_RR, F_RP };

static const uint8_t ks_bar_x[KS_FINGERS] = {1, 4, 7, 10, 13, 17, 20, 23, 26, 29};

static uint32_t ks_counts[KS_FINGERS];
static uint32_t ks_total;
static uint32_t ks_max = 1;  // init 1 to avoid /0 before any key is pressed

static int8_t finger_for(uint8_t row, uint8_t col) {
    if (row >= MATRIX_ROWS || col >= MATRIX_COLS) return -1;
    bool left  = row < 4;
    bool thumb = (row == 3) || (row == 7);
    if (thumb) {
        if (col > 2) return -1;
        return left ? F_LT : F_RT;
    }
    if (left) {
        switch (col) {
            case 1: return F_LP;
            case 2: return F_LR;
            case 3: return F_LM;
            case 4: case 5: return F_LI;  // inner col shares index bin
            default: return -1;
        }
    } else {
        switch (col) {
            case 0: case 1: return F_RI;
            case 2: return F_RM;
            case 3: return F_RR;
            case 4: return F_RP;
            default: return -1;
        }
    }
}

void keystats_record_press(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed || keycode == KC_NO || keycode == KC_TRNS) return;
    int8_t f = finger_for(record->event.key.row, record->event.key.col);
    if (f < 0) return;
    ks_counts[f]++;
    ks_total++;
    if (ks_counts[f] > ks_max) ks_max = ks_counts[f];
}

static void format_count(char buf[6], uint32_t n) {
    if (n < 100000) {
        snprintf(buf, 6, "%5lu", (unsigned long)n);
    } else if (n < 10000000) {
        snprintf(buf, 6, "%4luK", (unsigned long)(n / 1000));
    } else {
        snprintf(buf, 6, "%4luM", (unsigned long)(n / 1000000));
    }
}

static void render_keystats(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("KEYS"), false);

    char buf[6];
    format_count(buf, ks_total);
    oled_set_cursor(0, 1);
    oled_write(buf, false);

    for (uint8_t f = 0; f < KS_FINGERS; f++) {
        uint8_t h   = (uint8_t)((ks_counts[f] * 96UL) / ks_max);
        uint8_t x0  = ks_bar_x[f];
        uint8_t top = (uint8_t)(120 - h);  // y from which bar pixels are lit
        for (uint8_t y = 24; y <= 119; y++) {
            bool lit = (y >= top);
            oled_write_pixel(x0,     y, lit);
            oled_write_pixel(x0 + 1, y, lit);
        }
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_keystats();
    } else {
        jv_oled_render_status();
    }
    return false;
}

#endif
