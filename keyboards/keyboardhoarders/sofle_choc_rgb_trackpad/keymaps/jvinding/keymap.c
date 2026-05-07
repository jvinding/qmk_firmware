#include QMK_KEYBOARD_H
#include "jvinding.h"
#include "combos.c"
#include "jvinding.c"

// ---------------------------------------------------------------------------
// Keymap — all 60 keys written explicitly per layer.
//
// LAYOUT ordering (60 args):
//   Row 0:   [0,0]..[0,5]  [5,5]..[5,0]               — 12 keys (number row)
//   Row 1:   [1,0]..[1,5]  [6,5]..[6,0]               — 12 keys (top alpha = crkbd row 0)
//   Row 2:   [2,0]..[2,5]  [7,5]..[7,0]               — 12 keys (home row = crkbd row 1)
//   Row 3:   [3,0]..[3,5] [4,5][9,5] [8,5]..[8,0]     — 14 keys (bottom alpha + encoder press)
//   Thumbs:  [4,0]..[4,4]  [9,4]..[9,0]               — 10 keys
//
// Normal layers (BASE–FUN):
//   Row 0 = KC_NO. Rows 1-3 carry the crkbd inner-block keys verbatim.
//   Inner 3 thumbs each side = crkbd thumb assignments.
//   Outer thumbs [4,0][4,1][9,1] = KC_NO; [9,0] = TG(JV_GAME) on every normal layer.
//   Encoder press: [4,5] = left click, [9,5] = right click.
// ---------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ── BASE (Colemak-DH) ──────────────────────────────────────────────────────
[JV_BASE] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  MS_WHLU, KC_Q,                KC_W,           KC_F,            KC_P,            KC_G,            KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOT,        MS_WHLL,
  MS_BTN1, LCTL_T(KC_A),        LALT_T(KC_R),   LGUI_T(KC_S),    LSFT_T(KC_T),    HYPR_T(KC_D),    HYPR_T(KC_H),   RSFT_T(KC_N),   RGUI_T(KC_E),   RALT_T(KC_I),   RCTL_T(KC_O),   MS_BTN2,
  MS_WHLD, LT(JV_BUTTON,KC_Z),  KC_X,           KC_C,            KC_V,            KC_B,            KC_MPLY, MS_BTN1,  KC_K,          KC_M,           KC_COMM,        KC_DOT,         LT(JV_BUTTON,KC_SLSH), MS_WHLR,
  KC_NO,   KC_NO,               LT(JV_FUN,KC_DEL),  LT(JV_NUM,KC_BSPC), LT(JV_SYM,KC_ENT),   LT(JV_MOUSE,KC_TAB), LT(JV_NAV,KC_SPC), LT(JV_MEDIA,KC_ESC), KC_NO, TG(JV_GAME)
),

// ── EXTRA (QWERTY-DH) ──────────────────────────────────────────────────────
[JV_EXTRA] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  MS_WHLU, KC_Q,                KC_W,           KC_E,            KC_R,            KC_T,            KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           MS_WHLL,
  MS_BTN1, LCTL_T(KC_A),        LALT_T(KC_S),   LGUI_T(KC_D),    LSFT_T(KC_F),    HYPR_T(KC_G),    HYPR_T(KC_H),   RSFT_T(KC_J),   RGUI_T(KC_K),   RALT_T(KC_L),   RCTL_T(KC_QUOT),MS_BTN2,
  MS_WHLD, LT(JV_BUTTON,KC_Z),  KC_X,           KC_C,            KC_V,            KC_B,            KC_TRNS, KC_TRNS,  KC_N,          KC_M,           KC_COMM,        KC_DOT,         LT(JV_BUTTON,KC_SLSH), MS_WHLR,
  KC_NO,   KC_NO,               LT(JV_FUN,KC_DEL),  LT(JV_NUM,KC_BSPC), LT(JV_SYM,KC_ENT),   LT(JV_MOUSE,KC_TAB), LT(JV_NAV,KC_SPC), LT(JV_MEDIA,KC_ESC), KC_NO, TG(JV_GAME)
),

// ── TAP (reduced home-row mods) ────────────────────────────────────────────
[JV_TAP] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  MS_WHLU, KC_TRNS,             KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        MS_WHLL,
  MS_BTN1, LGUI_T(KC_A),        KC_TRNS,        LCTL_T(KC_S),    KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,        RCTL_T(KC_E),   KC_TRNS,        RGUI_T(KC_O),   MS_BTN2,
  MS_WHLD, KC_TRNS,             KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        MS_WHLR,
  KC_NO,   KC_NO,               KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_NO,          TG(JV_GAME)
),

