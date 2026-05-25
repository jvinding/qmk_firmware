#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "rgb_matrix.h"
#include "jvinding.h"

#ifdef RGB_MATRIX_ENABLE

#if defined(RGB_MATRIX_SPLIT)
extern const uint8_t k_rgb_matrix_split[2];
#endif

__attribute__((weak)) void jv_rgb_matrix_indicators_keyboard(uint8_t active_layer, uint8_t led_min, uint8_t led_max) {}

// ---------------------------------------------------------------------------
// Catppuccin Latte palette — V normalised to 255 (global brightness via JV_RGB_BRIGHTNESS)
// ---------------------------------------------------------------------------

#define JV_C_ROSEWATER ((HSV){  8, 116, 255})
#define JV_C_PINK      ((HSV){224, 126, 255})
#define JV_C_MAUVE     ((HSV){188, 194, 255})
#define JV_C_RED       ((HSV){246, 237, 255})
#define JV_C_PEACH     ((HSV){ 16, 244, 255})
#define JV_C_YELLOW    ((HSV){ 25, 222, 255})
#define JV_C_GREEN     ((HSV){ 77, 186, 255})
#define JV_C_TEAL      ((HSV){130, 217, 255})
#define JV_C_SKY       ((HSV){140, 250, 255})
#define JV_C_SAPPHIRE  ((HSV){134, 210, 255})
#define JV_C_BLUE      ((HSV){156, 224, 255})
#define JV_C_LAVENDER  ((HSV){164, 140, 255})

// ---------------------------------------------------------------------------
// Per-layer HSV
// ---------------------------------------------------------------------------

HSV jv_hsv_for_layer_id(uint8_t id) {
    switch (id) {
        case JV_BASE:    return JV_C_LAVENDER;   // pastel blue-purple, easy on eyes
        case JV_QWERTY:   return JV_C_PINK;
        case JV_OSALT:       return JV_C_ROSEWATER;
        case JV_BUTTON:  return JV_C_SAPPHIRE;
        case JV_NAV:     return JV_C_SKY;
        case JV_MOUSE:   return JV_C_YELLOW;
        case JV_MEDIA:   return JV_C_GREEN;
        case JV_NUM:     return JV_C_BLUE;
        case JV_NUMPAD:  return JV_C_MAUVE;      // same hue as GAME; they never coexist
        case JV_SYM:     return JV_C_TEAL;
        case JV_FUN:     return JV_C_PEACH;
        case JV_GAME:    return JV_C_MAUVE;      // soft purple, easy on eyes
        case JV_GAME_FN: return JV_C_LAVENDER;   // same hue as BASE; they never coexist
        default:         return JV_C_LAVENDER;
    }
}

// TD index → target layer (0xFF = no layer target)
static const uint8_t jv_td_target_layer[12] = {
    0xFF,        // JV_TD_BOOT
    JV_BASE, JV_QWERTY, JV_OSALT, JV_BUTTON,
    JV_NAV, JV_MOUSE, JV_MEDIA, JV_NUM, JV_NUMPAD, JV_SYM, JV_FUN
};

// ---------------------------------------------------------------------------
// Keycode analysis helpers
// ---------------------------------------------------------------------------

static int8_t jv_layer_key_target_id(uint16_t kc) {
    if (IS_QK_TO(kc))                   return (int8_t)QK_TO_GET_LAYER(kc);
    if (IS_QK_MOMENTARY(kc))            return (int8_t)QK_MOMENTARY_GET_LAYER(kc);
    if (IS_QK_DEF_LAYER(kc))            return (int8_t)QK_DEF_LAYER_GET_LAYER(kc);
    if (IS_QK_TOGGLE_LAYER(kc))         return (int8_t)QK_TOGGLE_LAYER_GET_LAYER(kc);
    if (IS_QK_ONE_SHOT_LAYER(kc))       return (int8_t)QK_ONE_SHOT_LAYER_GET_LAYER(kc);
    if (IS_QK_LAYER_TAP(kc))            return (int8_t)QK_LAYER_TAP_GET_LAYER(kc);
    if (IS_QK_LAYER_TAP_TOGGLE(kc))     return (int8_t)QK_LAYER_TAP_TOGGLE_GET_LAYER(kc);
    if (IS_QK_PERSISTENT_DEF_LAYER(kc)) return (int8_t)QK_PERSISTENT_DEF_LAYER_GET_LAYER(kc);
    if (IS_QK_LAYER_MOD(kc))            return (int8_t)QK_LAYER_MOD_GET_LAYER(kc);
    return -1;
}

static uint16_t jv_semantic_inner_keycode(uint16_t kc) {
    if (IS_QK_MOD_TAP(kc))   return QK_MOD_TAP_GET_TAP_KEYCODE(kc);
    if (IS_QK_MODS(kc))      return QK_MODS_GET_BASIC_KEYCODE(kc);
    if (IS_QK_LAYER_TAP(kc)) return QK_LAYER_TAP_GET_TAP_KEYCODE(kc);
    return kc;
}

