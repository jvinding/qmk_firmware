#include QMK_KEYBOARD_H
#include "jvinding.h"
#ifdef SPLIT_KEYBOARD
#    include "transactions.h"
#endif

// ---------------------------------------------------------------------------
// Caps word split sync
// ---------------------------------------------------------------------------

void keyboard_post_init_keymap(void);

bool jv_caps_word = false;

#if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
static void jv_caps_word_sync_handler(uint8_t buflen, const void *data, uint8_t rbuflen, void *rdata) {
    jv_caps_word = *(const bool *)data;
}
#endif

void keyboard_post_init_user(void) {
#if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
    transaction_register_rpc(JV_SYNC_CAPS_WORD, jv_caps_word_sync_handler);
#endif
    keyboard_post_init_keymap();
}

void housekeeping_task_user(void) {
#if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
    if (is_keyboard_master()) {
        static bool last_sent = false;
        if (jv_caps_word != last_sent) {
            if (transaction_rpc_send(JV_SYNC_CAPS_WORD, sizeof(jv_caps_word), &jv_caps_word)) {
                last_sent = jv_caps_word;
            }
        }
    }
#endif
}

// ---------------------------------------------------------------------------
// Tap dances
// ---------------------------------------------------------------------------

void jv_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

#define JV_TD_LAYER_FN(LAYER) \
void jv_td_fn_##LAYER(tap_dance_state_t *state, void *user_data) { \
    if (state->count == 2) { \
        default_layer_set((layer_state_t)1 << JV_##LAYER); \
    } \
}

JV_TD_LAYER_FN(BASE)
JV_TD_LAYER_FN(EXTRA)
JV_TD_LAYER_FN(TAP)
JV_TD_LAYER_FN(BUTTON)
JV_TD_LAYER_FN(NAV)
JV_TD_LAYER_FN(MOUSE)
JV_TD_LAYER_FN(MEDIA)
JV_TD_LAYER_FN(NUM)
JV_TD_LAYER_FN(NUMPAD)
JV_TD_LAYER_FN(SYM)
JV_TD_LAYER_FN(FUN)

tap_dance_action_t tap_dance_actions[] = {
    [JV_TD_BOOT]   = ACTION_TAP_DANCE_FN(jv_td_fn_boot),
    [JV_TD_BASE]   = ACTION_TAP_DANCE_FN(jv_td_fn_BASE),
    [JV_TD_EXTRA]  = ACTION_TAP_DANCE_FN(jv_td_fn_EXTRA),
    [JV_TD_TAP]    = ACTION_TAP_DANCE_FN(jv_td_fn_TAP),
    [JV_TD_BUTTON] = ACTION_TAP_DANCE_FN(jv_td_fn_BUTTON),
    [JV_TD_NAV]    = ACTION_TAP_DANCE_FN(jv_td_fn_NAV),
    [JV_TD_MOUSE]  = ACTION_TAP_DANCE_FN(jv_td_fn_MOUSE),
    [JV_TD_MEDIA]  = ACTION_TAP_DANCE_FN(jv_td_fn_MEDIA),
    [JV_TD_NUM]    = ACTION_TAP_DANCE_FN(jv_td_fn_NUM),
    [JV_TD_NUMPAD] = ACTION_TAP_DANCE_FN(jv_td_fn_NUMPAD),
    [JV_TD_SYM]    = ACTION_TAP_DANCE_FN(jv_td_fn_SYM),
    [JV_TD_FUN]    = ACTION_TAP_DANCE_FN(jv_td_fn_FUN),
};

// ---------------------------------------------------------------------------
// Key overrides: Shift + CW_TOGG → Caps Lock
// ---------------------------------------------------------------------------

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t *key_overrides[] = {
    &capsword_key_override,
    NULL
};

// ---------------------------------------------------------------------------
// RGB init via keyboard_post_init_keymap (holykeebs owns keyboard_post_init_user)
// ---------------------------------------------------------------------------

void keyboard_post_init_keymap(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
#endif
}
