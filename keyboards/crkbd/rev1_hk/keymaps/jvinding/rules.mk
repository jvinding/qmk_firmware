USER_NAME = jvinding

# Right half is master (USB-connected side)
OPT_DEFS += -DHK_MASTER_RIGHT
OPT_DEFS += -DHK_POINTING_DEVICE_RIGHT_TRACKPOINT

# Split serial
SERIAL_DRIVER = vendor

# Trackpoint via PS/2
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = ps2
PS2_ENABLE             = yes
PS2_DRIVER             = vendor

# OLED and RGB re-enabled
OLED_ENABLE       = yes
OLED_DRIVER       = ssd1306
RGB_MATRIX_ENABLE = yes

# ps2_mouse.c provides ps2_mouse_init() used by drivers/sensors/ps2.c
SRC += $(TOP_DIR)/drivers/ps2/ps2_mouse.c

# Holykeebs trackpoint plumbing
SRC += $(TOP_DIR)/users/holykeebs/holykeebs.c
SRC += $(TOP_DIR)/users/holykeebs/trackpoint.c
SRC += $(TOP_DIR)/users/holykeebs/pimoroni.c
SRC += $(TOP_DIR)/users/holykeebs/hk_debug.c
SRC += $(TOP_DIR)/users/holykeebs/rpc.c

# jvinding user space OLED and RGB (combos.c and jvinding.c are #included from keymap.c)
SRC += $(TOP_DIR)/users/jvinding/oled.c
SRC += $(TOP_DIR)/users/jvinding/rgb.c

# Required by oled.c for caps word sync
CAPS_WORD_ENABLE     = yes

MOUSEKEY_ENABLE      = yes
COMBO_ENABLE         = yes
TAP_DANCE_ENABLE     = yes

# Per-keyboard RGB hook
SRC += rgb_keyboard.c

# keymap.c and rgb_keyboard.c include jvinding.h from the user space directory
EXTRAINCDIRS += users/jvinding
