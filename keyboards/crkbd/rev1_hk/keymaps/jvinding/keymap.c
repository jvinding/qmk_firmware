#include QMK_KEYBOARD_H
#include "jvinding.h"
#include "combos.c"
#include "jvinding.c"

// ---------------------------------------------------------------------------
// Keymap — all 42 keys written explicitly per layer.
//
// LAYOUT_split_3x6_3 ordering (42 args):
//   Row 0 (L→R):  [0,0]..[0,5]  [4,5]..[4,0]   (left outer-pinky first, right inner-first)
//   Row 1 (L→R):  [1,0]..[1,5]  [5,5]..[5,0]
//   Row 2 (L→R):  [2,0]..[2,5]  [6,5]..[6,0]
//   Thumbs (6):   [3,3][3,4][3,5]  [7,5][7,4][7,3]  (left outer→inner, right inner→outer)
//
// Outer pinky columns ([r,0] on both sides) carry always-on mouse keys on
// BASE/QWERTY/OSALT and KC_TRNS on every other layer.
// ---------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ── BASE (Colemak-DH) ──────────────────────────────────────────────────────
[JV_BASE] = LAYOUT_split_3x6_3(
  MS_WHLU, KC_Q,              KC_W,           KC_F,           KC_P,           KC_G,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOT,        MS_WHLL,
  MS_BTN1, LCTL_T(KC_A),      LALT_T(KC_R),   LGUI_T(KC_S),   LSFT_T(KC_T),   HYPR_T(KC_D),   HYPR_T(KC_H),   RSFT_T(KC_N),   RGUI_T(KC_E),   RALT_T(KC_I),   RCTL_T(KC_O),   MS_BTN2,
  MS_WHLD, LT(JV_BUTTON,KC_Z),KC_X,           KC_C,           KC_V,           KC_B,           KC_K,           KC_M,           KC_COMM,        KC_DOT,         LT(JV_BUTTON,KC_SLSH), MS_WHLR,
                               LT(JV_FUN,KC_DEL), LT(JV_NUM,KC_BSPC), LT(JV_SYM,KC_ENT),  LT(JV_MOUSE,KC_TAB), LT(JV_NAV,KC_SPC), LT(JV_MEDIA,KC_ESC)
),

// ── QWERTY ──────────────────────────────────────────────────────
[JV_QWERTY] = LAYOUT_split_3x6_3(
  MS_WHLU, KC_Q,              KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           MS_WHLL,
  MS_BTN1, LCTL_T(KC_A),      LALT_T(KC_S),   LGUI_T(KC_D),   LSFT_T(KC_F),   HYPR_T(KC_G),   HYPR_T(KC_H),   RSFT_T(KC_J),   RGUI_T(KC_K),   RALT_T(KC_L),   RCTL_T(KC_QUOT),MS_BTN2,
  MS_WHLD, LT(JV_BUTTON,KC_Z),KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMM,        KC_DOT,         LT(JV_BUTTON,KC_SLSH), MS_WHLR,
                               LT(JV_FUN,KC_DEL), LT(JV_NUM,KC_BSPC), LT(JV_SYM,KC_ENT),  LT(JV_MOUSE,KC_TAB), LT(JV_NAV,KC_SPC), LT(JV_MEDIA,KC_ESC)
),

// ── OSALT (alternate-OS overlay) ────────────────────────────────────────────
[JV_OSALT] = LAYOUT_split_3x6_3(
  MS_WHLU, KC_TRNS,           KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        MS_WHLL,
  MS_BTN1, LGUI_T(KC_A),      KC_TRNS,        LCTL_T(KC_S),   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        RCTL_T(KC_E),   KC_TRNS,        RGUI_T(KC_O),   MS_BTN2,
  MS_WHLD, KC_TRNS,           KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        MS_WHLR,
                               KC_TRNS,        KC_TRNS,        KC_TRNS,                        KC_TRNS,        KC_TRNS,        KC_TRNS
),

