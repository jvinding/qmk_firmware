#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"

#ifdef OLED_ENABLE
static const char *layer_names[] = {
#define MIRYOKU_X(LAYER, STRING) STRING,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

bool oled_task_user(void) {
    layer_state_t layer = get_highest_layer(layer_state);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    oled_write(layer_names[layer], false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