// ── BUTTON ─────────────────────────────────────────────────────────────────
[JV_BUTTON] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS, MS_WHLL,             MS_WHLD,        MS_WHLU,         MS_WHLR,         JV_UND,          JV_UND,         MS_WHLL,        MS_WHLD,        MS_WHLU,        MS_WHLR,        KC_TRNS,
  KC_TRNS, KC_LGUI,             KC_LALT,        KC_LCTL,         KC_LSFT,         JV_NU,           JV_NU,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_TRNS,
  KC_TRNS, JV_UND,              JV_CUT,         JV_CPY,          JV_PST,          JV_RDO,          KC_TRNS, MS_BTN2,  JV_RDO,        JV_PST,         JV_CPY,         JV_CUT,         JV_UND,         KC_TRNS,
  KC_NO,   KC_NO,               MS_BTN3,        MS_BTN1,         MS_BTN2,         MS_BTN2,         MS_BTN1,        MS_BTN3,        KC_NO,          TG(JV_GAME)
),

// ── NAV (inverted-T) ───────────────────────────────────────────────────────
[JV_NAV] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS, KC_PGUP,             KC_HOME,        KC_UP,           KC_END,          KC_INS,          JV_NA,          TD(JV_TD_BASE), TD(JV_TD_EXTRA),TD(JV_TD_TAP),  TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS, KC_PGDN,             KC_LEFT,        KC_DOWN,         KC_RGHT,         CW_TOGG,         KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS, JV_UND,              JV_CUT,         JV_CPY,          JV_PST,          JV_RDO,          KC_TRNS, KC_TRNS,  JV_NA,         TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA,          JV_NA,          KC_TRNS,
  KC_NO,   KC_NO,               KC_DEL,         KC_BSPC,         KC_ENT,          JV_NA,           JV_NA,          JV_NA,          KC_NO,          TG(JV_GAME)
),

// ── MOUSE ──────────────────────────────────────────────────────────────────
[JV_MOUSE] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS, MS_WHLU,             MS_WHLL,        MS_UP,           MS_WHLR,         JV_NU,           JV_NA,          TD(JV_TD_BASE), TD(JV_TD_EXTRA),TD(JV_TD_TAP),  TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS, MS_WHLD,             MS_LEFT,        MS_DOWN,         MS_RGHT,         JV_NU,           KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS, JV_UND,              JV_CUT,         JV_CPY,          JV_PST,          JV_RDO,          KC_TRNS, KC_TRNS,  JV_NA,         TD(JV_TD_MOUSE),TD(JV_TD_SYM),  JV_NA,          JV_NA,          KC_TRNS,
  KC_NO,   KC_NO,               MS_BTN3,        MS_BTN1,         MS_BTN2,         JV_NA,           JV_NA,          JV_NA,          KC_NO,          TG(JV_GAME)
),

// ── MEDIA ──────────────────────────────────────────────────────────────────
[JV_MEDIA] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS, UG_HUEU,             UG_SATU,        KC_VOLU,         UG_VALU,         UG_TOGG,         JV_NA,          TD(JV_TD_BASE), TD(JV_TD_EXTRA),TD(JV_TD_TAP),  TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS, UG_NEXT,             KC_MPRV,        KC_VOLD,         KC_MNXT,         UG_NEXT,         KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS, JV_NU,               JV_NU,          JV_NU,           JV_NU,           RGB_M_T,         KC_TRNS, KC_TRNS,  JV_NA,         TD(JV_TD_MEDIA),TD(JV_TD_FUN),  JV_NA,          JV_NA,          KC_TRNS,
  KC_NO,   KC_NO,               KC_MUTE,        KC_MPLY,         KC_MSTP,         JV_NA,           JV_NA,          JV_NA,          KC_NO,          TG(JV_GAME)
),

// ── NUM ────────────────────────────────────────────────────────────────────
[JV_NUM] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS, TD(JV_TD_BOOT),      TD(JV_TD_TAP),  TD(JV_TD_EXTRA), TD(JV_TD_BASE),  MO(JV_NUMPAD),   KC_LBRC,        KC_7,           KC_8,           KC_9,           KC_RBRC,        KC_TRNS,
  KC_TRNS, KC_LCTL,             KC_LALT,        KC_LGUI,         KC_LSFT,         KC_HYPR,         KC_EQL,         KC_4,           KC_5,           KC_6,           KC_SCLN,        KC_TRNS,
  KC_TRNS, JV_NA,               JV_NU,          TD(JV_TD_NAV),   TD(JV_TD_NUM),   JV_NA,           KC_TRNS, KC_TRNS,  KC_BSLS,       KC_1,           KC_2,           KC_3,           KC_GRV,         KC_TRNS,
  KC_NO,   KC_NO,               JV_NA,          JV_NA,           JV_NA,           KC_MINS,         KC_0,           KC_DOT,         KC_NO,          TG(JV_GAME)
),

// ── NUMPAD ─────────────────────────────────────────────────────────────────
[JV_NUMPAD] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS, TD(JV_TD_BOOT),      TD(JV_TD_TAP),  TD(JV_TD_EXTRA), TD(JV_TD_BASE),  JV_NA,           KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_TRNS,
  KC_TRNS, KC_LCTL,             KC_LALT,        KC_LGUI,         KC_LSFT,         KC_HYPR,         KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRNS,
  KC_TRNS, JV_NA,               JV_NU,          TD(JV_TD_NAV),   TD(JV_TD_NUM),   JV_NA,           KC_TRNS, KC_TRNS,  KC_KP_ENTER,   KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_EQUAL,    KC_TRNS,
  KC_NO,   KC_NO,               JV_NA,          JV_NA,           JV_NA,           KC_BSPC,         KC_KP_0,        KC_KP_DOT,      KC_NO,          TG(JV_GAME)
),

