#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef OLED_ENABLE

static const char * const jv_layer_names[] = {
    [JV_BASE]   = "Base",
    [JV_EXTRA]  = "Extra",
    [JV_TAP]    = "Tap",
    [JV_BUTTON] = "Button",
    [JV_NAV]    = "Nav",
    [JV_MOUSE]  = "Mouse",
    [JV_MEDIA]  = "Media",
    [JV_NUM]    = "Num",
    [JV_NUMPAD] = "Numpad",
    [JV_SYM]    = "Sym",
    [JV_FUN]    = "Fun",
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // OLED is on the left half; rotate 270 so text reads top-to-bottom
    // on a vertically-mounted display.
    return is_keyboard_left() ? OLED_ROTATION_270 : rotation;
}

bool oled_task_user(void) {
    // Only the left half (which carries the OLED) renders.
    // layer_state is synced from master (right) via SPLIT_LAYER_STATE_ENABLE.
    if (!is_keyboard_left()) return false;

    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR("\n"), false);
    if (layer < sizeof(jv_layer_names) / sizeof(jv_layer_names[0])) {
        oled_write(jv_layer_names[layer], false);
    }

    oled_write_P(PSTR("\n\n"), false);

    led_t led = host_keyboard_led_state();
    oled_write_P(led.caps_lock ? PSTR("CAPS\n") : PSTR("    \n"), false);

    return false;
}

#endif
