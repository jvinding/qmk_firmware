
#include "quantum.h"
#include "rgb_matrix.h"

// Fix for split keyboard RGB matrix issues:
// 1. Enable SPLIT_TRANSPORT_MIRROR for proper RGB sync between halves
// 2. Use RGB_MATRIX_INDICATOR_SET_COLOR macro instead of direct rgb_matrix_set_color
// 3. Use RGB_MATRIX_USE_LIMITS for proper LED range handling on split keyboards

#define LEFT_UNDERGLOW_TOP_RIGHT 0
#define LEFT_UNDERGLOW_TOP_MIDDLE 1
#define LEFT_UNDERGLOW_TOP_LEFT 2
#define LEFT_UNDERGLOW_BOTTOM_LEFT 3
#define LEFT_UNDERGLOW_BOTTOM_MIDDLE 4
#define LEFT_UNDERGLOW_BOTTOM_RIGHT 5

// COL 0 is the breakaway column for the 3x6 layout, I don't have it
#define LEFT_COL0_ROW0 24
#define LEFT_COL1_ROW0 23
#define LEFT_COL2_ROW0 18
#define LEFT_COL3_ROW0 17
#define LEFT_COL4_ROW0 10
#define LEFT_COL5_ROW0 9

#define LEFT_COL0_ROW1 25
#define LEFT_COL1_ROW1 22
#define LEFT_COL2_ROW1 19
#define LEFT_COL3_ROW1 16
#define LEFT_COL4_ROW1 11
#define LEFT_COL5_ROW1 8

#define LEFT_COL0_ROW2 26
#define LEFT_COL1_ROW2 21
#define LEFT_COL2_ROW2 20
#define LEFT_COL3_ROW2 15
#define LEFT_COL4_ROW2 12
#define LEFT_COL5_ROW2 7

#define LEFT_THUMB_TERTIARY 14
#define LEFT_THUMB_PRIMARY 13
#define LEFT_THUMB_SECONDARY 6

#define RIGHT_UNDERGLOW_TOP_LEFT 27
#define RIGHT_UNDERGLOW_TOP_MIDDLE 28
#define RIGHT_UNDERGLOW_TOP_RIGHT 29
#define RIGHT_UNDERGLOW_BOTTOM_RIGHT 30
#define RIGHT_UNDERGLOW_BOTTOM_MIDDLE 31
#define RIGHT_UNDERGLOW_BOTTOM_LEFT 32

// COL 0 is the breakaway column for the 3x6 layout, I don't have it
#define RIGHT_COL0_ROW0 51
#define RIGHT_COL1_ROW0 50
#define RIGHT_COL2_ROW0 45
#define RIGHT_COL3_ROW0 44
#define RIGHT_COL4_ROW0 37
#define RIGHT_COL5_ROW0 36

#define RIGHT_COL0_ROW1 52
#define RIGHT_COL1_ROW1 49
#define RIGHT_COL2_ROW1 46
#define RIGHT_COL3_ROW1 43
#define RIGHT_COL4_ROW1 38
#define RIGHT_COL5_ROW1 35

#define RIGHT_COL0_ROW2 53
#define RIGHT_COL1_ROW2 48
#define RIGHT_COL2_ROW2 47
#define RIGHT_COL3_ROW2 42
#define RIGHT_COL4_ROW2 39
#define RIGHT_COL5_ROW2 34

#define RIGHT_THUMB_TERTIARY 41
#define RIGHT_THUMB_PRIMARY 40
#define RIGHT_THUMB_SECONDARY 33

#define LAYER_COUNT 8

enum layers { _ALPHA, _QWERTY, _WINDOWS, _BUTTON, _NAV, _MOUSE, _MEDIA, _NUMBER, _NUMPAD, _SYMBOL, _FUNCTION };
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_key_t;

#define HSV_ALPHA HSV_WHITE
#define HSV_QWERTY HSV_RED
#define HSV_WINDOWS HSV_SPRINGGREEN
#define HSV_BUTTON HSV_PINK
#define HSV_NAV HSV_CYAN
#define HSV_MOUSE HSV_YELLOW
#define HSV_MEDIA HSV_PURPLE
#define HSV_NUMBER HSV_BLUE
#define HSV_NUMPAD HSV_TURQUOISE
#define HSV_SYMBOL HSV_GREEN
#define HSV_FUNCTION HSV_ORANGE
#define HSV_INVERTED_T HSV_MAGENTA
#define HSV_UNUSED HSV_BLACK

