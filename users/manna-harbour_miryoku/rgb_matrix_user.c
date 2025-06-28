#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"
#include "print.h"
#include "quantum.h"

void keyboard_post_init_user(void) {
    // print("HERE\n");
    // Customise these values to desired behaviour
    // debug_enable = true;
    // debug_matrix = true;
    // print("HERE 2\n");
//   debug_keyboard=true;
// debug_mouse=true;
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable();
    // print("HERE 3\n");
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    // rgb_matrix_sethsv_noeeprom(HSV_OFF);

    // print("HERE 4\n");
    // rgb_matrix_sethsv(HSV_CYAN);
#endif
    // print("HERE 5\n");
}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
 */

#ifdef RGB_MATRIX_ENABLE
#    define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
// Define colors for different key types
#    define HSV_ALPHA HSV_WHITE        // Alpha keys
#    define HSV_NUMBER HSV_BLUE        // Number keys
#    define HSV_SYMBOL HSV_GREEN       // Symbol keys
#    define HSV_FUNCTION HSV_ORANGE    // Function keys
#    define HSV_NAV HSV_CYAN           // Navigation keys
#    define HSV_MEDIA HSV_PURPLE       // Media controls
#    define HSV_MOUSE HSV_YELLOW       // Mouse controls
#    define HSV_INVERTED_T HSV_MAGENTA // Modifier keys
#    define HSV_QWERTY HSV_RED         // Modifier keys
#    define HSV_UNUSED HSV_BLACK       // Unused keys

#    define RGB_ALPHA RGB_WHITE        // Alpha keys
#    define RGB_NUMBER RGB_BLUE        // Number keys
#    define RGB_SYMBOL RGB_GREEN       // Symbol keys
#    define RGB_FUNCTION RGB_ORANGE    // Function keys
#    define RGB_NAV RGB_CYAN           // Navigation keys
#    define RGB_MEDIA RGB_PURPLE       // Media controls
#    define RGB_MOUSE RGB_YELLOW       // Mouse controls
#    define RGB_INVERTED_T RGB_MAGENTA // Modifier keys
#    define RGB_QWERTY RGB_RED         // Modifier keys
#    define RGB_UNUSED RGB_BLACK       // Unused keys

// |RGB                  |HSV                  |
// |---------------------|---------------------|
// |`RGB_AZURE`          |`HSV_AZURE`          |
// |`RGB_BLACK`/`RGB_OFF`|`HSV_BLACK`/`HSV_OFF`|
// |`RGB_BLUE`           |`HSV_BLUE`           |
// |`RGB_CHARTREUSE`     |`HSV_CHARTREUSE`     |
// |`RGB_CORAL`          |`HSV_CORAL`          |
// |`RGB_CYAN`           |`HSV_CYAN`           |
// |`RGB_GOLD`           |`HSV_GOLD`           |
// |`RGB_GOLDENROD`      |`HSV_GOLDENROD`      |
// |`RGB_GREEN`          |`HSV_GREEN`          |
// |`RGB_MAGENTA`        |`HSV_MAGENTA`        |
// |`RGB_ORANGE`         |`HSV_ORANGE`         |
// |`RGB_PINK`           |`HSV_PINK`           |
// |`RGB_PURPLE`         |`HSV_PURPLE`         |
// |`RGB_RED`            |`HSV_RED`            |
// |`RGB_SPRINGGREEN`    |`HSV_SPRINGGREEN`    |
// |`RGB_TEAL`           |`HSV_TEAL`           |
// |`RGB_TURQUOISE`      |`HSV_TURQUOISE`      |
// |`RGB_WHITE`          |`HSV_WHITE`          |
// |`RGB_YELLOW`         |`HSV_YELLOW`         |

// #   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
// #   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
// #    define RGB_MATRIX_HUE_STEP 8
// #    define RGB_MATRIX_SAT_STEP 8
// #    define RGB_MATRIX_VAL_STEP 8
// #    define RGB_MATRIX_SPD_STEP 10

/* Enable the animations you want/need.  You may need to enable only a small number of these because       *
 * they take up a lot of space.  Enable and confirm that you can still successfully compile your firmware. */
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
// #    define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #    define ENABLE_RGB_MATRIX_BREATHING
// #    define ENABLE_RGB_MATRIX_BAND_SAT
// #    define ENABLE_RGB_MATRIX_BAND_VAL
// #    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #    define ENABLE_RGB_MATRIX_CYCLE_ALL
// #    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #    define ENABLE_RGB_MATRIX_DUAL_BEACON
// #    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #    define ENABLE_RGB_MATRIX_RAINDROPS
// #    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #    define ENABLE_RGB_MATRIX_HUE_BREATHING
// #    define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #    define ENABLE_RGB_MATRIX_HUE_WAVE
// #    define ENABLE_RGB_MATRIX_PIXEL_RAIN
// #    define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
// #    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #    define ENABLE_RGB_MATRIX_SPLASH
// #    define ENABLE_RGB_MATRIX_MULTISPLASH
// #    define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

// Define a structure to hold key colors
typedef struct {
    uint8_t h;
    uint8_t s;
    uint8_t v;
} hsv_key_t;
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_key_t;

// Logical Layout
// Columns
// Left
// 0  1  2  3  4  5
//                   ROWS
// 25 24 19 18 11 10   0
//    03    02    01
// 26 23 20 17 12 09   1
//    04    05    06
// 27 22 21 16 13 08   2
//
//          15 14 07   3
//
// Right
// 0  1  2  3  4  5
//                    ROWS
// 25 24 19 18 11 10   4
//    03    02    01
// 26 23 20 17 12 09   5
//    04    05    06
// 27 22 21 16 13 08   6
//
//          15 14 07   7

// Define colors for each key in each layer
// You'll need to adjust the number of keys based on your keyboard

#    define LED_COUNT 54 // 36-key layout (3x5+3 per hand) + 6 underglow on each hand + 3 on the break away column that i don't have
#    define KEY_COUNT 36

#    define LEFT_UNDERGLOW_TOP_RIGHT 0
#    define LEFT_UNDERGLOW_TOP_MIDDLE 1
#    define LEFT_UNDERGLOW_TOP_LEFT 2
#    define LEFT_UNDERGLOW_BOTTOM_LEFT 3
#    define LEFT_UNDERGLOW_BOTTOM_MIDDLE 4
#    define LEFT_UNDERGLOW_BOTTOM_RIGHT 5

