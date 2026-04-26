#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef RGB_MATRIX_ENABLE

// Per-keyboard hook: override in each keymap's rgb_keyboard.c to add
// per-LED accents on top of the solid layer colour set here.
__attribute__((weak)) void jv_rgb_matrix_indicators_keyboard(uint8_t layer) {}

bool rgb_matrix_indicators_user(void) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);

    // Convert the per-layer HSV colour to RGB and write it directly into
    // the pixel buffer.  rgb_matrix_set_color_all() overrides whatever the
    // active animation has just rendered, so the displayed colour is always
    // the layer colour regardless of which animation mode is stored in EEPROM.
    HSV hsv;
    switch (layer) {
        case JV_BASE:   hsv = (HSV){HSV_WHITE};       break;
        case JV_EXTRA:  hsv = (HSV){HSV_RED};         break;
        case JV_TAP:    hsv = (HSV){HSV_SPRINGGREEN}; break;
        case JV_BUTTON: hsv = (HSV){HSV_PINK};        break;
        case JV_NAV:    hsv = (HSV){HSV_CYAN};        break;
        case JV_MOUSE:  hsv = (HSV){HSV_YELLOW};      break;
        case JV_MEDIA:  hsv = (HSV){HSV_PURPLE};      break;
        case JV_NUM:    hsv = (HSV){HSV_BLUE};        break;
        case JV_NUMPAD: hsv = (HSV){HSV_TEAL};        break;
        case JV_SYM:    hsv = (HSV){HSV_GREEN};       break;
        case JV_FUN:    hsv = (HSV){HSV_ORANGE};      break;
        default:        hsv = (HSV){HSV_OFF};         break;
    }
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);

    jv_rgb_matrix_indicators_keyboard(layer);
    return false;
}

#endif
