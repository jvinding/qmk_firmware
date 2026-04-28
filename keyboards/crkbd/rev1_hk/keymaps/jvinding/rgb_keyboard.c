#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef RGB_MATRIX_ENABLE

// Board-specific RGB accents, called after the shared per-key system in
// users/jvinding/rgb.c has already painted all keys. Add overrides here
// for any Corne-specific LEDs that need different treatment.
void jv_rgb_matrix_indicators_keyboard(uint8_t active_layer, uint8_t led_min, uint8_t led_max) {
    (void)active_layer;
    (void)led_min;
    (void)led_max;
}

#endif
