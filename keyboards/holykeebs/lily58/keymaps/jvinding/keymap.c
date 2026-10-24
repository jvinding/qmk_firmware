#include QMK_KEYBOARD_H
#include "jvinding.h"
#include "combos.c"
#define KEYMAP_OVERRIDE_POST_INIT
#include "jvinding.c"

// ---------------------------------------------------------------------------
// Keymap — all 58 keys written explicitly per layer.
//
// LAYOUT ordering (58 args):
//   Row 0:   [0,0]..[0,5]  [5,5]..[5,0]               — 12 keys (number row)
//   Row 1:   [1,0]..[1,5]  [6,5]..[6,0]               — 12 keys (top alpha)
//   Row 2:   [2,0]..[2,5]  [7,5]..[7,0]               — 12 keys (home row)
//   Row 3:   [3,0]..[3,5] [4,5][9,5] [8,5]..[8,0]     — 14 keys (bottom alpha + inner pair)
//   Thumbs:  [4,1]..[4,4]  [9,4]..[9,1]               — 8 keys
//
// Same layout as the sofle_choc_rgb_trackpad keymap, minus the outermost
// thumb on each side.  Row 0 = KC_NO on normal layers.
//   [4,5] = sofle left-encoder press, [9,5] = sofle right-encoder press, which
//   is TG(JV_GAME) here on every layer.  There are no encoders or pointing
//   devices on this board.
// ---------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ── BASE (Colemak-DH) ───────────────────────────────────────────
[JV_BASE] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  MS_WHLU,        KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOT,        MS_WHLL,
  MS_BTN1,        LGUI_T(KC_A),   LALT_T(KC_R),   LCTL_T(KC_S),   LSFT_T(KC_T),   HYPR_T(KC_D),   HYPR_T(KC_H),   RSFT_T(KC_N),   RCTL_T(KC_E),   RALT_T(KC_I),   RGUI_T(KC_O),   MS_BTN2,
  MS_WHLD,        LT(JV_BUTTON,KC_Z),KC_X,           KC_C,           KC_V,           KC_B,           KC_MPLY,        TG(JV_GAME),    KC_K,           KC_M,           KC_COMM,        KC_DOT,         LT(JV_BUTTON,KC_SLSH),MS_WHLR,
  KC_NO,          LT(JV_FUN,KC_DEL),LT(JV_NUM,KC_BSPC),LT(JV_SYM,KC_ENT),LT(JV_MOUSE,KC_TAB),LT(JV_NAV,KC_SPC),LT(JV_MEDIA,KC_ESC),KC_NO
),

// ── QWERTY ──────────────────────────────────────────────────────
[JV_QWERTY] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  MS_WHLU,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           MS_WHLL,
  MS_BTN1,        LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   HYPR_T(KC_G),   HYPR_T(KC_H),   RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_QUOT),MS_BTN2,
  MS_WHLD,        LT(JV_BUTTON,KC_Z),KC_X,           KC_C,           KC_V,           KC_B,           KC_TRNS,        TG(JV_GAME),    KC_N,           KC_M,           KC_COMM,        KC_DOT,         LT(JV_BUTTON,KC_SLSH),MS_WHLR,
  KC_NO,          LT(JV_FUN,KC_DEL),LT(JV_NUM,KC_BSPC),LT(JV_SYM,KC_ENT),LT(JV_MOUSE,KC_TAB),LT(JV_NAV,KC_SPC),LT(JV_MEDIA,KC_ESC),KC_NO
),

// ── MAC (overlay: swap LCTL↔LGUI back to Mac-style on Colemak-DH positions) 
[JV_OSALT] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  MS_WHLU,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        MS_WHLL,
  MS_BTN1,        LCTL_T(KC_A),   KC_TRNS,        LGUI_T(KC_S),   KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        RGUI_T(KC_E),   KC_TRNS,        RCTL_T(KC_O),   MS_BTN2,
  MS_WHLD,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        TG(JV_GAME),    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        MS_WHLR,
  KC_NO,          KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO
),

// ── BUTTON ──────────────────────────────────────────────────────
[JV_BUTTON] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS,        MS_WHLL,        MS_WHLD,        MS_WHLU,        MS_WHLR,        JV_UND,         JV_UND,         MS_WHLL,        MS_WHLD,        MS_WHLU,        MS_WHLR,        KC_TRNS,
  KC_TRNS,        KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        JV_NU,          JV_NU,          KC_LSFT,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_TRNS,
  KC_TRNS,        JV_UND,         JV_CUT,         JV_CPY,         JV_PST,         JV_RDO,         KC_TRNS,        TG(JV_GAME),    JV_RDO,         JV_PST,         JV_CPY,         JV_CUT,         JV_UND,         KC_TRNS,
  KC_NO,          MS_BTN3,        MS_BTN1,        MS_BTN2,        MS_BTN2,        MS_BTN1,        MS_BTN3,        KC_NO
),

