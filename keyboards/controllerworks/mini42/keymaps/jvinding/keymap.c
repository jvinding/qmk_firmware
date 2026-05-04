#include QMK_KEYBOARD_H
#include "jvinding.h"
#include "combos.c"
#include "jvinding.c"

// ---------------------------------------------------------------------------
// Keymap — 42 keys written explicitly per layer.
//
// LAYOUT_split_3x6_3 ordering (42 args):
//   Row 0: [0,0]..[0,5]  [4,0]..[4,5]   (left col-0 outer, right col-5 outer)
//   Row 1: [1,0]..[1,5]  [5,0]..[5,5]
//   Row 2: [2,0]..[2,5]  [6,0]..[6,5]
//   Thumbs: [3,0][3,1][3,2]  [7,0][7,1][7,2]
//
// [r,0] on the left and [r+4,5] on the right are the outer-pinky columns.
// No switches are soldered there, so every layer uses JV_NP (KC_NO).
//
// The variadic wrapper forces macro expansion of row macros before the
// preprocessor counts arguments for LAYOUT_split_3x6_3.
// ---------------------------------------------------------------------------

#define LAYOUT_MINI42(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[JV_BASE] = LAYOUT_MINI42(
  JV_NP, JV_BASE_ROW0_L,   JV_BASE_ROW0_R,   JV_NP,
  JV_NP, JV_BASE_ROW1_L,   JV_BASE_ROW1_R,   JV_NP,
  JV_NP, JV_BASE_ROW2_L,   JV_BASE_ROW2_R,   JV_NP,
         JV_BASE_THUMBS_L, JV_BASE_THUMBS_R
),

[JV_EXTRA] = LAYOUT_MINI42(
  JV_NP, JV_EXTRA_ROW0_L,   JV_EXTRA_ROW0_R,   JV_NP,
  JV_NP, JV_EXTRA_ROW1_L,   JV_EXTRA_ROW1_R,   JV_NP,
  JV_NP, JV_EXTRA_ROW2_L,   JV_EXTRA_ROW2_R,   JV_NP,
         JV_EXTRA_THUMBS_L, JV_EXTRA_THUMBS_R
),

[JV_TAP] = LAYOUT_MINI42(
  JV_NP, JV_TAP_ROW0_L,   JV_TAP_ROW0_R,   JV_NP,
  JV_NP, JV_TAP_ROW1_L,   JV_TAP_ROW1_R,   JV_NP,
  JV_NP, JV_TAP_ROW2_L,   JV_TAP_ROW2_R,   JV_NP,
         JV_TAP_THUMBS_L, JV_TAP_THUMBS_R
),

[JV_BUTTON] = LAYOUT_MINI42(
  JV_NP, JV_BUTTON_ROW0_L,   JV_BUTTON_ROW0_R,   JV_NP,
  JV_NP, JV_BUTTON_ROW1_L,   JV_BUTTON_ROW1_R,   JV_NP,
  JV_NP, JV_BUTTON_ROW2_L,   JV_BUTTON_ROW2_R,   JV_NP,
         JV_BUTTON_THUMBS_L, JV_BUTTON_THUMBS_R
),

[JV_NAV] = LAYOUT_MINI42(
  JV_NP, JV_NAV_ROW0_L,   JV_NAV_ROW0_R,   JV_NP,
  JV_NP, JV_NAV_ROW1_L,   JV_NAV_ROW1_R,   JV_NP,
  JV_NP, JV_NAV_ROW2_L,   JV_NAV_ROW2_R,   JV_NP,
         JV_NAV_THUMBS_L, JV_NAV_THUMBS_R
),

[JV_MOUSE] = LAYOUT_MINI42(
  JV_NP, JV_MOUSE_ROW0_L,   JV_MOUSE_ROW0_R,   JV_NP,
  JV_NP, JV_MOUSE_ROW1_L,   JV_MOUSE_ROW1_R,   JV_NP,
  JV_NP, JV_MOUSE_ROW2_L,   JV_MOUSE_ROW2_R,   JV_NP,
         JV_MOUSE_THUMBS_L, JV_MOUSE_THUMBS_R
),

[JV_MEDIA] = LAYOUT_MINI42(
  JV_NP, JV_MEDIA_ROW0_L,   JV_MEDIA_ROW0_R,   JV_NP,
  JV_NP, JV_MEDIA_ROW1_L,   JV_MEDIA_ROW1_R,   JV_NP,
  JV_NP, JV_MEDIA_ROW2_L,   JV_MEDIA_ROW2_R,   JV_NP,
         JV_MEDIA_THUMBS_L, JV_MEDIA_THUMBS_R
),

[JV_NUM] = LAYOUT_MINI42(
  JV_NP, JV_NUM_ROW0_L,   JV_NUM_ROW0_R,   JV_NP,
  JV_NP, JV_NUM_ROW1_L,   JV_NUM_ROW1_R,   JV_NP,
  JV_NP, JV_NUM_ROW2_L,   JV_NUM_ROW2_R,   JV_NP,
         JV_NUM_THUMBS_L, JV_NUM_THUMBS_R
),

[JV_NUMPAD] = LAYOUT_MINI42(
  JV_NP, JV_NUMPAD_ROW0_L,   JV_NUMPAD_ROW0_R,   JV_NP,
  JV_NP, JV_NUMPAD_ROW1_L,   JV_NUMPAD_ROW1_R,   JV_NP,
  JV_NP, JV_NUMPAD_ROW2_L,   JV_NUMPAD_ROW2_R,   JV_NP,
         JV_NUMPAD_THUMBS_L, JV_NUMPAD_THUMBS_R
),

[JV_SYM] = LAYOUT_MINI42(
  JV_NP, JV_SYM_ROW0_L,   JV_SYM_ROW0_R,   JV_NP,
  JV_NP, JV_SYM_ROW1_L,   JV_SYM_ROW1_R,   JV_NP,
  JV_NP, JV_SYM_ROW2_L,   JV_SYM_ROW2_R,   JV_NP,
         JV_SYM_THUMBS_L, JV_SYM_THUMBS_R
),

[JV_FUN] = LAYOUT_MINI42(
  JV_NP, JV_FUN_ROW0_L,   JV_FUN_ROW0_R,   JV_NP,
  JV_NP, JV_FUN_ROW1_L,   JV_FUN_ROW1_R,   JV_NP,
  JV_NP, JV_FUN_ROW2_L,   JV_FUN_ROW2_R,   JV_NP,
         JV_FUN_THUMBS_L, JV_FUN_THUMBS_R
),

};

// Shift + CW_TOGG → KC_CAPS.
//
// process_caps_word runs after process_record_kb, so a key override fires too
// late.  This hook intercepts at the keymap level before caps_word sees it.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == CW_TOGG && record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            uint8_t saved = get_mods();
            clear_mods();
            tap_code(KC_CAPS);
            set_mods(saved);
            return false;
        }
        if (host_keyboard_led_state().caps_lock) {
            tap_code(KC_CAPS);
        }
    }
    return true;
}