static bool jv_is_cursor_move(uint16_t kc) {
    return kc >= QK_MOUSE_CURSOR_UP && kc <= QK_MOUSE_CURSOR_RIGHT;
}

static bool jv_is_mouse_button_or_scroll(uint16_t kc) {
    return (kc >= QK_MOUSE_BUTTON_1 && kc <= QK_MOUSE_BUTTON_8) ||
           (kc >= QK_MOUSE_WHEEL_UP && kc <= QK_MOUSE_WHEEL_RIGHT);
}

// ---------------------------------------------------------------------------
// Per-key color picker
//   global_layer  = get_highest_layer(layer_state | default_layer_state)
//   per_key_layer = layer_switch_get_layer(keypos)   — first non-TRNS layer
//   kc            = keymap_key_to_keycode(per_key_layer, keypos)
// ---------------------------------------------------------------------------

static HSV jv_hsv_for_key_in_context(uint8_t global_layer, uint8_t per_key_layer, uint16_t kc) {
    // Layer-switching keys → target layer color
    int8_t t = jv_layer_key_target_id(kc);
    if (t >= 0) {
        return jv_hsv_for_layer_id((uint8_t)t);
    }

    // Tap-dance → target layer color (if it has one)
    if (IS_QK_TAP_DANCE(kc)) {
        uint8_t idx = (uint8_t)(kc - QK_TAP_DANCE);
        if (idx < sizeof(jv_td_target_layer) / sizeof(jv_td_target_layer[0])) {
            uint8_t tl = jv_td_target_layer[idx];
            if (tl != 0xFF) return jv_hsv_for_layer_id(tl);
        }
    }

    const uint16_t inner = jv_semantic_inner_keycode(kc);

    // Directional accents → red
    if (global_layer == JV_NAV) {
        if (inner == KC_UP || inner == KC_DOWN || inner == KC_LEFT || inner == KC_RGHT)
            return JV_C_RED;
    }
    if (global_layer == JV_MOUSE) {
        if (jv_is_cursor_move(kc) || jv_is_cursor_move(inner))
            return JV_C_RED;
    }
    if (global_layer == JV_MEDIA) {
        if (inner == KC_VOLU || inner == KC_VOLD || inner == KC_MNXT || inner == KC_MPRV)
            return JV_C_RED;
    }

    // Mouse buttons and scroll → mouse layer color (yellow), regardless of active layer
    if (jv_is_mouse_button_or_scroll(kc) || jv_is_mouse_button_or_scroll(inner))
        return jv_hsv_for_layer_id(JV_MOUSE);

    // Gaming layer accents
    if (global_layer == JV_GAME) {
        if (inner == KC_W || inner == KC_A || inner == KC_S || inner == KC_D)
            return JV_C_RED;
    }
    if (global_layer == JV_GAME_FN) {
        if (inner == KC_UP || inner == KC_DOWN || inner == KC_LEFT || inner == KC_RGHT)
            return JV_C_RED;
        if (inner == KC_PGUP || inner == KC_PGDN || inner == KC_HOME || inner == KC_END || inner == KC_INS)
            return jv_hsv_for_layer_id(JV_NAV);
        if ((inner >= KC_NUM_LOCK && inner <= KC_KP_DOT) || inner == KC_KP_EQUAL)
            return jv_hsv_for_layer_id(JV_NUMPAD);
        if (inner >= KC_F1 && inner <= KC_F12)
            return jv_hsv_for_layer_id(JV_FUN);
    }

    return jv_hsv_for_layer_id(per_key_layer);
}

// ---------------------------------------------------------------------------
// Split helpers — each half only touches its own LED indices
// ---------------------------------------------------------------------------

#if defined(RGB_MATRIX_SPLIT)
static bool jv_led_on_this_hand(uint8_t i) {
    return is_keyboard_left() ? (i < k_rgb_matrix_split[0]) : (i >= k_rgb_matrix_split[0]);
}
#else
static bool jv_led_on_this_hand(uint8_t i) { (void)i; return true; }
#endif

#if defined(SPLIT_KEYBOARD)
static bool jv_key_row_on_this_hand(uint8_t row) {
    return is_keyboard_left() ? (row < MATRIX_ROWS / 2) : (row >= MATRIX_ROWS / 2);
}
#else
static bool jv_key_row_on_this_hand(uint8_t row) { (void)row; return true; }
#endif

// ---------------------------------------------------------------------------
// LED cache — rebuilt only when layer state changes
// ---------------------------------------------------------------------------

static rgb_t    jv_led_cache[RGB_MATRIX_LED_COUNT];
static bool     jv_cache_valid;
static uint32_t jv_cache_ls, jv_cache_dls;

