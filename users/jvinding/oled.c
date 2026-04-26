#include QMK_KEYBOARD_H
#include "jvinding.h"
#include "caps_word.h"
#include "users/holykeebs/pointing.h"

// caps_word_set_user runs on the master (right) whenever caps word turns on or
// off.  Mark g_hk_state dirty so the existing holykeebs housekeeping task
// syncs the new value to the slave (left) within ~100 ms.
void caps_word_set_user(bool active) {
    g_hk_state.caps_word = active;
    g_hk_state.dirty     = true;
}

#ifdef OLED_ENABLE

static const char * const jv_layer_names[] = {
    [JV_BASE]   = "Base",
    [JV_EXTRA]  = "Extra",
    [JV_TAP]    = "Tap",
    [JV_BUTTON] = "Btn",
    [JV_NAV]    = "Nav",
    [JV_MOUSE]  = "Mouse",
    [JV_MEDIA]  = "Media",
    [JV_NUM]    = "Num",
    [JV_NUMPAD] = "NPad",
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
    oled_write_ln_P(PSTR("Layer"), false);
    oled_write_ln_P(PSTR("-----"), false);
    if (layer < ARRAY_SIZE(jv_layer_names) && jv_layer_names[layer]) {
        oled_write_ln(jv_layer_names[layer], false);
    } else {
        oled_write_ln_P(PSTR("?"), false);
    }

    oled_write_ln_P(PSTR(""), false);

    led_t led = host_keyboard_led_state();
    oled_write_ln_P(led.caps_lock     ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_ln_P(g_hk_state.caps_word ? PSTR("CWRD") : PSTR("    "), false);

    return false;
}

#endif