// ── BUTTON ─────────────────────────────────────────────────────────────────
[JV_BUTTON] = LAYOUT_split_3x6_3(
  KC_TRNS, MS_WHLL,           MS_WHLD,        MS_WHLU,        MS_WHLR,        JV_UND,         JV_UND,         MS_WHLL,        MS_WHLD,        MS_WHLU,        MS_WHLR,        KC_TRNS,
  KC_TRNS, KC_LGUI,           KC_LALT,        KC_LCTL,        KC_LSFT,        JV_NU,          JV_NU,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_TRNS,
  KC_TRNS, JV_UND,            JV_CUT,         JV_CPY,         JV_PST,         JV_RDO,         JV_RDO,         JV_PST,         JV_CPY,         JV_CUT,         JV_UND,         KC_TRNS,
                               MS_BTN3,        MS_BTN1,        MS_BTN2,                        MS_BTN2,        MS_BTN1,        MS_BTN3
),

// ── NAV (inverted-T) ───────────────────────────────────────────────────────
[JV_NAV] = LAYOUT_split_3x6_3(
  KC_TRNS, KC_PGUP,           KC_HOME,        KC_UP,          KC_END,         KC_INS,         JV_NA,          TD(JV_TD_BASE), TD(JV_TD_QWERTY),TD(JV_TD_OSALT),  TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS, KC_PGDN,           KC_LEFT,        KC_DOWN,        KC_RGHT,        CW_TOGG,        KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS, JV_UND,            JV_CUT,         JV_CPY,         JV_PST,         JV_RDO,         JV_NA,          TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA,          JV_NA,          KC_TRNS,
                               KC_DEL,         KC_BSPC,        KC_ENT,                         JV_NA,          JV_NA,          JV_NA
),

// ── MOUSE ──────────────────────────────────────────────────────────────────
[JV_MOUSE] = LAYOUT_split_3x6_3(
  KC_TRNS, MS_WHLU,           MS_WHLL,        MS_UP,          MS_WHLR,        JV_NU,          JV_NA,          TD(JV_TD_BASE), TD(JV_TD_QWERTY),TD(JV_TD_OSALT),  TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS, MS_WHLD,           MS_LEFT,        MS_DOWN,        MS_RGHT,        JV_NU,          KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS, JV_UND,            JV_CUT,         JV_CPY,         JV_PST,         JV_RDO,         JV_NA,          TD(JV_TD_MOUSE),TD(JV_TD_SYM),  JV_NA,          JV_NA,          KC_TRNS,
                               MS_BTN3,        MS_BTN1,        MS_BTN2,                        JV_NA,          JV_NA,          JV_NA
),

// ── MEDIA ──────────────────────────────────────────────────────────────────
[JV_MEDIA] = LAYOUT_split_3x6_3(
  KC_TRNS, UG_HUEU,           UG_SATU,        KC_VOLU,        UG_VALU,        UG_TOGG,        JV_NA,          TD(JV_TD_BASE), TD(JV_TD_QWERTY),TD(JV_TD_OSALT),  TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS, UG_NEXT,           KC_MPRV,        KC_VOLD,        KC_MNXT,        UG_NEXT,        KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS, JV_NU,             JV_NU,          JV_NU,          JV_NU,          RGB_M_T,        JV_NA,          TD(JV_TD_MEDIA),TD(JV_TD_FUN),  JV_NA,          JV_NA,          KC_TRNS,
                               KC_MUTE,        KC_MPLY,        KC_MSTP,                        JV_NA,          JV_NA,          JV_NA
),

