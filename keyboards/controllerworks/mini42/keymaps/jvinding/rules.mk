USER_NAME = jvinding

# Right half is master (USB-connected side)
SERIAL_DRIVER = vendor

# OLED and RGB
OLED_ENABLE       = yes
OLED_DRIVER       = ssd1306
RGB_MATRIX_ENABLE = yes

# Userspace .c files (combos.c and jvinding.c are #included from keymap.c)
SRC += $(TOP_DIR)/users/jvinding/oled.c
SRC += $(TOP_DIR)/users/jvinding/rgb.c

# Per-board overrides
SRC += oled_status.c
SRC += rgb_keyboard.c

CAPS_WORD_ENABLE     = yes
MOUSEKEY_ENABLE      = yes
COMBO_ENABLE         = yes
TAP_DANCE_ENABLE     = yes
WPM_ENABLE           = yes

EXTRAINCDIRS += users/jvinding
