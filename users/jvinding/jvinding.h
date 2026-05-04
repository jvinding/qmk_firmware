#pragma once
#include "quantum.h"

// Caps word display state — set on master by caps_word_set_user, synced to slave.
extern bool jv_caps_word;

// ---------------------------------------------------------------------------
// Layer enum
// ---------------------------------------------------------------------------

enum jv_layers {
    JV_BASE,
    JV_EXTRA,
    JV_TAP,
    JV_BUTTON,
    JV_NAV,
    JV_MOUSE,
    JV_MEDIA,
    JV_NUM,
    JV_NUMPAD,
    JV_SYM,
    JV_FUN,
};

// ---------------------------------------------------------------------------
// Shared OLED helpers (oled.c)
// ---------------------------------------------------------------------------

#ifdef OLED_ENABLE
extern const char * const jv_layer_names[];
void jv_oled_draw_layer_caps(void);
void jv_oled_draw_caps_indicator(void);
void jv_oled_render_status(void);
#endif

// ---------------------------------------------------------------------------
// RGB helper (rgb.c)
// ---------------------------------------------------------------------------

#ifdef RGB_MATRIX_ENABLE
HSV jv_hsv_for_layer_id(uint8_t id);
#endif

// ---------------------------------------------------------------------------
// Tap-dance enum
// ---------------------------------------------------------------------------

enum jv_tap_dances {
    JV_TD_BOOT,
    JV_TD_BASE,
    JV_TD_EXTRA,
    JV_TD_TAP,
    JV_TD_BUTTON,
    JV_TD_NAV,
    JV_TD_MOUSE,
    JV_TD_MEDIA,
    JV_TD_NUM,
    JV_TD_NUMPAD,
    JV_TD_SYM,
    JV_TD_FUN,
};

// ---------------------------------------------------------------------------
// Shorthand aliases
// ---------------------------------------------------------------------------

// Mac clipboard
#define JV_UND LCMD(KC_Z)
#define JV_CUT LCMD(KC_X)
#define JV_CPY LCMD(KC_C)
#define JV_PST LCMD(KC_V)
#define JV_RDO SCMD(KC_Z)

#define JV_NA  KC_NO   // present but unavailable
#define JV_NU  KC_NO   // present but unused
#define JV_NP  KC_NO   // not physically present (placeholder)

// ---------------------------------------------------------------------------
// Per-layer 5-wide row macros (Colemak-DH with NAV/MOUSE/MEDIA on left thumb)
// Each expands to a comma-separated list of 5 keycodes.
//
// Thumb order convention for LAYOUT_split_3x6_3:
//   THUMBS_L: outer, mid, inner   (positions 36,37,38 in the layout macro)
//   THUMBS_R: inner, mid, outer   (positions 39,40,41 in the layout macro)
// ---------------------------------------------------------------------------

// BASE (Colemak-DH)
#define JV_BASE_ROW0_L  KC_Q,                   KC_W,              KC_F,             KC_P,             KC_G
#define JV_BASE_ROW0_R  KC_J,                   KC_L,              KC_U,             KC_Y,             KC_QUOT
#define JV_BASE_ROW1_L  LCTL_T(KC_A),           LALT_T(KC_R),      LGUI_T(KC_S),     LSFT_T(KC_T),     HYPR_T(KC_D)
#define JV_BASE_ROW1_R  HYPR_T(KC_H),           RSFT_T(KC_N),      RGUI_T(KC_E),     RALT_T(KC_I),     RCTL_T(KC_O)
#define JV_BASE_ROW2_L  LT(JV_BUTTON,KC_Z),     KC_X,              KC_C,             KC_V,             KC_B
#define JV_BASE_ROW2_R  KC_K,                   KC_M,              KC_COMM,          KC_DOT,           LT(JV_BUTTON,KC_SLSH)
#define JV_BASE_THUMBS_L  LT(JV_FUN,KC_DEL),    LT(JV_NUM,KC_BSPC),  LT(JV_SYM,KC_ENT)
#define JV_BASE_THUMBS_R  LT(JV_MOUSE,KC_TAB),  LT(JV_NAV,KC_SPC),   LT(JV_MEDIA,KC_ESC)

// EXTRA (ColemakDH)
#define JV_EXTRA_ROW0_L  KC_Q,                   KC_W,             KC_E,             KC_R,             KC_T
#define JV_EXTRA_ROW0_R  KC_Y,                   KC_U,             KC_I,             KC_O,             KC_P
#define JV_EXTRA_ROW1_L  LCTL_T(KC_A),           LALT_T(KC_S),     LGUI_T(KC_D),     LSFT_T(KC_F),     HYPR_T(KC_G)
#define JV_EXTRA_ROW1_R  HYPR_T(KC_H),           RSFT_T(KC_J),     RGUI_T(KC_K),     RALT_T(KC_L),     RCTL_T(KC_QUOT)
#define JV_EXTRA_ROW2_L  LT(JV_BUTTON,KC_Z),     KC_X,             KC_C,             KC_V,             KC_B
#define JV_EXTRA_ROW2_R  KC_N,                   KC_M,             KC_COMM,          KC_DOT,           LT(JV_BUTTON,KC_SLSH)
#define JV_EXTRA_THUMBS_L  JV_BASE_THUMBS_L
#define JV_EXTRA_THUMBS_R  JV_BASE_THUMBS_R