// ── SYM ────────────────────────────────────────────────────────────────────
[JV_SYM] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS, TD(JV_TD_BOOT),      TD(JV_TD_TAP),  TD(JV_TD_EXTRA), TD(JV_TD_BASE),  JV_NA,           KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        KC_TRNS,
  KC_TRNS, KC_LCTL,             KC_LALT,        KC_LGUI,         KC_LSFT,         KC_HYPR,         KC_PLUS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_COLN,        KC_TRNS,
  KC_TRNS, JV_NA,               JV_NA,          TD(JV_TD_MOUSE), TD(JV_TD_SYM),   JV_NA,           KC_TRNS, KC_TRNS,  KC_PIPE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_TILD,        KC_TRNS,
  KC_NO,   KC_NO,               JV_NA,          JV_NA,           JV_NA,           KC_UNDS,         KC_LPRN,        KC_RPRN,        KC_NO,          TG(JV_GAME)
),

// ── FUN ────────────────────────────────────────────────────────────────────
[JV_FUN] = LAYOUT(
  KC_NO,   KC_NO,               KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS, TD(JV_TD_BOOT),      TD(JV_TD_TAP),  TD(JV_TD_EXTRA), TD(JV_TD_BASE),  JV_NA,           KC_PSCR,        KC_F7,          KC_F8,          KC_F9,          KC_F12,         KC_TRNS,
  KC_TRNS, KC_LCTL,             KC_LALT,        KC_LGUI,         KC_LSFT,         KC_HYPR,         KC_SCRL,        KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRNS,
  KC_TRNS, JV_NA,               JV_NA,          TD(JV_TD_MEDIA), TD(JV_TD_FUN),   JV_NA,           KC_TRNS, KC_TRNS,  KC_PAUS,       KC_F1,          KC_F2,          KC_F3,          KC_F10,         KC_TRNS,
  KC_NO,   KC_NO,               JV_NA,          JV_NA,           JV_NA,           KC_TAB,          KC_SPC,         KC_APP,         KC_NO,          TG(JV_GAME)
),

// ── GAME (QWERTY, no home-row mods) ────────────────────────────────────────
[JV_GAME] = LAYOUT(
  KC_ESC,  KC_1,                KC_2,           KC_3,            KC_4,            KC_5,            KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
  KC_TAB,  KC_Q,                KC_W,           KC_E,            KC_R,            KC_T,            KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
  KC_LSFT, KC_A,                KC_S,           KC_D,            KC_F,            KC_G,            KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
  KC_LCTL, KC_Z,                KC_X,           KC_C,            KC_V,            KC_B,            KC_F12, MS_BTN1,  KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_KP_PLUS,
  MO(JV_GAME_FN), KC_LSFT,      KC_SPC,         KC_LCTL,         KC_LALT,         MO(JV_GAME_FN),  KC_ENT,         KC_LALT,        KC_RSFT,        TG(JV_GAME)
),

// ── GAME_FN (function/numpad/navigation overlay) ───────────────────────────
[JV_GAME_FN] = LAYOUT(
  KC_GRV,  KC_KP_1,             KC_KP_2,        KC_KP_3,         KC_KP_4,         KC_KP_5,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_EQL,
  KC_KP_MINUS, KC_PGUP,         KC_HOME,        KC_UP,           KC_END,          KC_PSCR,         KC_NUM_LOCK,    KC_KP_DOT,      KC_KP_ASTERISK, KC_KP_SLASH,    KC_KP_EQUAL,    KC_KP_ENTER,
  KC_BSPC, KC_PGDN,             KC_LEFT,        KC_DOWN,         KC_RGHT,         KC_INS,          KC_DEL,         KC_LCTL,        KC_LSFT,        KC_LALT,        KC_F11,         KC_F12,
  KC_KP_PLUS, KC_KP_6,          KC_KP_7,        KC_KP_8,         KC_KP_9,         KC_KP_0,         KC_TRNS, KC_TRNS,  KC_F6,         KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,
  KC_TRNS, KC_TRNS,             KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
),

};

// ---------------------------------------------------------------------------
// Encoder map: left = index 0 (master), right = index 1 (slave).
// Rotation uses encoder_map; press is a normal matrix keycode ([4,5] and [9,5]).
// ---------------------------------------------------------------------------

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [JV_BASE]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU) },
    [JV_EXTRA]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_TAP]     = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_BUTTON]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(MS_WHLL, MS_WHLR) },
    [JV_NAV]     = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_MOUSE]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_MEDIA]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_NUM]     = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_NUMPAD]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_SYM]     = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_FUN]     = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_GAME]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [JV_GAME_FN] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif
