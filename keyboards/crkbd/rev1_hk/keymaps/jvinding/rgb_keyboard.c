#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef RGB_MATRIX_ENABLE

// Board-specific RGB accents, called after the shared per-key system in
// users/jvinding/rgb.c has already painted all keys. Add overrides here
// for any Corne-specific LEDs that need different treatment.
void jv_rgb_matrix_indicators_keyboard(uint8_t active_layer, uint8_t led_min, uint8_t led_max) {
    (void)active_layer;
    // Opaque case: underglow LEDs are not visible, turn them off.
    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
}

#endif