// ── NUM ────────────────────────────────────────────────────────────────────
[JV_NUM] = LAYOUT_split_3x6_3(
  KC_TRNS, TD(JV_TD_BOOT),    TD(JV_TD_OSALT),  TD(JV_TD_QWERTY),TD(JV_TD_BASE), MO(JV_NUMPAD),  KC_LBRC,        KC_7,           KC_8,           KC_9,           KC_RBRC,        KC_TRNS,
  KC_TRNS, KC_LCTL,           KC_LALT,        KC_LGUI,        KC_LSFT,        KC_HYPR,        KC_EQL,         KC_4,           KC_5,           KC_6,           KC_SCLN,        KC_TRNS,
  KC_TRNS, JV_NA,             JV_NU,          TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA,          KC_BSLS,        KC_1,           KC_2,           KC_3,           KC_GRV,         KC_TRNS,
                               JV_NA,          JV_NA,          JV_NA,                          KC_MINS,        KC_0,           KC_DOT
),

// ── NUMPAD ─────────────────────────────────────────────────────────────────
[JV_NUMPAD] = LAYOUT_split_3x6_3(
  KC_TRNS, TD(JV_TD_BOOT),    TD(JV_TD_OSALT),  TD(JV_TD_QWERTY),TD(JV_TD_BASE), JV_NA,           KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_TRNS,
  KC_TRNS, KC_LCTL,           KC_LALT,        KC_LGUI,        KC_LSFT,        KC_HYPR,        KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRNS,
  KC_TRNS, JV_NA,             JV_NU,          TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA,           KC_KP_ENTER,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_EQUAL,    KC_TRNS,
                               JV_NA,          JV_NA,          JV_NA,                          KC_BSPC,        KC_KP_0,        KC_KP_DOT
),

// ── SYM ────────────────────────────────────────────────────────────────────
[JV_SYM] = LAYOUT_split_3x6_3(
  KC_TRNS, TD(JV_TD_BOOT),    TD(JV_TD_OSALT),  TD(JV_TD_QWERTY),TD(JV_TD_BASE), JV_NA,           KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        KC_TRNS,
  KC_TRNS, KC_LCTL,           KC_LALT,        KC_LGUI,        KC_LSFT,        KC_HYPR,        KC_PLUS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_COLN,        KC_TRNS,
  KC_TRNS, JV_NA,             JV_NA,          TD(JV_TD_MOUSE),TD(JV_TD_SYM),  JV_NA,           KC_PIPE,        KC_EXLM,        KC_AT,          KC_HASH,        KC_TILD,        KC_TRNS,
                               JV_NA,          JV_NA,          JV_NA,                          KC_UNDS,        KC_LPRN,        KC_RPRN
),

// ── FUN ────────────────────────────────────────────────────────────────────
[JV_FUN] = LAYOUT_split_3x6_3(
  KC_TRNS, TD(JV_TD_BOOT),    TD(JV_TD_OSALT),  TD(JV_TD_QWERTY),TD(JV_TD_BASE), JV_NA,           KC_PSCR,        KC_F7,          KC_F8,          KC_F9,          KC_F12,         KC_TRNS,
  KC_TRNS, KC_LCTL,           KC_LALT,        KC_LGUI,        KC_LSFT,        KC_HYPR,        KC_SCRL,        KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRNS,
  KC_TRNS, JV_NA,             JV_NA,          TD(JV_TD_MEDIA),TD(JV_TD_FUN),  JV_NA,           KC_PAUS,        KC_F1,          KC_F2,          KC_F3,          KC_F10,         KC_TRNS,
                               JV_NA,          JV_NA,          JV_NA,                          KC_TAB,         KC_SPC,         KC_APP
),

};

// Shift + CW_TOGG → KC_CAPS.
//
// process_record_keymap runs inside process_record_kb (line ~363 of quantum.c),
// which is before process_caps_word (line ~392).  A key override would be too
// late: process_caps_word returns false for CW_TOGG, short-circuiting the chain
// before process_key_override ever fires.
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (keycode == CW_TOGG && record->event.pressed && (get_mods() & MOD_MASK_SHIFT)) {
        uint8_t saved = get_mods();
        clear_mods();
        tap_code(KC_CAPS);
        set_mods(saved);
        return false;
    }
    return true;
}
