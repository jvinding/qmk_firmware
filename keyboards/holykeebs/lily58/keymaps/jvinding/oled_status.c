#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef OLED_ENABLE

// Portrait 32x128 screens (5 columns x 16 lines of text).  The master half
// (the one counting key presses) shows the per-finger keystroke histogram, as
// on the mini42; the other half shows the shared status view.
// Both halves are rotated 270.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Writes n in decimal with no padding.
static void write_uint(uint32_t n) {
    char buf[11];
    uint8_t i = sizeof(buf) - 1;
    buf[i] = '\0';
    do {
        buf[--i] = '0' + n % 10;
        n /= 10;
    } while (n);
    oled_write(&buf[i], false);
}

// Count with K/M suffix once it would crowd the line.
static void write_count(uint32_t n) {
    if (n < 100000) {
        write_uint(n);
    } else if (n < 10000000) {
        write_uint(n / 1000);
        oled_write_P(PSTR("K"), false);
    } else {
        write_uint(n / 1000000);
        oled_write_P(PSTR("M"), false);
    }
}

// ---------------------------------------------------------------------------
// Per-finger keystroke histogram, counted on the master half.
//
// y 0..7 "KEYS", y 8..15 total, y 24..119 holds 10 bars auto-scaled to the
// tallest finger: L pinky, ring, middle, index, thumb | R thumb, index,
// middle, ring, pinky.  Bars are 2 px wide at x = 1,4,7,10,13 | 17,20,23,26,29.
// ---------------------------------------------------------------------------

#define KS_FINGERS 10
#define KS_TOP     24
#define KS_BOTTOM  119

enum { F_LP = 0, F_LR, F_LM, F_LI, F_LT, F_RT, F_RI, F_RM, F_RR, F_RP };

static uint32_t ks_counts[KS_FINGERS];
static uint32_t ks_total;
static uint32_t ks_max = 1;  // 1, not 0, to avoid /0 before the first press

// Lily58 matrix: rows 0-3 / 5-8 are the main block, rows 4 / 9 hold the four
// thumb keys (cols 1-4) plus the inner 1u key (col 5, pressed by the index).
// Cols 0-1 are the pinky column pair, 4-5 the index pair, on both halves.
static int8_t finger_for(uint8_t row, uint8_t col) {
    if (row >= MATRIX_ROWS || col >= MATRIX_COLS) return -1;
    const bool left  = row < MATRIX_ROWS / 2;
    const bool thumb = (row % (MATRIX_ROWS / 2) == 4) && col >= 1 && col <= 4;
    if (thumb) return left ? F_LT : F_RT;
    switch (col) {
        case 0: case 1: return left ? F_LP : F_RP;
        case 2:         return left ? F_LR : F_RR;
        case 3:         return left ? F_LM : F_RM;
        default:        return left ? F_LI : F_RI;
    }
}

void keystats_record_press(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed || keycode == KC_NO || keycode == KC_TRNS) return;
    const int8_t f = finger_for(record->event.key.row, record->event.key.col);
    if (f < 0) return;
    ks_counts[f]++;
    ks_total++;
    if (ks_counts[f] > ks_max) ks_max = ks_counts[f];
}

static const uint8_t ks_bar_x[KS_FINGERS] = {1, 4, 7, 10, 13, 17, 20, 23, 26, 29};

static void render_keystats(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("KEYS"), false);
    oled_set_cursor(0, 1);
    write_count(ks_total);
    oled_advance_page(true);

    for (uint8_t f = 0; f < KS_FINGERS; f++) {
        const uint8_t h   = (uint8_t)((uint64_t)ks_counts[f] * (KS_BOTTOM - KS_TOP + 1) / ks_max);
        const uint8_t top = KS_BOTTOM + 1 - h;
        for (uint8_t x = ks_bar_x[f]; x < ks_bar_x[f] + 2; x++) {
            for (uint8_t y = KS_TOP; y <= KS_BOTTOM; y++) {
                oled_write_pixel(x, y, y >= top);
            }
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
