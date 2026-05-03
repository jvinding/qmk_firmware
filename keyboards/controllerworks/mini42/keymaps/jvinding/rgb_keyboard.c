#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef RGB_MATRIX_ENABLE

// Outer-column positions ([r,0] left / [r+4,5] right) have KC_NO on every
// layer, so the shared picker in rgb.c already maps them to the active-layer
// color.  No explicit override is needed here.
void jv_rgb_matrix_indicators_keyboard(uint8_t active_layer, uint8_t led_min, uint8_t led_max) {
    (void)active_layer;
    (void)led_min;
    (void)led_max;
}

#endif