#define RGB_ALPHA RGB_WHITE
#define RGB_QWERTY RGB_RED
#define RGB_WINDOWS RGB_SPRINGGREEN
#define RGB_BUTTON RGB_PINK
#define RGB_NAV RGB_CYAN
#define RGB_MOUSE RGB_YELLOW
#define RGB_MEDIA RGB_PURPLE
#define RGB_NUMBER RGB_BLUE
#define RGB_NUMPAD RGB_TURQUOISE
#define RGB_SYMBOL RGB_GREEN
#define RGB_FUNCTION RGB_ORANGE
#define RGB_INVERTED_T RGB_MAGENTA
#define RGB_UNUSED RGB_BLACK

// static const rgb_key_t layer_default_colors[LAYER_COUNT] = {{RGB_ALPHA}, {RGB_QWERTY}, {RGB_NAV}, {RGB_MOUSE}, {RGB_MEDIA}, {RGB_NUMBER}, {RGB_SYMBOL}, {RGB_FUNCTION}};

void keyboard_post_init_user(void) {
    // https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
    // set initial effect on keyboard start; ignore what's in EEPROM!
    // rgb_matrix_mode_noeeprom(
    // RGB_MATRIX_TYPING_HEATMAP
    //   RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    // );

    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
    /*
    // https://docs.qmk.fm/#/feature_rgb_matrix?id=indicators-without-rgb-matrix-effect
    //
    // Indicators without RGB Matrix Effect
    //
    // If you want to just use RGB indicators without RGB matrix effect, it is not
    // possible to disable the latter because toggling RGB off will disable
    // everything. You can workaround it with solid effect and colors off using
    // this init function:
    //
    // rgb_matrix_sethsv_noeeprom(HSV_OFF); // XXX: this throws away the color!
    HSV hsv = rgb_matrix_get_hsv();
    rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, 0); // turn off, preserving color
    */
}

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     rgb_key_t color = {RGB_ALPHA};
//     // RGB_MATRIX_USE_LIMITS(led_min, led_max);
//     for (uint8_t index = led_min; index < led_max; ++index) {
//         RGB_MATRIX_INDICATOR_SET_COLOR(index, color.r, color.g, color.b);
//     }
//     return false;
// }
// for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
//     for (uint8_t col = 1; col < MATRIX_COLS; ++col) {
//         uint8_t index = g_led_config.matrix_co[row][col];
//         if (index != NO_LED) {
//             RGB_MATRIX_INDICATOR_SET_COLOR(index, RGB_ALPHA.r, RGB_ALPHA.g, RGB_ALPHA.b);
//         }
//     }
// }
// }
bool rgb_matrix_indicators_user(void) {
    // if (is_keyboard_left()) return false;
    // uprintf("rgb_matrix_indicators_user side: %s\n", is_keyboard_left() ? "left" : "right");
    // uint8_t       led_min               = 0;
    // uint8_t       led_max               = RGB_MATRIX_LED_COUNT;
    // const uint8_t k_rgb_matrix_split[2] = RGB_MATRIX_SPLIT;
    // if (is_keyboard_left() && (led_max > k_rgb_matrix_split[0])) led_max = k_rgb_matrix_split[0];
    // if (!(is_keyboard_left()) && (led_min < k_rgb_matrix_split[0])) led_min = k_rgb_matrix_split[0];

    // uprintf("led_min: %d led_max: %d\n", led_min, led_max);

    // rgb_matrix_sethsv_noeeprom(HSV_OFF);

    // for (uint8_t index = led_min; index < led_max; ++index) {
    //     rgb_matrix_set_color(index, RGB_WHITE);
    // }
    // if (true) return false;

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _ALPHA:
            rgb_matrix_sethsv_noeeprom(HSV_ALPHA);
            // rgb_matrix_set_color_all(RGB_ALPHA);
            // Use direct rgb_matrix_set_color calls - these should work with SPLIT_TRANSPORT_MIRROR enabled
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_THUMB_PRIMARY, RGB_NUMBER);
                rgb_matrix_set_color(LEFT_THUMB_SECONDARY, RGB_SYMBOL);
                rgb_matrix_set_color(LEFT_THUMB_TERTIARY, RGB_FUNCTION);
            } else {
                rgb_matrix_set_color(RIGHT_THUMB_PRIMARY, RGB_NAV);
                rgb_matrix_set_color(RIGHT_THUMB_SECONDARY, RGB_MOUSE);
                rgb_matrix_set_color(RIGHT_THUMB_TERTIARY, RGB_MEDIA);
            }
            break;
        case _QWERTY:
            rgb_matrix_sethsv_noeeprom(HSV_QWERTY);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_THUMB_PRIMARY, RGB_NUMBER);
                rgb_matrix_set_color(LEFT_THUMB_SECONDARY, RGB_SYMBOL);
                rgb_matrix_set_color(LEFT_THUMB_TERTIARY, RGB_FUNCTION);
            } else {
                rgb_matrix_set_color(RIGHT_THUMB_PRIMARY, RGB_NAV);
                rgb_matrix_set_color(RIGHT_THUMB_SECONDARY, RGB_MOUSE);
                rgb_matrix_set_color(RIGHT_THUMB_TERTIARY, RGB_MEDIA);
            }
            break;
        case _WINDOWS:
            rgb_matrix_sethsv_noeeprom(HSV_WINDOWS);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_THUMB_PRIMARY, RGB_NUMBER);
                rgb_matrix_set_color(LEFT_THUMB_SECONDARY, RGB_SYMBOL);
                rgb_matrix_set_color(LEFT_THUMB_TERTIARY, RGB_FUNCTION);
            } else {
                rgb_matrix_set_color(RIGHT_THUMB_PRIMARY, RGB_NAV);
                rgb_matrix_set_color(RIGHT_THUMB_SECONDARY, RGB_MOUSE);
                rgb_matrix_set_color(RIGHT_THUMB_TERTIARY, RGB_MEDIA);
            }
            break;
        case _BUTTON:
            rgb_matrix_sethsv_noeeprom(HSV_BUTTON);
            break;
        case _NAV:
            rgb_matrix_sethsv_noeeprom(HSV_NAV);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_COL3_ROW0, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL2_ROW1, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL3_ROW1, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL4_ROW1, RGB_INVERTED_T);
            } else {
                rgb_matrix_set_color(RIGHT_COL5_ROW0, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL4_ROW0, RGB_ALPHA);
                rgb_matrix_set_color(RIGHT_COL3_ROW0, RGB_QWERTY);
                rgb_matrix_set_color(RIGHT_COL2_ROW0, RGB_WINDOWS);

                rgb_matrix_set_color(RIGHT_COL5_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL3_ROW2, RGB_NUMBER);
                rgb_matrix_set_color(RIGHT_COL2_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL1_ROW2, RGB_UNUSED);

                rgb_matrix_set_color(RIGHT_THUMB_PRIMARY, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_THUMB_SECONDARY, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_THUMB_TERTIARY, RGB_UNUSED);
            }
            break;
        case _MOUSE:
            rgb_matrix_sethsv_noeeprom(HSV_MOUSE);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_COL3_ROW0, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL2_ROW1, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL3_ROW1, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL4_ROW1, RGB_INVERTED_T);
            } else {
                rgb_matrix_set_color(RIGHT_COL5_ROW0, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL4_ROW0, RGB_ALPHA);
                rgb_matrix_set_color(RIGHT_COL3_ROW0, RGB_QWERTY);
                rgb_matrix_set_color(RIGHT_COL2_ROW0, RGB_WINDOWS);

                rgb_matrix_set_color(RIGHT_COL5_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL3_ROW2, RGB_SYMBOL);
                rgb_matrix_set_color(RIGHT_COL2_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL1_ROW2, RGB_UNUSED);

                rgb_matrix_set_color(RIGHT_THUMB_PRIMARY, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_THUMB_SECONDARY, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_THUMB_TERTIARY, RGB_UNUSED);
            }
            break;
        case _MEDIA:
            rgb_matrix_sethsv_noeeprom(HSV_MEDIA);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_COL3_ROW0, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL2_ROW1, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL3_ROW1, RGB_INVERTED_T);
                rgb_matrix_set_color(LEFT_COL4_ROW1, RGB_INVERTED_T);

                rgb_matrix_set_color(LEFT_THUMB_TERTIARY, RGB_UNUSED);
            } else {
                rgb_matrix_set_color(RIGHT_COL5_ROW0, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL4_ROW0, RGB_ALPHA);
                rgb_matrix_set_color(RIGHT_COL3_ROW0, RGB_QWERTY);
                rgb_matrix_set_color(RIGHT_COL2_ROW0, RGB_WINDOWS);

                rgb_matrix_set_color(RIGHT_COL5_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL3_ROW2, RGB_FUNCTION);
                rgb_matrix_set_color(RIGHT_COL2_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_COL1_ROW2, RGB_UNUSED);

                rgb_matrix_set_color(RIGHT_THUMB_PRIMARY, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_THUMB_SECONDARY, RGB_UNUSED);
                rgb_matrix_set_color(RIGHT_THUMB_TERTIARY, RGB_UNUSED);
            }
            break;
        case _NUMBER:
            rgb_matrix_sethsv_noeeprom(HSV_NUMBER);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_COL2_ROW0, RGB_WINDOWS);
                rgb_matrix_set_color(LEFT_COL3_ROW0, RGB_QWERTY);
                rgb_matrix_set_color(LEFT_COL4_ROW0, RGB_ALPHA);
                rgb_matrix_set_color(LEFT_COL5_ROW0, RGB_NUMPAD);

                rgb_matrix_set_color(LEFT_COL1_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_COL2_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_COL3_ROW2, RGB_NAV);
                rgb_matrix_set_color(LEFT_COL5_ROW2, RGB_UNUSED);

                rgb_matrix_set_color(LEFT_THUMB_PRIMARY, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_THUMB_SECONDARY, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_THUMB_TERTIARY, RGB_UNUSED);
            }
            break;
         case _NUMPAD:
            rgb_matrix_sethsv_noeeprom(HSV_NUMPAD);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_COL2_ROW0, RGB_WINDOWS);
                rgb_matrix_set_color(LEFT_COL3_ROW0, RGB_QWERTY);
                rgb_matrix_set_color(LEFT_COL4_ROW0, RGB_ALPHA);
                rgb_matrix_set_color(LEFT_COL5_ROW0, RGB_UNUSED);

                rgb_matrix_set_color(LEFT_COL1_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_COL2_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_COL3_ROW2, RGB_NAV);
                rgb_matrix_set_color(LEFT_COL5_ROW2, RGB_UNUSED);

                rgb_matrix_set_color(LEFT_THUMB_PRIMARY, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_THUMB_SECONDARY, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_THUMB_TERTIARY, RGB_UNUSED);
            }
            break;
        case _SYMBOL:
            rgb_matrix_sethsv_noeeprom(HSV_SYMBOL);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_COL2_ROW0, RGB_WINDOWS);
                rgb_matrix_set_color(LEFT_COL3_ROW0, RGB_QWERTY);
                rgb_matrix_set_color(LEFT_COL4_ROW0, RGB_ALPHA);
                rgb_matrix_set_color(LEFT_COL5_ROW0, RGB_UNUSED);

                rgb_matrix_set_color(LEFT_COL1_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_COL2_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_COL3_ROW2, RGB_MOUSE);
                rgb_matrix_set_color(LEFT_COL5_ROW2, RGB_UNUSED);

                rgb_matrix_set_color(LEFT_THUMB_PRIMARY, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_THUMB_SECONDARY, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_THUMB_TERTIARY, RGB_UNUSED);
            }
            break;
        case _FUNCTION:
            rgb_matrix_sethsv_noeeprom(HSV_FUNCTION);
            if (is_keyboard_left()) {
                rgb_matrix_set_color(LEFT_COL2_ROW0, RGB_WINDOWS);
                rgb_matrix_set_color(LEFT_COL3_ROW0, RGB_QWERTY);
                rgb_matrix_set_color(LEFT_COL4_ROW0, RGB_ALPHA);
                rgb_matrix_set_color(LEFT_COL5_ROW0, RGB_UNUSED);

                rgb_matrix_set_color(LEFT_COL1_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_COL2_ROW2, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_COL3_ROW2, RGB_MEDIA);
                rgb_matrix_set_color(LEFT_COL5_ROW2, RGB_UNUSED);

                rgb_matrix_set_color(LEFT_THUMB_PRIMARY, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_THUMB_SECONDARY, RGB_UNUSED);
                rgb_matrix_set_color(LEFT_THUMB_TERTIARY, RGB_UNUSED);
            }

            break;
    }
    return false;
}