// COL 0 is the breakaway column for the 3x6 layout, I don't have it
#    define LEFT_COL0_ROW0 24
#    define LEFT_COL1_ROW0 23
#    define LEFT_COL2_ROW0 18
#    define LEFT_COL3_ROW0 17
#    define LEFT_COL4_ROW0 10
#    define LEFT_COL5_ROW0 9

#    define LEFT_COL0_ROW1 25
#    define LEFT_COL1_ROW1 22
#    define LEFT_COL2_ROW1 19
#    define LEFT_COL3_ROW1 16
#    define LEFT_COL4_ROW1 11
#    define LEFT_COL5_ROW1 8

#    define LEFT_COL0_ROW2 26
#    define LEFT_COL1_ROW2 21
#    define LEFT_COL2_ROW2 20
#    define LEFT_COL3_ROW2 15
#    define LEFT_COL4_ROW2 12
#    define LEFT_COL5_ROW2 7

#    define LEFT_THUMB_TERTIARY 14
#    define LEFT_THUMB_PRIMARY 13
#    define LEFT_THUMB_SECONDARY 6

#    define RIGHT_UNDERGLOW_TOP_LEFT 27
#    define RIGHT_UNDERGLOW_TOP_MIDDLE 28
#    define RIGHT_UNDERGLOW_TOP_RIGHT 29
#    define RIGHT_UNDERGLOW_BOTTOM_RIGHT 30
#    define RIGHT_UNDERGLOW_BOTTOM_MIDDLE 31
#    define RIGHT_UNDERGLOW_BOTTOM_LEFT 32

// COL 0 is the breakaway column for the 3x6 layout, I don't have it
#    define RIGHT_COL0_ROW0 51
#    define RIGHT_COL1_ROW0 50
#    define RIGHT_COL2_ROW0 45
#    define RIGHT_COL3_ROW0 44
#    define RIGHT_COL4_ROW0 37
#    define RIGHT_COL5_ROW0 36

#    define RIGHT_COL0_ROW1 52
#    define RIGHT_COL1_ROW1 49
#    define RIGHT_COL2_ROW1 46
#    define RIGHT_COL3_ROW1 43
#    define RIGHT_COL4_ROW1 38
#    define RIGHT_COL5_ROW1 35

#    define RIGHT_COL0_ROW2 53
#    define RIGHT_COL1_ROW2 48
#    define RIGHT_COL2_ROW2 47
#    define RIGHT_COL3_ROW2 42
#    define RIGHT_COL4_ROW2 39
#    define RIGHT_COL5_ROW2 34

#    define RIGHT_THUMB_TERTIARY 41
#    define RIGHT_THUMB_PRIMARY 40
#    define RIGHT_THUMB_SECONDARY 33

#    define LAYER_COUNT 8

enum layer_colors {
    _ALPHA,
    _QWERTY,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUMBER,
    _SYMBOL,
    _FUNCTION,
};

static const rgb_key_t layer_default_colors[LAYER_COUNT] = {{RGB_ALPHA}, {RGB_QWERTY}, {RGB_NAV}, {RGB_MOUSE}, {RGB_MEDIA}, {RGB_NUMBER}, {RGB_SYMBOL}, {RGB_FUNCTION}};
static const hsv_key_t layer_default_colors_hsv[LAYER_COUNT] = {{HSV_ALPHA}, {HSV_QWERTY}, {HSV_NAV}, {HSV_MOUSE}, {HSV_MEDIA}, {HSV_NUMBER}, {HSV_SYMBOL}, {HSV_FUNCTION}};

static const rgb_key_t base_layer_colors[KEY_COUNT] = {
    // Left hand
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_FUNCTION},
    {RGB_NUMBER},
    {RGB_SYMBOL},

    // Right hand
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_ALPHA},
    {RGB_MOUSE},
    {RGB_NAV},
    {RGB_MEDIA}};

// static const rgb_key_t base_layer_colors[LED_COUNT] = {
//     // Left hand
//     [LEFT_UNDERGLOW_TOP_LEFT] = {RGB_ALPHA}, [LEFT_UNDERGLOW_TOP_MIDDLE] = {RGB_ALPHA}, [LEFT_UNDERGLOW_TOP_RIGHT] = {RGB_ALPHA},
//     [LEFT_UNDERGLOW_BOTTOM_LEFT] = {RGB_ALPHA}, [LEFT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_ALPHA}, [LEFT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_ALPHA},

//     [LEFT_COL0_ROW0] = {RGB_UNUSED}, [LEFT_COL0_ROW1] = {RGB_UNUSED}, [LEFT_COL0_ROW2] = {RGB_UNUSED},

//     [LEFT_COL1_ROW0] = {RGB_ALPHA}, [LEFT_COL2_ROW0] = {RGB_ALPHA}, [LEFT_COL3_ROW0] = {RGB_ALPHA}, [LEFT_COL4_ROW0] = {RGB_ALPHA},  [LEFT_COL5_ROW0] = {RGB_ALPHA},
//     [LEFT_COL1_ROW1] = {RGB_ALPHA}, [LEFT_COL2_ROW1] = {RGB_ALPHA}, [LEFT_COL3_ROW1] = {RGB_ALPHA}, [LEFT_COL4_ROW1] = {RGB_ALPHA},  [LEFT_COL5_ROW1] = {RGB_ALPHA},
//     [LEFT_COL1_ROW2] = {RGB_ALPHA}, [LEFT_COL2_ROW2] = {RGB_ALPHA}, [LEFT_COL3_ROW2] = {RGB_ALPHA}, [LEFT_COL4_ROW2] = {RGB_ALPHA},  [LEFT_COL5_ROW2] = {RGB_ALPHA},
//     [LEFT_THUMB_TERTIARY] = {RGB_FUNCTION}, [LEFT_THUMB_PRIMARY] = {RGB_NUMBER}, [LEFT_THUMB_SECONDARY] = {RGB_SYMBOL},

//     // Right hand
//     [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_ALPHA}, [RIGHT_UNDERGLOW_TOP_MIDDLE] = {RGB_ALPHA}, [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_ALPHA},
//     [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_ALPHA}, [RIGHT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_ALPHA}, [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_ALPHA},

//     [RIGHT_COL0_ROW0] = {RGB_UNUSED}, [RIGHT_COL0_ROW1] = {RGB_UNUSED}, [RIGHT_COL0_ROW2] = {RGB_UNUSED},

