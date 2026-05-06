USER_NAME = jvinding

# users/jvinding/rules.mk (auto-applied via USER_NAME) enables:
#   MOUSEKEY_ENABLE, EXTRAKEY_ENABLE, CAPS_WORD_ENABLE, COMBO_ENABLE,
#   TAP_DANCE_ENABLE, KEY_OVERRIDE_ENABLE, AUTO_SHIFT_ENABLE, LTO_ENABLE
# and disables RGBLIGHT, BACKLIGHT, MUSIC, MIDI, etc.
#
# keyboard.json already enables: rgb_matrix, pointing_device, mousekey,
#   extrakey, nkro, bootmagic.
# keyboard-level rules.mk already sets:
#   POINTING_DEVICE_DRIVER = cirque_pinnacle_spi

# Shared jvinding RGB engine: per-layer colors + per-key overrides.
SRC += $(TOP_DIR)/users/jvinding/rgb.c

EXTRAINCDIRS += users/jvinding
