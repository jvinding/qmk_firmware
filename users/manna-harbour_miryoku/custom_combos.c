enum combos {
  DELZ_UNDO,
  ZX_CUT,
  XC_COPY,
  CV_PASTE,
  VB_REDO
};

uint16_t COMBO_LEN = 5;

const uint16_t PROGMEM combo_delz[] = {KC_DEL, KC_Z, COMBO_END};
const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_vb[] = {KC_DEL, KC_Z, COMBO_END};

combo_t key_combos[] = {
  [DELZ_UNDO] = COMBO(combo_delz, U_UND),
  [ZX_CUT] = COMBO(combo_zx, U_CUT),
  [XC_COPY] = COMBO(combo_xc, U_CPY),
  [CV_PASTE] = COMBO(combo_cv, U_PST),
  [VB_REDO] = COMBO(combo_vb, U_RDO)
};