// ── NAV (inverted-T) ────────────────────────────────────────────
[JV_NAV] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS,        KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_INS,         JV_NA,          TD(JV_TD_BASE), TD(JV_TD_QWERTY),TD(JV_TD_OSALT),TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS,        KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RGHT,        CW_TOGG,        KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS,        JV_UND,         JV_CUT,         JV_CPY,         JV_PST,         JV_RDO,         KC_TRNS,        TG(JV_GAME),    JV_NA,          TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA,          JV_NA,          KC_TRNS,
  KC_NO,          KC_DEL,         KC_BSPC,        KC_ENT,         JV_NA,          JV_NA,          JV_NA,          KC_NO
),

// ── MOUSE ───────────────────────────────────────────────────────
[JV_MOUSE] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS,        MS_WHLU,        MS_WHLL,        MS_UP,          MS_WHLR,        JV_NU,          JV_NA,          TD(JV_TD_BASE), TD(JV_TD_QWERTY),TD(JV_TD_OSALT),TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS,        MS_WHLD,        MS_LEFT,        MS_DOWN,        MS_RGHT,        JV_NU,          KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS,        JV_UND,         JV_CUT,         JV_CPY,         JV_PST,         JV_RDO,         KC_TRNS,        TG(JV_GAME),    JV_NA,          TD(JV_TD_MOUSE),TD(JV_TD_SYM),  JV_NA,          JV_NA,          KC_TRNS,
  KC_NO,          MS_BTN3,        MS_BTN1,        MS_BTN2,        JV_NA,          JV_NA,          JV_NA,          KC_NO
),

// ── MEDIA ───────────────────────────────────────────────────────
[JV_MEDIA] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS,        UG_HUEU,        UG_SATU,        KC_VOLU,        UG_VALU,        UG_TOGG,        JV_NA,          TD(JV_TD_BASE), TD(JV_TD_QWERTY),TD(JV_TD_OSALT),TD(JV_TD_BOOT), KC_TRNS,
  KC_TRNS,        UG_NEXT,        KC_MPRV,        KC_VOLD,        KC_MNXT,        UG_NEXT,        KC_HYPR,        KC_RSFT,        KC_RGUI,        KC_RALT,        KC_RCTL,        KC_TRNS,
  KC_TRNS,        JV_NU,          JV_NU,          JV_NU,          JV_NU,          RGB_M_T,        KC_TRNS,        TG(JV_GAME),    JV_NA,          TD(JV_TD_MEDIA),TD(JV_TD_FUN),  JV_NA,          JV_NA,          KC_TRNS,
  KC_NO,          KC_MUTE,        KC_MPLY,        KC_MSTP,        JV_NA,          JV_NA,          JV_NA,          KC_NO
),

// ── NUM ─────────────────────────────────────────────────────────
[JV_NUM] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS,        TD(JV_TD_BOOT), TD(JV_TD_OSALT),TD(JV_TD_QWERTY),TD(JV_TD_BASE), MO(JV_NUMPAD),  KC_LBRC,        KC_7,           KC_8,           KC_9,           KC_RBRC,        KC_TRNS,
  KC_TRNS,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_LSFT,        KC_HYPR,        KC_EQL,         KC_4,           KC_5,           KC_6,           KC_SCLN,        KC_TRNS,
  KC_TRNS,        JV_NA,          JV_NU,          TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA,          KC_TRNS,        TG(JV_GAME),    KC_BSLS,        KC_1,           KC_2,           KC_3,           KC_GRV,         KC_TRNS,
  KC_NO,          JV_NA,          JV_NA,          JV_NA,          KC_MINS,        KC_0,           KC_DOT,         KC_NO
),

// ── NUMPAD ──────────────────────────────────────────────────────
[JV_NUMPAD] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS,        TD(JV_TD_BOOT), TD(JV_TD_OSALT),TD(JV_TD_QWERTY),TD(JV_TD_BASE), JV_NA,          KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_TRNS,
  KC_TRNS,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_LSFT,        KC_HYPR,        KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRNS,
  KC_TRNS,        JV_NA,          JV_NU,          TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA,          KC_TRNS,        TG(JV_GAME),    KC_KP_ENTER,    KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_EQUAL,    KC_TRNS,
  KC_NO,          JV_NA,          JV_NA,          JV_NA,          KC_BSPC,        KC_KP_0,        KC_KP_DOT,      KC_NO
),

