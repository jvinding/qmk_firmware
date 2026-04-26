#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef RGB_MATRIX_ENABLE

// ---------------------------------------------------------------------------
// Corne LED indices (from keyboards/crkbd/rev1/keyboard.json rgb_matrix.layout)
//
// Left side  0..26  (27 LEDs)
//   0..5   underglow (flags=2, no matrix coords)
//   6      [3,5] outer left thumb
//   7      [2,5] col5 row2
//   8      [1,5] col5 row1
//   9      [0,5] col5 row0
//  10      [0,4] col4 row0
//  11      [1,4] col4 row1
//  12      [2,4] col4 row2
//  13      [3,4] mid-inner left thumb
//  14      [3,3] inner left thumb
//  15      [2,3] col3 row2
//  16      [1,3] col3 row1
//  17      [0,3] col3 row0
//  18      [0,2] col2 row0
//  19      [1,2] col2 row1
//  20      [2,2] col2 row2
//  21      [2,1] col1 row2
//  22      [1,1] col1 row1
//  23      [0,1] col1 row0
//  24      [0,0] outer pinky row0   ← KC_WH_U / KC_WH_L
//  25      [1,0] outer pinky row1   ← KC_BTN1 / KC_BTN2
//  26      [2,0] outer pinky row2   ← KC_WH_D / KC_WH_R
//
// Right side 27..53 (mirror of left at +27)
//  27..32  underglow
//  33      [7,5] outer right thumb
//  34..52  per-key (mirror of left layout)
//  51      [4,0] outer pinky row0   ← KC_WH_L
//  52      [5,0] outer pinky row1   ← KC_BTN2
//  53      [6,0] outer pinky row2   ← KC_WH_R
// ---------------------------------------------------------------------------

#define LX_OUTER_TOP 24
#define LX_OUTER_MID 25
#define LX_OUTER_BOT 26

#define RX_OFFSET    27
#define RX_OUTER_TOP (LX_OUTER_TOP + RX_OFFSET)
#define RX_OUTER_MID (LX_OUTER_MID + RX_OFFSET)
#define RX_OUTER_BOT (LX_OUTER_BOT + RX_OFFSET)

void jv_rgb_matrix_indicators_keyboard(uint8_t layer) {
    // Outer pinky columns are always-on mouse keys on BASE/EXTRA/TAP.
    // Highlight them yellow to advertise the function.
    if (layer == JV_BASE || layer == JV_EXTRA || layer == JV_TAP) {
        rgb_matrix_set_color(LX_OUTER_TOP, RGB_YELLOW);
        rgb_matrix_set_color(LX_OUTER_MID, RGB_YELLOW);
        rgb_matrix_set_color(LX_OUTER_BOT, RGB_YELLOW);
        rgb_matrix_set_color(RX_OUTER_TOP, RGB_YELLOW);
        rgb_matrix_set_color(RX_OUTER_MID, RGB_YELLOW);
        rgb_matrix_set_color(RX_OUTER_BOT, RGB_YELLOW);
    }
}

#endif