static void jv_rebuild_cache(void) {
    const uint8_t al   = get_highest_layer(layer_state | default_layer_state);
    const HSV     base = jv_hsv_for_layer_id(al);
    const RGB     brgb = hsv_to_rgb(base);

    // Default all local LEDs to the active layer color
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        if (jv_led_on_this_hand(i)) jv_led_cache[i] = brgb;
    }

    // Per-key override
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        if (!jv_key_row_on_this_hand(r)) continue;
        for (uint8_t c = 0; c < MATRIX_COLS; c++) {
            const uint8_t li = g_led_config.matrix_co[r][c];
            if (li == NO_LED || li >= RGB_MATRIX_LED_COUNT) continue;
            if (!jv_led_on_this_hand(li)) continue;

            keypos_t       key = {.row = r, .col = c};
            const uint8_t  sl  = layer_switch_get_layer(key);
            const uint16_t kc  = keymap_key_to_keycode(sl, key);
            if (kc == KC_NO) {
                jv_led_cache[li] = (rgb_t){0, 0, 0};
                continue;
            }
            jv_led_cache[li] = hsv_to_rgb(jv_hsv_for_key_in_context(al, sl, kc));
        }
    }

    // Underglow follows the active layer color
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        if (jv_led_on_this_hand(i) && HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW))
            jv_led_cache[i] = brgb;
    }

    jv_cache_ls    = layer_state;
    jv_cache_dls   = default_layer_state;
    jv_cache_valid = true;
}

// ---------------------------------------------------------------------------
// Hooks
// ---------------------------------------------------------------------------

// No-op: suppress the animation engine from asserting it owns the frame.
bool rgb_matrix_indicators_user(void) {
    return true;
}

// Strong _kb symbol so LTO (disabled for this keyboard) cannot fold it away.
// Invalidates the cache on layer change, rebuilds, then pushes the full local
// half from cache rather than only the current led_min..led_max chunk.
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    (void)led_min;
    (void)led_max;

    if (layer_state != jv_cache_ls || default_layer_state != jv_cache_dls)
        jv_cache_valid = false;
    if (!jv_cache_valid) jv_rebuild_cache();

#if defined(RGB_MATRIX_SPLIT)
    const uint8_t h0 = is_keyboard_left() ? 0 : k_rgb_matrix_split[0];
    const uint8_t h1 = is_keyboard_left() ? k_rgb_matrix_split[0] : (uint8_t)RGB_MATRIX_LED_COUNT;
#else
    const uint8_t h0 = 0;
    const uint8_t h1 = (uint8_t)RGB_MATRIX_LED_COUNT;
#endif

    // Per-channel correction: output = (cache * BRIGHTNESS * MULT) >> 16.
    // BRIGHTNESS: 64 = full brightness, 32 = half, 16 = quarter. Values above 64 clip.
    // CORRECTION: 1024 = no correction. Split keyboards support independent left/right values.
    // Override in the board's config.h, e.g.:
    //   #define JV_RGB_BRIGHTNESS       48u
    //   #define JV_RGB_CORRECT_LEFT_R   80u
    //   #define JV_RGB_CORRECT_LEFT_G   72u
    //   #define JV_RGB_CORRECT_LEFT_B  640u
    //   #define JV_RGB_CORRECT_RIGHT_R  80u
    //   #define JV_RGB_CORRECT_RIGHT_G  72u
    //   #define JV_RGB_CORRECT_RIGHT_B 640u
#ifndef JV_RGB_BRIGHTNESS
#define JV_RGB_BRIGHTNESS 64u
#endif
#ifndef JV_RGB_CORRECT_LEFT_R
#define JV_RGB_CORRECT_LEFT_R 1024u
#endif
#ifndef JV_RGB_CORRECT_LEFT_G
#define JV_RGB_CORRECT_LEFT_G 1024u
#endif
#ifndef JV_RGB_CORRECT_LEFT_B
#define JV_RGB_CORRECT_LEFT_B 1024u
#endif
#ifndef JV_RGB_CORRECT_RIGHT_R
#define JV_RGB_CORRECT_RIGHT_R 1024u
#endif
#ifndef JV_RGB_CORRECT_RIGHT_G
#define JV_RGB_CORRECT_RIGHT_G 1024u
#endif
#ifndef JV_RGB_CORRECT_RIGHT_B
#define JV_RGB_CORRECT_RIGHT_B 1024u
#endif
    const uint32_t cr = is_keyboard_left() ? JV_RGB_CORRECT_LEFT_R : JV_RGB_CORRECT_RIGHT_R;
    const uint32_t cg = is_keyboard_left() ? JV_RGB_CORRECT_LEFT_G : JV_RGB_CORRECT_RIGHT_G;
    const uint32_t cb = is_keyboard_left() ? JV_RGB_CORRECT_LEFT_B : JV_RGB_CORRECT_RIGHT_B;
    for (uint8_t i = h0; i < h1; i++) {
        rgb_matrix_set_color(i,
            (uint8_t)(((uint32_t)jv_led_cache[i].r * JV_RGB_BRIGHTNESS * cr) >> 16),
            (uint8_t)(((uint32_t)jv_led_cache[i].g * JV_RGB_BRIGHTNESS * cg) >> 16),
            (uint8_t)(((uint32_t)jv_led_cache[i].b * JV_RGB_BRIGHTNESS * cb) >> 16));
    }

    jv_rgb_matrix_indicators_keyboard(
        get_highest_layer(layer_state | default_layer_state), h0, h1);
    return false;
}

#endif