// TAP (Qwerty with reduced home-row mods for typing)
#define JV_TAP_ROW0_L  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS
#define JV_TAP_ROW0_R  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS
#define JV_TAP_ROW1_L  LGUI_T(KC_A), KC_TRNS, LCTL_T(KC_S), KC_TRNS,    KC_TRNS
#define JV_TAP_ROW1_R  KC_TRNS, KC_TRNS, RCTL_T(KC_E), KC_TRNS,         RGUI_T(KC_O)
#define JV_TAP_ROW2_L  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS
#define JV_TAP_ROW2_R  KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,          KC_TRNS
#define JV_TAP_THUMBS_L  KC_TRNS, KC_TRNS, KC_TRNS
#define JV_TAP_THUMBS_R  KC_TRNS, KC_TRNS, KC_TRNS

// BUTTON
#define JV_BUTTON_ROW0_L  MS_WHLL,  MS_WHLD,  MS_WHLU,  MS_WHLR,  JV_UND
#define JV_BUTTON_ROW0_R  JV_UND,   MS_WHLL,  MS_WHLD,  MS_WHLU,  MS_WHLR
#define JV_BUTTON_ROW1_L  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  JV_NU
#define JV_BUTTON_ROW1_R  JV_NU,    KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI
#define JV_BUTTON_ROW2_L  JV_UND,   JV_CUT,   JV_CPY,   JV_PST,   JV_RDO
#define JV_BUTTON_ROW2_R  JV_RDO,   JV_PST,   JV_CPY,   JV_CUT,   JV_UND
// Thumbs: L=(BTN3,BTN1,BTN2) R=(BTN2,BTN1,BTN3)
#define JV_BUTTON_THUMBS_L  MS_BTN3, MS_BTN1, MS_BTN2
#define JV_BUTTON_THUMBS_R  MS_BTN2, MS_BTN1, MS_BTN3

// NAV (inverted-T: PGUP/HOME/UP/END/INS top row, PGDN/LEFT/DOWN/RGHT/CW_TOGG home row)
#define JV_NAV_ROW0_L  KC_PGUP,  KC_HOME,            KC_UP,              KC_END,            KC_INS
#define JV_NAV_ROW0_R  JV_NA,    TD(JV_TD_BASE),     TD(JV_TD_EXTRA),    TD(JV_TD_TAP),     TD(JV_TD_BOOT)
#define JV_NAV_ROW1_L  KC_PGDN,  KC_LEFT,            KC_DOWN,            KC_RGHT,           CW_TOGG
#define JV_NAV_ROW1_R  KC_HYPR,  KC_RSFT,            KC_RGUI,            KC_RALT,           KC_RCTL
#define JV_NAV_ROW2_L  JV_UND,   JV_CUT,             JV_CPY,             JV_PST,            JV_RDO
#define JV_NAV_ROW2_R  JV_NA,    TD(JV_TD_NAV),      TD(JV_TD_NUM),      JV_NA,             JV_NA
// L=(DEL,BSPC,ENT)  R=(NA,NA,NA)
#define JV_NAV_THUMBS_L  KC_DEL,   KC_BSPC,  KC_ENT
#define JV_NAV_THUMBS_R  JV_NA,    JV_NA,    JV_NA

// MOUSE
#define JV_MOUSE_ROW0_L  MS_WHLU,  MS_WHLL,  MS_UP,    MS_WHLR,  JV_NU
#define JV_MOUSE_ROW0_R  JV_NA,    TD(JV_TD_BASE),  TD(JV_TD_EXTRA),  TD(JV_TD_TAP),  TD(JV_TD_BOOT)
#define JV_MOUSE_ROW1_L  MS_WHLD,  MS_LEFT,  MS_DOWN,  MS_RGHT,  JV_NU
#define JV_MOUSE_ROW1_R  KC_HYPR,  KC_RSFT,  KC_RGUI,  KC_RALT,  KC_RCTL
#define JV_MOUSE_ROW2_L  JV_UND,   JV_CUT,   JV_CPY,   JV_PST,   JV_RDO
#define JV_MOUSE_ROW2_R  JV_NA,    TD(JV_TD_MOUSE),  TD(JV_TD_SYM),  JV_NA,  JV_NA
// L=(BTN3,BTN1,BTN2)  R=(NA,NA,NA)
#define JV_MOUSE_THUMBS_L  MS_BTN3,  MS_BTN1,  MS_BTN2
#define JV_MOUSE_THUMBS_R  JV_NA,    JV_NA,    JV_NA