// ── SYM ─────────────────────────────────────────────────────────
[JV_SYM] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS,        TD(JV_TD_BOOT), TD(JV_TD_OSALT),TD(JV_TD_QWERTY),TD(JV_TD_BASE), JV_NA,          KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        KC_TRNS,
  KC_TRNS,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_LSFT,        KC_HYPR,        KC_PLUS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_COLN,        KC_TRNS,
  KC_TRNS,        JV_NA,          JV_NA,          TD(JV_TD_MOUSE),TD(JV_TD_SYM),  JV_NA,          KC_TRNS,        TG(JV_GAME),    KC_PIPE,        KC_EXLM,        KC_AT,          KC_HASH,        KC_TILD,        KC_TRNS,
  KC_NO,          JV_NA,          JV_NA,          JV_NA,          KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_NO
),

// ── FUN ─────────────────────────────────────────────────────────
[JV_FUN] = LAYOUT(
  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
  KC_TRNS,        TD(JV_TD_BOOT), TD(JV_TD_OSALT),TD(JV_TD_QWERTY),TD(JV_TD_BASE), JV_NA,          KC_PSCR,        KC_F7,          KC_F8,          KC_F9,          KC_F12,         KC_TRNS,
  KC_TRNS,        KC_LCTL,        KC_LALT,        KC_LGUI,        KC_LSFT,        KC_HYPR,        KC_SCRL,        KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRNS,
  KC_TRNS,        JV_NA,          JV_NA,          TD(JV_TD_MEDIA),TD(JV_TD_FUN),  JV_NA,          KC_TRNS,        TG(JV_GAME),    KC_PAUS,        KC_F1,          KC_F2,          KC_F3,          KC_F10,         KC_TRNS,
  KC_NO,          JV_NA,          JV_NA,          JV_NA,          KC_TAB,         KC_SPC,         KC_APP,         KC_NO
),

// ── GAME (QWERTY, no home-row mods) ─────────────────────────────
[JV_GAME] = LAYOUT(
  KC_ESC,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
  KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
  KC_BSPC,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT,
  KC_KP_MINUS,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LALT,        TG(JV_GAME),    KC_N,          KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_KP_PLUS,
  MO(JV_GAME_FN), KC_LSFT,        KC_SPC,         KC_LCTL,        MO(JV_GAME_FN), KC_ENT,         KC_LALT,        KC_RSFT
),

// ── GAME_FN (function/numpad/navigation overlay) ────────────────
[JV_GAME_FN] = LAYOUT(
  KC_GRV,         KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_EQL,
  KC_KP_PLUS,     KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_PSCR,        KC_NUM_LOCK,    KC_KP_DOT,      KC_KP_ASTERISK, KC_KP_SLASH,    KC_KP_EQUAL,    KC_KP_ENTER,
  KC_BSPC,        KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_INS,         KC_DEL,         KC_LCTL,        KC_LSFT,        KC_LALT,        KC_F11,         KC_F12,
  KC_KP_MINUS,    KC_KP_6,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        KC_TRNS,        KC_TRNS,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,
  KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS
),

};

void keyboard_post_init_keymap(void) {
    // Windows-first board: EEPROM may still hold OSALT (Mac overlay) from an
    // older session or VIA tweak — always come back on the Windows base layer.
    if (default_layer_state & (layer_state_t)1 << JV_OSALT) {
        set_single_persistent_default_layer(JV_BASE);
    }
}

void suspend_power_down_user(void) {
    // Drop held LT/MO layers before sleep so wake doesn't inherit a stale NUM
    // (or other overlay) that makes PIN/login keys send modifiers instead of digits.
    layer_clear();
}

void suspend_wakeup_init_user(void) {
    layer_clear();
#ifndef NO_ACTION_ONESHOT
    clear_oneshot_mods();
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
#endif
    clear_keyboard();
}

#ifdef AUTO_SHIFT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto-shift must not fire while gaming (held WASD / numbers / symbols).
    if (layer_state_cmp(state, JV_GAME) || layer_state_cmp(state, JV_GAME_FN)) {
        autoshift_disable();
    } else {
        autoshift_enable();
    }
    return state;
}
#endif