//     [RIGHT_COL1_ROW0] = {RGB_ALPHA},  [RIGHT_COL2_ROW0] = {RGB_ALPHA},  [RIGHT_COL3_ROW0] = {RGB_ALPHA},  [RIGHT_COL4_ROW0] = {RGB_ALPHA},  [RIGHT_COL5_ROW0] = {RGB_ALPHA},
//     [RIGHT_COL1_ROW1] = {RGB_ALPHA},  [RIGHT_COL2_ROW1] = {RGB_ALPHA},  [RIGHT_COL3_ROW1] = {RGB_ALPHA},  [RIGHT_COL4_ROW1] = {RGB_ALPHA},  [RIGHT_COL5_ROW1] = {RGB_ALPHA},
//     [RIGHT_COL1_ROW2] = {RGB_ALPHA},  [RIGHT_COL2_ROW2] = {RGB_ALPHA},  [RIGHT_COL3_ROW2] = {RGB_ALPHA},  [RIGHT_COL4_ROW2] = {RGB_ALPHA},  [RIGHT_COL5_ROW2] = {RGB_ALPHA},
//     [RIGHT_THUMB_SECONDARY] = {RGB_MOUSE},  [RIGHT_THUMB_PRIMARY] = {RGB_NAV},    [RIGHT_THUMB_TERTIARY] = {RGB_MEDIA}
// };

// static const rgb_key_t qwerty_colors[LED_COUNT] = {
//     // Left hand
//     [LEFT_UNDERGLOW_TOP_LEFT] = {RGB_QWERTY}, [LEFT_UNDERGLOW_TOP_MIDDLE] = {RGB_QWERTY}, [LEFT_UNDERGLOW_TOP_RIGHT] = {RGB_QWERTY},
//     [LEFT_UNDERGLOW_BOTTOM_LEFT] = {RGB_QWERTY}, [LEFT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_QWERTY}, [LEFT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_QWERTY},

//     [LEFT_COL0_ROW0] = {RGB_UNUSED}, [LEFT_COL0_ROW1] = {RGB_UNUSED}, [LEFT_COL0_ROW2] = {RGB_UNUSED},

//     [LEFT_COL1_ROW0]  = {RGB_QWERTY},  [LEFT_COL2_ROW0]  = {RGB_QWERTY},  [LEFT_COL3_ROW0]  = {RGB_QWERTY},  [LEFT_COL4_ROW0]  = {RGB_QWERTY},  [LEFT_COL5_ROW0]  = {RGB_QWERTY},
//     [LEFT_COL1_ROW1]  = {RGB_QWERTY},  [LEFT_COL2_ROW1]  = {RGB_QWERTY},  [LEFT_COL3_ROW1]  = {RGB_QWERTY},  [LEFT_COL4_ROW1]  = {RGB_QWERTY},  [LEFT_COL5_ROW1]  = {RGB_QWERTY},
//     [LEFT_COL1_ROW2] = {RGB_QWERTY},  [LEFT_COL2_ROW2] = {RGB_QWERTY},  [LEFT_COL3_ROW2] = {RGB_QWERTY},  [LEFT_COL4_ROW2] = {RGB_QWERTY},  [LEFT_COL5_ROW2] = {RGB_QWERTY},
//     [LEFT_THUMB_TERTIARY] = {RGB_FUNCTION},[LEFT_THUMB_PRIMARY] = {RGB_NUMBER},  [LEFT_THUMB_SECONDARY] = {RGB_SYMBOL},

//     // Right hand
//     [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_QWERTY}, [RIGHT_UNDERGLOW_TOP_MIDDLE] = {RGB_QWERTY}, [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_QWERTY},
//     [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_QWERTY}, [RIGHT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_QWERTY}, [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_QWERTY},

//     [RIGHT_COL0_ROW0] = {RGB_UNUSED}, [RIGHT_COL0_ROW1] = {RGB_UNUSED}, [RIGHT_COL0_ROW2] = {RGB_UNUSED},

//     [RIGHT_COL1_ROW0] = {RGB_QWERTY},  [RIGHT_COL2_ROW0] = {RGB_QWERTY},  [RIGHT_COL3_ROW0] = {RGB_QWERTY},  [RIGHT_COL4_ROW0] = {RGB_QWERTY},  [RIGHT_COL5_ROW0] = {RGB_QWERTY},
//     [RIGHT_COL1_ROW1] = {RGB_QWERTY},  [RIGHT_COL2_ROW1] = {RGB_QWERTY},  [RIGHT_COL3_ROW1] = {RGB_QWERTY},  [RIGHT_COL4_ROW1] = {RGB_QWERTY},  [RIGHT_COL5_ROW1] = {RGB_QWERTY},
//     [RIGHT_COL1_ROW2] = {RGB_QWERTY},  [RIGHT_COL2_ROW2] = {RGB_QWERTY},  [RIGHT_COL3_ROW2] = {RGB_QWERTY},  [RIGHT_COL4_ROW2] = {RGB_QWERTY},  [RIGHT_COL5_ROW2] = {RGB_QWERTY},
//     [RIGHT_THUMB_SECONDARY] = {RGB_MOUSE},   [RIGHT_THUMB_PRIMARY] = {RGB_NAV},    [RIGHT_THUMB_TERTIARY] = {RGB_MEDIA}
// };

// static const rgb_key_t nav_colors[LED_COUNT] = {
//     // Left hand
//     [LEFT_UNDERGLOW_TOP_LEFT] = {RGB_NAV}, [LEFT_UNDERGLOW_TOP_MIDDLE] = {RGB_NAV}, [LEFT_UNDERGLOW_TOP_RIGHT] = {RGB_NAV},
//     [LEFT_UNDERGLOW_BOTTOM_LEFT] = {RGB_NAV}, [LEFT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_NAV}, [LEFT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_NAV},

//     [LEFT_COL0_ROW0] = {RGB_UNUSED}, [LEFT_COL0_ROW1] = {RGB_UNUSED}, [LEFT_COL0_ROW2] = {RGB_UNUSED},

//     [LEFT_COL1_ROW0]  = {RGB_NAV}, [LEFT_COL2_ROW0]  = {RGB_NAV},       [LEFT_COL3_ROW0]  = {RGB_INVERTED_T}, [LEFT_COL4_ROW0]  = {RGB_NAV},        [LEFT_COL5_ROW0]  = {RGB_NAV},
//     [LEFT_COL1_ROW1]  = {RGB_NAV}, [LEFT_COL2_ROW1]  = {RGB_INVERTED_T},[LEFT_COL3_ROW1]  = {RGB_INVERTED_T}, [LEFT_COL4_ROW1]  = {RGB_INVERTED_T}, [LEFT_COL5_ROW1]  = {RGB_NAV},
//     [LEFT_COL1_ROW2] = {RGB_NAV}, [LEFT_COL2_ROW2] = {RGB_NAV},       [LEFT_COL3_ROW2] = {RGB_NAV},        [LEFT_COL4_ROW2] = {RGB_NAV},        [LEFT_COL5_ROW2] = {RGB_NAV},
//     [LEFT_THUMB_TERTIARY] = {RGB_NAV}, [LEFT_THUMB_PRIMARY] = {RGB_NAV},       [LEFT_THUMB_SECONDARY] = {RGB_NAV},

//     // Right hand
//     [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_ALPHA}, [RIGHT_UNDERGLOW_TOP_MIDDLE] = {RGB_NAV}, [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_NAV},
//     [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_NAV}, [RIGHT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_NAV}, [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_NAV},

//     [RIGHT_COL0_ROW0] = {RGB_UNUSED}, [RIGHT_COL0_ROW1] = {RGB_UNUSED}, [RIGHT_COL0_ROW2] = {RGB_UNUSED},

//     [RIGHT_COL1_ROW0] = {RGB_UNUSED},    [RIGHT_COL2_ROW0] = {RGB_ALPHA},     [RIGHT_COL3_ROW0] = {RGB_QWERTY},    [RIGHT_COL4_ROW0] = {RGB_UNUSED},    [RIGHT_COL5_ROW0] = {RGB_NAV},
//     [RIGHT_COL1_ROW1] = {RGB_UNUSED},    [RIGHT_COL2_ROW1] = {RGB_NAV},       [RIGHT_COL3_ROW1] = {RGB_NAV},       [RIGHT_COL4_ROW1] = {RGB_NAV},       [RIGHT_COL5_ROW1] = {RGB_NAV},
//     [RIGHT_COL1_ROW2] = {RGB_UNUSED},    [RIGHT_COL2_ROW2] = {RGB_NUMBER},    [RIGHT_COL3_ROW2] = {RGB_NAV},       [RIGHT_COL4_ROW2] = {RGB_NAV},       [RIGHT_COL5_ROW2] = {RGB_NAV},
//     [RIGHT_THUMB_SECONDARY] = {RGB_UNUSED},    [RIGHT_THUMB_PRIMARY] = {RGB_UNUSED},    [RIGHT_THUMB_TERTIARY] = {RGB_UNUSED}
// };

// static const rgb_key_t mouse_colors[LED_COUNT] = {
//     // Left hand
//     [LEFT_UNDERGLOW_TOP_LEFT] = {RGB_MOUSE}, [LEFT_UNDERGLOW_TOP_MIDDLE] = {RGB_MOUSE}, [LEFT_UNDERGLOW_TOP_RIGHT] = {RGB_MOUSE},
//     [LEFT_UNDERGLOW_BOTTOM_LEFT] = {RGB_MOUSE}, [LEFT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_MOUSE}, [LEFT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_MOUSE},

//     [LEFT_COL0_ROW0] = {RGB_UNUSED}, [LEFT_COL0_ROW1] = {RGB_UNUSED}, [LEFT_COL0_ROW2] = {RGB_UNUSED},

//     [LEFT_COL1_ROW0]  = {RGB_MOUSE}, [LEFT_COL2_ROW0]  = {RGB_MOUSE},       [LEFT_COL3_ROW0]  = {RGB_INVERTED_T}, [LEFT_COL4_ROW0]  = {RGB_MOUSE},      [LEFT_COL5_ROW0]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW1]  = {RGB_MOUSE}, [LEFT_COL2_ROW1]  = {RGB_INVERTED_T},  [LEFT_COL3_ROW1]  = {RGB_INVERTED_T}, [LEFT_COL4_ROW1]  = {RGB_INVERTED_T}, [LEFT_COL5_ROW1]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW2] = {RGB_MOUSE}, [LEFT_COL2_ROW2] = {RGB_MOUSE},       [LEFT_COL3_ROW2] = {RGB_MOUSE},      [LEFT_COL4_ROW2] = {RGB_MOUSE},      [LEFT_COL5_ROW2] = {RGB_MOUSE},
//     [LEFT_THUMB_TERTIARY] = {RGB_MOUSE}, [LEFT_THUMB_PRIMARY] = {RGB_MOUSE},       [LEFT_THUMB_SECONDARY] = {RGB_MOUSE},

//     // Right hand
//     [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_MOUSE}, [RIGHT_UNDERGLOW_TOP_MIDDLE] = {RGB_MOUSE}, [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_MOUSE},
//     [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_MOUSE}, [RIGHT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_MOUSE}, [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_MOUSE},

//     [RIGHT_COL0_ROW0] = {RGB_UNUSED}, [RIGHT_COL0_ROW1] = {RGB_UNUSED}, [RIGHT_COL0_ROW2] = {RGB_UNUSED},

//     [RIGHT_COL1_ROW0] = {RGB_UNUSED},    [RIGHT_COL2_ROW0] = {RGB_ALPHA},     [RIGHT_COL3_ROW0] = {RGB_QWERTY},    [RIGHT_COL4_ROW0] = {RGB_UNUSED},    [RIGHT_COL5_ROW0] = {RGB_MOUSE},
//     [RIGHT_COL1_ROW1] = {RGB_UNUSED},    [RIGHT_COL2_ROW1] = {RGB_MOUSE},     [RIGHT_COL3_ROW1] = {RGB_MOUSE},     [RIGHT_COL4_ROW1] = {RGB_MOUSE},     [RIGHT_COL5_ROW1] = {RGB_MOUSE},
//     [RIGHT_COL1_ROW2] = {RGB_UNUSED},    [RIGHT_COL2_ROW2] = {RGB_MOUSE},     [RIGHT_COL3_ROW2] = {RGB_SYMBOL},    [RIGHT_COL4_ROW2] = {RGB_MOUSE},     [RIGHT_COL5_ROW2] = {RGB_MOUSE},
//     [RIGHT_THUMB_SECONDARY] = {RGB_UNUSED},    [RIGHT_THUMB_PRIMARY] = {RGB_UNUSED},    [RIGHT_THUMB_TERTIARY] = {RGB_UNUSED}
// };

// static const rgb_key_t media_colors[LED_COUNT] = {
//     // Left hand
//     [LEFT_UNDERGLOW_TOP_LEFT] = {RGB_MEDIA}, [LEFT_UNDERGLOW_TOP_MIDDLE] = {RGB_MEDIA}, [LEFT_UNDERGLOW_TOP_RIGHT] = {RGB_MEDIA},
//     [LEFT_UNDERGLOW_BOTTOM_LEFT] = {RGB_MEDIA}, [LEFT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_MEDIA}, [LEFT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_MEDIA},

//     [LEFT_COL0_ROW0] = {RGB_UNUSED}, [LEFT_COL0_ROW1] = {RGB_UNUSED}, [LEFT_COL0_ROW2] = {RGB_UNUSED},

//     [LEFT_COL1_ROW0]  = {RGB_MEDIA}, [LEFT_COL2_ROW0]  = {RGB_MEDIA},       [LEFT_COL3_ROW0]  = {RGB_INVERTED_T}, [LEFT_COL4_ROW0]  = {RGB_MEDIA},      [LEFT_COL5_ROW0]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW1]  = {RGB_MEDIA}, [LEFT_COL2_ROW1]  = {RGB_INVERTED_T},  [LEFT_COL3_ROW1]  = {RGB_INVERTED_T}, [LEFT_COL4_ROW1]  = {RGB_INVERTED_T}, [LEFT_COL5_ROW1]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW2] = {RGB_UNUSED},[LEFT_COL2_ROW2] = {RGB_UNUSED},      [LEFT_COL3_ROW2] = {RGB_UNUSED},     [LEFT_COL4_ROW2] = {RGB_UNUSED},     [LEFT_COL5_ROW2] = {RGB_MEDIA},
//     [LEFT_THUMB_TERTIARY] = {RGB_MEDIA}, [LEFT_THUMB_PRIMARY] = {RGB_MEDIA},       [LEFT_THUMB_SECONDARY] = {RGB_MEDIA},

//     // Right hand
//     [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_MEDIA}, [RIGHT_UNDERGLOW_TOP_MIDDLE] = {RGB_MEDIA}, [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_MEDIA},
//     [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_MEDIA}, [RIGHT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_MEDIA}, [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_MEDIA},

//     [RIGHT_COL0_ROW0] = {RGB_UNUSED}, [RIGHT_COL0_ROW1] = {RGB_UNUSED}, [RIGHT_COL0_ROW2] = {RGB_UNUSED},

//     [RIGHT_COL1_ROW0] = {RGB_UNUSED},    [RIGHT_COL2_ROW0] = {RGB_ALPHA},     [RIGHT_COL3_ROW0] = {RGB_QWERTY},    [RIGHT_COL4_ROW0] = {RGB_UNUSED},    [RIGHT_COL5_ROW0] = {RGB_MEDIA},
//     [RIGHT_COL1_ROW1] = {RGB_UNUSED},    [RIGHT_COL2_ROW1] = {RGB_MEDIA},     [RIGHT_COL3_ROW1] = {RGB_MEDIA},     [RIGHT_COL4_ROW1] = {RGB_MEDIA},     [RIGHT_COL5_ROW1] = {RGB_MEDIA},
//     [RIGHT_COL1_ROW2] = {RGB_UNUSED},    [RIGHT_COL2_ROW2] = {RGB_MEDIA},     [RIGHT_COL3_ROW2] = {RGB_FUNCTION},  [RIGHT_COL4_ROW2] = {RGB_UNUSED},    [RIGHT_COL5_ROW2] = {RGB_UNUSED},
//     [RIGHT_THUMB_SECONDARY] = {RGB_UNUSED},    [RIGHT_THUMB_PRIMARY] = {RGB_UNUSED},    [RIGHT_THUMB_TERTIARY] = {RGB_UNUSED}
// };

// static const rgb_key_t number_colors[LED_COUNT] = {
//     // Left hand
//     [LEFT_UNDERGLOW_TOP_LEFT] = {RGB_NUMBER}, [LEFT_UNDERGLOW_TOP_MIDDLE] = {RGB_NUMBER}, [LEFT_UNDERGLOW_TOP_RIGHT] = {RGB_NUMBER},
//     [LEFT_UNDERGLOW_BOTTOM_LEFT] = {RGB_NUMBER}, [LEFT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_NUMBER}, [LEFT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_NUMBER},

//     [LEFT_COL0_ROW0] = {RGB_UNUSED}, [LEFT_COL0_ROW1] = {RGB_UNUSED}, [LEFT_COL0_ROW2] = {RGB_UNUSED},

//     [LEFT_COL1_ROW0]  = {RGB_NUMBER}, [LEFT_COL2_ROW0]  = {RGB_UNUSED}, [LEFT_COL3_ROW0]  = {RGB_QWERTY}, [LEFT_COL4_ROW0]  = {RGB_ALPHA},  [LEFT_COL5_ROW0]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW1]  = {RGB_NUMBER}, [LEFT_COL2_ROW1]  = {RGB_NUMBER}, [LEFT_COL3_ROW1]  = {RGB_NUMBER}, [LEFT_COL4_ROW1]  = {RGB_NUMBER}, [LEFT_COL5_ROW1]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW2] = {RGB_UNUSED}, [LEFT_COL2_ROW2] = {RGB_UNUSED}, [LEFT_COL3_ROW2] = {RGB_NAV},    [LEFT_COL4_ROW2] = {RGB_NUMBER}, [LEFT_COL5_ROW2] = {RGB_UNUSED},
//     [LEFT_THUMB_TERTIARY] = {RGB_UNUSED}, [LEFT_THUMB_PRIMARY] = {RGB_UNUSED}, [LEFT_THUMB_SECONDARY] = {RGB_UNUSED},

//     // Right hand
//     [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_NUMBER}, [RIGHT_UNDERGLOW_TOP_MIDDLE] = {RGB_NUMBER}, [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_NUMBER},
//     [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_NUMBER}, [RIGHT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_NUMBER}, [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_NUMBER},

//     [RIGHT_COL0_ROW0] = {RGB_UNUSED}, [RIGHT_COL0_ROW1] = {RGB_UNUSED}, [RIGHT_COL0_ROW2] = {RGB_UNUSED},

//     [RIGHT_COL1_ROW0] = {RGB_NUMBER}, [RIGHT_COL2_ROW0] = {RGB_NUMBER}, [RIGHT_COL3_ROW0] = {RGB_NUMBER}, [RIGHT_COL4_ROW0] = {RGB_NUMBER}, [RIGHT_COL5_ROW0] = {RGB_NUMBER},
//     [RIGHT_COL1_ROW1] = {RGB_NUMBER}, [RIGHT_COL2_ROW1] = {RGB_NUMBER}, [RIGHT_COL3_ROW1] = {RGB_NUMBER}, [RIGHT_COL4_ROW1] = {RGB_NUMBER}, [RIGHT_COL5_ROW1] = {RGB_NUMBER},
//     [RIGHT_COL1_ROW2] = {RGB_NUMBER}, [RIGHT_COL2_ROW2] = {RGB_NUMBER}, [RIGHT_COL3_ROW2] = {RGB_NUMBER}, [RIGHT_COL4_ROW2] = {RGB_NUMBER}, [RIGHT_COL5_ROW2] = {RGB_NUMBER},
//     [RIGHT_THUMB_SECONDARY] = {RGB_NUMBER}, [RIGHT_THUMB_PRIMARY] = {RGB_NUMBER}, [RIGHT_THUMB_TERTIARY] = {RGB_NUMBER}
// };

// static const rgb_key_t symbol_colors[LED_COUNT] = {
//     // Left hand
//     [LEFT_UNDERGLOW_TOP_LEFT] = {RGB_SYMBOL}, [LEFT_UNDERGLOW_TOP_MIDDLE] = {RGB_SYMBOL}, [LEFT_UNDERGLOW_TOP_RIGHT] = {RGB_SYMBOL},
//     [LEFT_UNDERGLOW_BOTTOM_LEFT] = {RGB_SYMBOL}, [LEFT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_SYMBOL}, [LEFT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_SYMBOL},

//     [LEFT_COL0_ROW0] = {RGB_UNUSED}, [LEFT_COL0_ROW1] = {RGB_UNUSED}, [LEFT_COL0_ROW2] = {RGB_UNUSED},

//     [LEFT_COL1_ROW0]  = {RGB_SYMBOL}, [LEFT_COL2_ROW0]  = {RGB_UNUSED}, [LEFT_COL3_ROW0]  = {RGB_QWERTY}, [LEFT_COL4_ROW0]  = {RGB_ALPHA},  [LEFT_COL5_ROW0]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW1]  = {RGB_SYMBOL}, [LEFT_COL2_ROW1]  = {RGB_SYMBOL}, [LEFT_COL3_ROW1]  = {RGB_SYMBOL}, [LEFT_COL4_ROW1]  = {RGB_SYMBOL}, [LEFT_COL5_ROW1]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW2] = {RGB_UNUSED}, [LEFT_COL2_ROW2] = {RGB_UNUSED}, [LEFT_COL3_ROW2] = {RGB_MOUSE},  [LEFT_COL4_ROW2] = {RGB_SYMBOL}, [LEFT_COL5_ROW2] = {RGB_UNUSED},
//     [LEFT_THUMB_TERTIARY] = {RGB_UNUSED}, [LEFT_THUMB_PRIMARY] = {RGB_UNUSED}, [LEFT_THUMB_SECONDARY] = {RGB_UNUSED},

//     // Right hand
//     [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_SYMBOL}, [RIGHT_UNDERGLOW_TOP_MIDDLE] = {RGB_SYMBOL}, [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_SYMBOL},
//     [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_SYMBOL}, [RIGHT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_SYMBOL}, [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_SYMBOL},

//     [RIGHT_COL0_ROW0] = {RGB_UNUSED}, [RIGHT_COL0_ROW1] = {RGB_UNUSED}, [RIGHT_COL0_ROW2] = {RGB_UNUSED},

//     [RIGHT_COL1_ROW0] = {RGB_SYMBOL}, [RIGHT_COL2_ROW0] = {RGB_SYMBOL}, [RIGHT_COL3_ROW0] = {RGB_SYMBOL}, [RIGHT_COL4_ROW0] = {RGB_SYMBOL}, [RIGHT_COL5_ROW0] = {RGB_SYMBOL},
//     [RIGHT_COL1_ROW1] = {RGB_SYMBOL}, [RIGHT_COL2_ROW1] = {RGB_SYMBOL}, [RIGHT_COL3_ROW1] = {RGB_SYMBOL}, [RIGHT_COL4_ROW1] = {RGB_SYMBOL}, [RIGHT_COL5_ROW1] = {RGB_SYMBOL},
//     [RIGHT_COL1_ROW2] = {RGB_SYMBOL}, [RIGHT_COL2_ROW2] = {RGB_SYMBOL}, [RIGHT_COL3_ROW2] = {RGB_SYMBOL}, [RIGHT_COL4_ROW2] = {RGB_SYMBOL}, [RIGHT_COL5_ROW2] = {RGB_SYMBOL},
//     [RIGHT_THUMB_SECONDARY] = {RGB_SYMBOL}, [RIGHT_THUMB_PRIMARY] = {RGB_SYMBOL}, [RIGHT_THUMB_TERTIARY] = {RGB_SYMBOL}
// };

// static const rgb_key_t function_colors[LED_COUNT] = {
//     // Left hand
//     [LEFT_UNDERGLOW_TOP_LEFT] = {RGB_FUNCTION}, [LEFT_UNDERGLOW_TOP_MIDDLE] = {RGB_FUNCTION}, [LEFT_UNDERGLOW_TOP_RIGHT] = {RGB_FUNCTION},
//     [LEFT_UNDERGLOW_BOTTOM_LEFT] = {RGB_FUNCTION}, [LEFT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_FUNCTION}, [LEFT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_FUNCTION},

//     [LEFT_COL0_ROW0] = {RGB_UNUSED}, [LEFT_COL0_ROW1] = {RGB_UNUSED}, [LEFT_COL0_ROW2] = {RGB_UNUSED},

//     [LEFT_COL1_ROW0]  = {RGB_FUNCTION}, [LEFT_COL2_ROW0]  = {RGB_UNUSED},   [LEFT_COL3_ROW0]  = {RGB_QWERTY},   [LEFT_COL4_ROW0]  = {RGB_ALPHA},    [LEFT_COL5_ROW0]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW1]  = {RGB_FUNCTION}, [LEFT_COL2_ROW1]  = {RGB_FUNCTION}, [LEFT_COL3_ROW1]  = {RGB_FUNCTION}, [LEFT_COL4_ROW1]  = {RGB_FUNCTION}, [LEFT_COL5_ROW1]  = {RGB_UNUSED},
//     [LEFT_COL1_ROW2] = {RGB_UNUSED},   [LEFT_COL2_ROW2] = {RGB_UNUSED},   [LEFT_COL3_ROW2] = {RGB_MEDIA},    [LEFT_COL4_ROW2] = {RGB_FUNCTION}, [LEFT_COL5_ROW2] = {RGB_UNUSED},
//     [LEFT_THUMB_TERTIARY] = {RGB_UNUSED},   [LEFT_THUMB_PRIMARY] = {RGB_UNUSED},   [LEFT_THUMB_SECONDARY] = {RGB_UNUSED},

