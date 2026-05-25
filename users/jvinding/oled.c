#include QMK_KEYBOARD_H
#include "jvinding.h"
#include "caps_word.h"
#include <stdio.h>
#ifdef HK_MASTER_RIGHT
#include "users/holykeebs/pointing.h"
#endif

void caps_word_set_user(bool active) {
#ifdef HK_MASTER_RIGHT
    g_hk_state.caps_word = active;
    g_hk_state.dirty     = true;
#else
    jv_caps_word = active;
#endif
}

#ifdef OLED_ENABLE

const char * const jv_layer_names[] = {
    [JV_BASE]    = "Base",
    [JV_QWERTY]  = "QWER",
#ifdef JV_WINDOWS_FIRST
    [JV_OSALT]   = "Mac",
#else
    [JV_OSALT]   = "Win",
#endif
    [JV_BUTTON]  = "Btn",
    [JV_NAV]     = "Nav",
    [JV_MOUSE]   = "Mouse",
    [JV_MEDIA]   = "Media",
    [JV_NUM]     = "Num",
    [JV_NUMPAD]  = "NPad",
    [JV_SYM]     = "Sym",
    [JV_FUN]     = "Fun",
    [JV_GAME]    = "Game",
    [JV_GAME_FN] = "GmFn",
};

void jv_oled_draw_caps_indicator(void) {
    led_t led = host_keyboard_led_state();
#ifdef HK_MASTER_RIGHT
    bool cw = g_hk_state.caps_word;
#else
    bool cw = jv_caps_word;
#endif
    if (cw) {
        oled_write_ln_P(PSTR("CWRD"), false);
    } else {
        oled_write_ln_P(led.caps_lock ? PSTR("CAPS") : PSTR(""), false);
    }
    oled_write_ln_P(PSTR(""), false);
}

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
    oled_write_ln_P(jv_caps_word ? PSTR("CWRD") : PSTR("    "), false);
#endif
}

// ---------------------------------------------------------------------------
// Rich status display: layer, mods, caps, WPM, uptime.
// Individual helpers are static; call jv_oled_render_status() from outside.
// ---------------------------------------------------------------------------

static void render_layer_line(void) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    oled_write_ln_P(PSTR("LYR"), false);
    if (layer < ARRAY_SIZE(jv_layer_names) && jv_layer_names[layer]) {
        oled_write_ln(jv_layer_names[layer], false);
    } else {
        oled_write_ln_P(PSTR("?"), false);
    }
    oled_write_ln_P(PSTR(""), false);
}

#ifdef SPLIT_MODS_ENABLE
static void render_mods_line(void) {
    uint8_t m = get_mods();
    char buf[5];
    buf[0] = (m & MOD_MASK_SHIFT) ? 'S' : '.';
    buf[1] = (m & MOD_MASK_GUI)   ? 'G' : '.';
    buf[2] = (m & MOD_MASK_ALT)   ? 'A' : '.';
    buf[3] = (m & MOD_MASK_CTRL)  ? 'C' : '.';
    buf[4] = '\0';
    oled_write_ln_P(PSTR("MOD"), false);
    oled_write_ln(buf, false);
    oled_write_ln_P(PSTR(""), false);
}
#endif

#ifdef WPM_ENABLE
static void render_wpm_line(void) {
    char buf[8];
    snprintf(buf, sizeof(buf), "%3u", get_current_wpm());
    oled_write_ln_P(PSTR("WPM"), false);
    oled_write_ln(buf, false);
    oled_write_ln_P(PSTR(""), false);
}
#endif

static void render_uptime_line(void) {
    uint32_t s = timer_read32() / 1000;
    uint16_t h = (uint16_t)(s / 3600);
    uint8_t  m = (uint8_t)((s % 3600) / 60);
    char buf[8];
    snprintf(buf, sizeof(buf), "%uh%02um", h, m);
    oled_write_ln_P(PSTR("UP"), false);
    oled_write_ln(buf, false);
    oled_write_ln_P(PSTR(""), false);
}

void jv_oled_render_status(void) {
    render_layer_line();
#ifdef SPLIT_MODS_ENABLE
    render_mods_line();
#endif
    jv_oled_draw_caps_indicator();
#ifdef WPM_ENABLE
    render_wpm_line();
#endif
    render_uptime_line();
}

// Boards that want different per-side rendering override oled_task_user with
// a strong (non-weak) definition.  The default here matches the crkbd: render
// the status view only on the left half.
__attribute__((weak)) oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? OLED_ROTATION_270 : rotation;
}

__attribute__((weak)) bool oled_task_user(void) {
    if (!is_keyboard_left()) return false;
    jv_oled_render_status();
    return false;
}

#endif
