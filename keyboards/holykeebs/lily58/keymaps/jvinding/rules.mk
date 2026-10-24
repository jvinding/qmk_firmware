USER_NAME = jvinding

# Split serial (vendor keyboard.json leaves this to the holykeebs userspace)
SERIAL_DRIVER = vendor

OLED_ENABLE = yes
RGB_MATRIX_ENABLE = yes

# combos.c and jvinding.c are #included from keymap.c
SRC += $(USER_PATH)/oled.c
SRC += $(USER_PATH)/rgb.c

CAPS_WORD_ENABLE = yes
MOUSEKEY_ENABLE  = yes
COMBO_ENABLE     = yes
TAP_DANCE_ENABLE = yes

EXTRAINCDIRS += users/jvinding