// MEDIA
#define JV_MEDIA_ROW0_L  UG_HUEU,  UG_SATU,  KC_VOLU,  UG_VALU,  UG_TOGG
#define JV_MEDIA_ROW0_R  JV_NA,    TD(JV_TD_BASE),  TD(JV_TD_EXTRA),  TD(JV_TD_TAP),  TD(JV_TD_BOOT)
#define JV_MEDIA_ROW1_L  UG_NEXT,  KC_MPRV,  KC_VOLD,  KC_MNXT,  UG_NEXT
#define JV_MEDIA_ROW1_R  KC_HYPR,  KC_RSFT,  KC_RGUI,  KC_RALT,  KC_RCTL
#define JV_MEDIA_ROW2_L  JV_NU,    JV_NU,    JV_NU,    JV_NU,    RGB_M_T
#define JV_MEDIA_ROW2_R  JV_NA,    TD(JV_TD_MEDIA),  TD(JV_TD_FUN),  JV_NA,  JV_NA
// L=(MUTE,MPLY,MSTP)  R=(NA,NA,NA)
#define JV_MEDIA_THUMBS_L  KC_MUTE,  KC_MPLY,  KC_MSTP
#define JV_MEDIA_THUMBS_R  JV_NA,    JV_NA,    JV_NA

// NUM
#define JV_NUM_ROW0_L  TD(JV_TD_BOOT),  TD(JV_TD_TAP),  TD(JV_TD_EXTRA),  TD(JV_TD_BASE),  MO(JV_NUMPAD)
#define JV_NUM_ROW0_R  KC_LBRC,  KC_7,  KC_8,  KC_9,  KC_RBRC
#define JV_NUM_ROW1_L  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_HYPR
#define JV_NUM_ROW1_R  KC_EQL,   KC_4,  KC_5,  KC_6,  KC_SCLN
#define JV_NUM_ROW2_L  JV_NA,    JV_NU,    TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA
#define JV_NUM_ROW2_R  KC_BSLS,  KC_1,  KC_2,  KC_3,  KC_GRV
// L=(NA,NA,NA)  R=(KC_MINS,KC_0,KC_DOT)
#define JV_NUM_THUMBS_L  JV_NA,    JV_NA, JV_NA
#define JV_NUM_THUMBS_R  KC_MINS,  KC_0,  KC_DOT

// NUMPAD
#define JV_NUMPAD_ROW0_L  TD(JV_TD_BOOT),  TD(JV_TD_TAP),  TD(JV_TD_EXTRA),  TD(JV_TD_BASE),  JV_NA
#define JV_NUMPAD_ROW0_R  KC_KP_SLASH,     KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_MINUS
#define JV_NUMPAD_ROW1_L  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_HYPR
#define JV_NUMPAD_ROW1_R  KC_KP_ASTERISK,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_PLUS
#define JV_NUMPAD_ROW2_L  JV_NA,    JV_NU,    TD(JV_TD_NAV),  TD(JV_TD_NUM),  JV_NA
#define JV_NUMPAD_ROW2_R  KC_KP_ENTER,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_EQUAL
// L=(NA,NA,NA)  R=(KC_BSPC,KC_KP_0,KC_KP_DOT)
#define JV_NUMPAD_THUMBS_L  JV_NA,    JV_NA,      JV_NA
#define JV_NUMPAD_THUMBS_R  KC_BSPC,  KC_KP_0,    KC_KP_DOT

// SYM
#define JV_SYM_ROW0_L  TD(JV_TD_BOOT),  TD(JV_TD_TAP),  TD(JV_TD_EXTRA),  TD(JV_TD_BASE),  JV_NA
#define JV_SYM_ROW0_R  KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RCBR
#define JV_SYM_ROW1_L  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_HYPR
#define JV_SYM_ROW1_R  KC_PLUS,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_COLN
#define JV_SYM_ROW2_L  JV_NA,    JV_NA,    TD(JV_TD_MOUSE),  TD(JV_TD_SYM),  JV_NA
#define JV_SYM_ROW2_R  KC_PIPE,  KC_EXLM,  KC_AT,    KC_HASH,  KC_TILD
// L=(NA,NA,NA)  R=(KC_UNDS,KC_LPRN,KC_RPRN)
#define JV_SYM_THUMBS_L  JV_NA,    JV_NA,    JV_NA
#define JV_SYM_THUMBS_R  KC_UNDS,  KC_LPRN,  KC_RPRN

// FUN
#define JV_FUN_ROW0_L  TD(JV_TD_BOOT),  TD(JV_TD_TAP),  TD(JV_TD_EXTRA),  TD(JV_TD_BASE),  JV_NA
#define JV_FUN_ROW0_R  KC_PSCR,  KC_F7,  KC_F8,  KC_F9,  KC_F12
#define JV_FUN_ROW1_L  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_HYPR
#define JV_FUN_ROW1_R  KC_SCRL,  KC_F4,  KC_F5,  KC_F6,  KC_F11
#define JV_FUN_ROW2_L  JV_NA,    JV_NA,    TD(JV_TD_MEDIA),  TD(JV_TD_FUN),  JV_NA
#define JV_FUN_ROW2_R  KC_PAUS,  KC_F1,  KC_F2,  KC_F3,  KC_F10
// L=(NA,NA,NA)  R=(KC_TAB,KC_SPC,KC_APP)
#define JV_FUN_THUMBS_L  JV_NA,   JV_NA,   JV_NA
#define JV_FUN_THUMBS_R  KC_TAB,  KC_SPC,  KC_APP
