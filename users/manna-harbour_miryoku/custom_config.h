#pragma once

#define EE_HANDS

#define MIRYOKU_NAV_INVERTEDT
#define MIRYOKU_LAYERS_FLIP
#define MIRYOKU_ALPHAS_COLEMAK
#define MIRYOKU_EXTRA_COLEMAKDH
#define MIRYOKU_TAP_QWERTY
#define MIRYOKU_CLIPBOARD_MAC

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

// https://github.com/qmk/qmk_firmware/issues/18511#issuecomment-1264604610
// https://github.com/qmk/qmk_firmware/issues/8990#issuecomment-851055637
// #undef SPLIT_USB_DETECT

// #define SPLIT_USB_DETECT
// #define TAPPING_TOGGLE 2
// TODO JJV it looks like miryoku is overriding anything I set here. fix it.
#define TAPPING_TERM 250

// #define RGB_MATRIX_LED_FLUSH_LIMIT 96

#define CHORDAL_HOLD
// #define BILATERAL_COMBINATIONS

#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

// #undef RGBLIGHT_ANIMATIONS


#define DYNAMIC_KEYMAP_LAYER_COUNT 9
// #define LAYER_STATE_8BIT

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_G,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
LCTL_T(KC_A),      LALT_T(KC_R),      LGUI_T(KC_S),      LSFT_T(KC_T),      HYPR_T(KC_D),      HYPR_T(KC_H),      RSFT_T(KC_N),      RGUI_T(KC_E),      RALT_T(KC_I),      RCTL_T(KC_O),      \
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_K,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_LAYER_EXTRA \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LCTL_T(KC_A),      LALT_T(KC_S),      LGUI_T(KC_D),      LSFT_T(KC_F),      HYPR_T(KC_G),      HYPR_T(KC_H),      RSFT_T(KC_J),      RGUI_T(KC_K),      RALT_T(KC_L),      RCTL_T(KC_QUOT),   \
KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              LT(U_FUN,KC_DEL),  LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  LT(U_MEDIA,KC_ESC),U_NP,              U_NP

#define MIRYOKU_LAYER_TAP \
KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           \
LGUI_T(KC_A),      KC_TRNS,           LCTL_T(KC_S),      KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           RCTL_T(KC_E),      KC_TRNS,           RGUI_T(KC_O),      \
KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           \
U_NP,              U_NP,              KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           U_NP,              U_NP

#define MIRYOKU_LAYER_NAV \
KC_PGUP,           KC_HOME,           KC_UP,             KC_END,            KC_INS,            U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_PGDN,           KC_LEFT,           KC_DOWN,           KC_RGHT,           CW_TOGG,           KC_HYPR,           KC_RSFT,           KC_RGUI,           KC_RALT,           KC_RCTL,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              TD(U_TD_U_NAV),    TD(U_TD_U_NUM),    U_NA,              U_NA,              \
U_NP,              U_NP,              KC_DEL,            KC_BSPC,           KC_ENT,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
KC_WH_U,           KC_WH_L,           KC_MS_U,           KC_WH_R,           U_NU,              U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
KC_WH_D,           KC_MS_L,           KC_MS_D,           KC_MS_R,           U_NU,              KC_HYPR,           KC_RSFT,           KC_RGUI,           KC_RALT,           KC_RCTL,           \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              TD(U_TD_U_MOUSE),  TD(U_TD_U_SYM),    U_NA,              U_NA,              \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MEDIA \
RGB_HUI,           RGB_SAI,           KC_VOLU,           RGB_VAI,           RGB_TOG,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
RGB_MOD,           KC_MPRV,           KC_VOLD,           KC_MNXT,           RGB_MOD,           KC_HYPR,           KC_RSFT,           KC_RGUI,           KC_RALT,           KC_RCTL,           \
U_NU,              U_NU,              U_NU,              U_NU,              RGB_M_T,           U_NA,              TD(U_TD_U_MEDIA),  TD(U_TD_U_FUN),    U_NA,              U_NA,              \
U_NP,              U_NP,              KC_MUTE,           KC_MPLY,           KC_MSTP,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           \
KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_HYPR,           KC_EQL,            KC_4,              KC_5,              KC_6,              KC_SCLN,           \
U_NA,              U_NU,              TD(U_TD_U_NAV),    TD(U_TD_U_NUM),    U_NA,              KC_BSLS,           KC_1,              KC_2,              KC_3,              KC_GRV,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MINS,           KC_0,              KC_DOT,            U_NP,              U_NP

#define MIRYOKU_LAYER_SYM \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           \
KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_HYPR,           KC_PLUS,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_COLN,           \
U_NA,              U_NA,              TD(U_TD_U_MOUSE),  TD(U_TD_U_SYM),    U_NA,              KC_PIPE,           KC_EXLM,           KC_AT,             KC_HASH,           KC_TILD,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_UNDS,           KC_LPRN,           KC_RPRN,           U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              KC_PSCR,           KC_F7,             KC_F8,             KC_F9,             KC_F12,            \
KC_LCTL,           KC_LALT,           KC_LGUI,           KC_LSFT,           KC_HYPR,           KC_SCRL,           KC_F4,             KC_F5,             KC_F6,             KC_F11,            \
U_NA,              U_NA,              TD(U_TD_U_MEDIA),  TD(U_TD_U_FUN),    U_NA,              KC_PAUS,           KC_F1,             KC_F2,             KC_F3,             KC_F10,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_TAB,            KC_SPC,            KC_APP,            U_NP,              U_NP

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
#define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#endif
