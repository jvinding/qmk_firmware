#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_zx, JV_CUT),
    COMBO(combo_xc, JV_CPY),
    COMBO(combo_cv, JV_PST),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);
#endif
