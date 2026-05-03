#include QMK_KEYBOARD_H
#include "jvinding.h"
#include "caps_word.h"
#ifdef HK_MASTER_RIGHT
#include "users/holykeebs/pointing.h"
#endif

#ifndef HK_MASTER_RIGHT
static bool s_caps_word;
#endif

void caps_word_set_user(bool active) {
#ifdef HK_MASTER_RIGHT
    g_hk_state.caps_word = active;
    g_hk_state.dirty     = true;
#else
    s_caps_word = active;
#endif
}

#ifdef OLED_ENABLE

const char * const jv_layer_names[] = {
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

void jv_oled_draw_layer_caps(void) {
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
    oled_write_ln_P(led.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
#ifdef HK_MASTER_RIGHT
    oled_write_ln_P(g_hk_state.caps_word ? PSTR("CWRD") : PSTR("    "), false);
#else
    oled_write_ln_P(s_caps_word ? PSTR("CWRD") : PSTR("    "), false);
#endif
}

// Boards that want different per-side rendering override oled_task_user with
// a strong (non-weak) definition.  The default here matches the crkbd: render
// the layer/caps view only on the left half.
__attribute__((weak)) oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? OLED_ROTATION_270 : rotation;
}

__attribute__((weak)) bool oled_task_user(void) {
    if (!is_keyboard_left()) return false;
    jv_oled_draw_layer_caps();
    return false;
}

#endif