//     // Right hand
//     [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_FUNCTION}, [RIGHT_UNDERGLOW_TOP_MIDDLE] = {RGB_FUNCTION}, [RIGHT_UNDERGLOW_TOP_RIGHT] = {RGB_FUNCTION},
//     [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_FUNCTION}, [RIGHT_UNDERGLOW_BOTTOM_MIDDLE] = {RGB_FUNCTION}, [RIGHT_UNDERGLOW_BOTTOM_RIGHT] = {RGB_FUNCTION},

//     [RIGHT_COL0_ROW0] = {RGB_UNUSED}, [RIGHT_COL0_ROW1] = {RGB_UNUSED}, [RIGHT_COL0_ROW2] = {RGB_UNUSED},

//     [RIGHT_COL1_ROW0] = {RGB_FUNCTION}, [RIGHT_COL2_ROW0] = {RGB_FUNCTION}, [RIGHT_COL3_ROW0] = {RGB_FUNCTION}, [RIGHT_COL4_ROW0] = {RGB_FUNCTION}, [RIGHT_COL5_ROW0] = {RGB_FUNCTION},
//     [RIGHT_COL1_ROW1] = {RGB_FUNCTION}, [RIGHT_COL2_ROW1] = {RGB_FUNCTION}, [RIGHT_COL3_ROW1] = {RGB_FUNCTION}, [RIGHT_COL4_ROW1] = {RGB_FUNCTION}, [RIGHT_COL5_ROW1] = {RGB_FUNCTION},
//     [RIGHT_COL1_ROW2] = {RGB_FUNCTION}, [RIGHT_COL2_ROW2] = {RGB_FUNCTION}, [RIGHT_COL3_ROW2] = {RGB_FUNCTION}, [RIGHT_COL4_ROW2] = {RGB_FUNCTION}, [RIGHT_COL5_ROW2] = {RGB_FUNCTION},
//     [RIGHT_THUMB_SECONDARY] = {RGB_FUNCTION}, [RIGHT_THUMB_PRIMARY] = {RGB_FUNCTION}, [RIGHT_THUMB_TERTIARY] = {RGB_FUNCTION}
// };

// Array of layer color configurations

// static const rgb_key_t* layer_colors[] = {
// base_layer_colors,
// qwerty_colors,
// nav_colors,
// mouse_colors,
// media_colors,
// number_colors,
// symbol_colors,
// function_colors
// };

// uint8_t led_map[LED_COUNT] = {0};

/* void init_led_map(void) {
    // Initialize all positions to an invalid value (e.g., 255)
    for (int i = 0; i < LED_COUNT; i++) {
        led_map[i] = 255;
    }

    // Map physical LED indices to logical positions
    led_map[LEFT_COL1_ROW0] = 0;
    led_map[LEFT_COL2_ROW0] = 1;
    led_map[LEFT_COL3_ROW0] = 2;
    led_map[LEFT_COL4_ROW0] = 3;
    led_map[LEFT_COL5_ROW0] = 4;

    led_map[LEFT_COL1_ROW1] = 5;
    led_map[LEFT_COL2_ROW1] = 6;
    led_map[LEFT_COL3_ROW1] = 7;
    led_map[LEFT_COL4_ROW1] = 8;
    led_map[LEFT_COL5_ROW1] = 9;

    led_map[LEFT_COL1_ROW2] = 10;
    led_map[LEFT_COL2_ROW2] = 11;
    led_map[LEFT_COL3_ROW2] = 12;
    led_map[LEFT_COL4_ROW2] = 13;
    led_map[LEFT_COL5_ROW2] = 14;

    led_map[LEFT_THUMB_TERTIARY]  = 15;
    led_map[LEFT_THUMB_PRIMARY]   = 16;
    led_map[LEFT_THUMB_SECONDARY] = 17;

    led_map[RIGHT_COL1_ROW0] = 18;
    led_map[RIGHT_COL2_ROW0] = 19;
    led_map[RIGHT_COL3_ROW0] = 20;
    led_map[RIGHT_COL4_ROW0] = 21;
    led_map[RIGHT_COL5_ROW0] = 22;

    led_map[RIGHT_COL1_ROW1] = 23;
    led_map[RIGHT_COL2_ROW1] = 24;
    led_map[RIGHT_COL3_ROW1] = 25;
    led_map[RIGHT_COL4_ROW1] = 26;
    led_map[RIGHT_COL5_ROW1] = 27;

    led_map[RIGHT_COL1_ROW2] = 28;
    led_map[RIGHT_COL2_ROW2] = 29;
    led_map[RIGHT_COL3_ROW2] = 30;
    led_map[RIGHT_COL4_ROW2] = 31;
    led_map[RIGHT_COL5_ROW2] = 32;

    led_map[RIGHT_THUMB_SECONDARY] = 33;
    led_map[RIGHT_THUMB_PRIMARY]   = 34;
    led_map[RIGHT_THUMB_TERTIARY]  = 35;
} */

// Function to apply colors based on the active layer
// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     if (!rgb_matrix_is_enabled()) return false;

//     // Initialize the LED map if needed (do this once)
//     static bool map_initialized = false;
//     if (!map_initialized) {
//         init_led_map();
//         map_initialized = true;
//     }

//     uint8_t layer = get_highest_layer(layer_state);

//     // Set all LEDs to off first
//     rgb_matrix_set_color_all(0, 0, 0);

//     // Set colors based on the current layer
//     const rgb_key_t* colors;
//     switch (layer) {
//         case 0:  // Base layer
//             colors = base_layer_colors;
//             break;
//         // Add cases for other layers
//         default:
//             colors = base_layer_colors;
//             break;
//     }

//     // Apply colors to LEDs using the mapping
//     for (int i = 0; i < LED_COUNT; i++) {
//         if (led_map[i] != 255) {  // If this LED has a valid mapping
//             uint8_t logical_pos = led_map[i];
//             rgb_key_t color = colors[logical_pos];
//             rgb_matrix_set_color(i, color.r, color.g, color.b);
//         }
//     }

//     return false;
// }

/*
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer < 0 || layer >= LAYER_COUNT) {
        layer = 0;
    }

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t  index    = g_led_config.matrix_co[row][col];
            uint16_t key_code = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (index >= led_min && index < led_max && index != NO_LED) {
                rgb_key_t color = layer_default_colors[layer];
                uint8_t   flag_index = (MATRIX_COLS * row) + col;
                if (HAS_FLAGS(g_led_config.flags[flag_index], LED_FLAG_UNDERGLOW) || IS_QK_BASIC(key_code)) {
                    // print("here\n");
                    // print("basic\n");
                    rgb_matrix_set_color(index, color.r, color.g, color.b);
                } else if (IS_QK_MOD_TAP(key_code)) {
                    // print("mod tap\n");
                    rgb_matrix_set_color(index, RGB_YELLOW);
                } else if (IS_QK_MODS(key_code)) {
                    // print("mod\n");
                    rgb_matrix_set_color(index, RGB_PURPLE);
                } else if (IS_QK_MOMENTARY(key_code)) {
                    // print("momentary\n");
                    rgb_matrix_set_color(index, RGB_GREEN);
                } else {
                    // uprintf("row: %d col: %d\n", row, col);
                    // uprintf("index: %d, keycode: %#04x\n", key_code);
                }
                // rgb_key_t color = layer_default_colors[layer];
                // rgb_matrix_set_color(index, color.r, color.g, color.b);
            }
        }
        // keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
        // rgb_matrix_set_color(index, RGB_GREEN);
        // }
    }

    return false;
}
*/
/*
bool rgb_matrix_indicators_user(void) {
    print("rgb_matrix_indicators_user\n");
    // if (userspace_config.rgb_layer_change) {
    uint8_t layer = get_highest_layer(layer_state);
    //
    uprintf("layer: %d\n", layer);

    if (layer >= LAYER_COUNT) {
        layer = 0;
    }
    uprintf("layer 2: %d\n", layer);
    rgb_key_t color = layer_default_colors[layer];

    uprintf("color d: %02d %02d %02d\n", color.r, color.g, color.b);
    // uprintf("color x: %02x %02x %02x\n", color.r, color.g, color.b);
    // uprintf("color spring: %02x %02x %02x\n", RGB_SPRINGGREEN);
    rgb_matrix_set_color_all(color.r, color.g, color.b);

    return false;
}
*/
/*
bool rgb_matrix_indicators_user(void) {
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case MAC_BASE:
            rgb_matrix_set_color_all(0xFF, 0x00, 0x00);  // RGB red
            break;
        case WIN_BASE:
            rgb_matrix_set_color_all(0x00, 0xFF, 0x00);  // RGB green
            break;
        case MAC_FN:
            rgb_matrix_set_color_all(0x00, 0x00, 0xFF);  // RGB blue
            break;
        case WIN_FN:
            rgb_matrix_set_color_all(0xFF, 0xFF, 0x00);  // RGB yellow
            break;
        default:
            break;
    }
    return false;
}
*/

layer_state_t layer_state_set_rgb_light(layer_state_t state) {
    print("layer_state_set_rgb_light\n");
    // if (userspace_config.rgb_layer_change) {
    uint8_t layer = get_highest_layer(state);
    //     _ALPHA,
    // _QWERTY,
    // _NAV,
    // _MOUSE,
    // _MEDIA,
    // _NUMBER,
    // _SYMBOL,
    // _FUNCTION,
    //
    uprintf("layer: %d\n", layer);

    if (layer >= LAYER_COUNT) {
        layer = 0;
    }
    uprintf("layer 2: %d\n", layer);
    hsv_key_t color = layer_default_colors_hsv[layer];

    uprintf("color d: %02d %02d %02d\n", color.h, color.s, color.v);
    // uprintf("color x: %02x %02x %02x\n", color.r, color.g, color.b);
    // uprintf("color spring: %02x %02x %02x\n", RGB_SPRINGGREEN);
    // rgb_matrix_set_color_all(color.r, color.g, color.b);
    rgblight_sethsv_noeeprom(color.h, color.s, color.v);

    // print("1\n");

    // switch () {
    //     case _RAISE:
    //         break;
    //     case _LOWER:
    //         rgb_matrix_set_color_all(RGB_GREEN);
    //         break;
    //     case _ADJUST:
    //         rgb_matrix_set_color_all(RGB_RED);
    //         break;
    // }
    // }
    return state;
}

// rgb_matrix_indicators_useR
/* bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uprintf("led_min: %d led_max: %d\n", led_min, led_max);
    if (!rgb_matrix_is_enabled()) return false;
    print("2\n");

    // Initialize the LED map if needed (do this once)
    static bool map_initialized = false;
    if (!map_initialized) {

        init_led_map();
        map_initialized = true;
    }
    print("3\n");

    uint8_t layer = get_highest_layer(layer_state);

    // If layer is out of bounds, default to layer 0
    if (layer >= ARRAY_SIZE(layer_colors)) {
        layer = 0;
    }
    uprintf("layer: %d", layer);

    // Apply colors for the current layer
    for (uint8_t i = led_min; i < led_max && i < RGB_MATRIX_LED_COUNT; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            uprintf("%d is undergow", i);
            rgb_matrix_set_color(i, RGB_SPRINGGREEN);
        } else {
            uint8_t logical_pos = led_map[i];
            // uint8_t logical_pos = 255;
            uprintf("led_map[%d] = %d\n", i, logical_pos);
            // continue;
            // if (logical_pos < 18 && logical_pos >= 0) {
            if (logical_pos != 255) { // If this LED has a valid mapping
                const rgb_key_t color = layer_colors[layer][logical_pos];
                uprintf("RGB[%d]: %d %d %d\n", i, color.r, color.g, color.b);
                RGB_MATRIX_INDICATOR_SET_COLOR(i, color.r, color.g, color.b);
                // rgb_matrix_set_color(i, color.r, color.g, color.b);
                // rgb_matrix_set_color(i, RGB_PURPLE);
                // } else if (logical_pos < 36 && logical_pos >= 0) {
                // rgb_matrix_set_color(i, RGB_GREEN);
                // } else {
                // rgb_matrix_set_color(i, RGB_SPRINGGREEN);
            }
        }
    }

    return false;
}
 */
// Optional: Add special handling for specific keys
// void rgb_matrix_update_pwm_buffers(void) {
// This function is called after the PWM buffers are updated
// You can add special effects here if needed
// }

layer_state_t layer_state_set_user(layer_state_t state) {
    print("layer_state_set_user\n");
    state = layer_state_set_rgb_light(state);

    return state;
}

// void keyboard_post_init_user(void) {
//     rgb_matrix_enble();
//     rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//     rgb_matrix_sethsv(HSV_CYAN);
// }

#endif // RGB_MATRIX_ENABLE
