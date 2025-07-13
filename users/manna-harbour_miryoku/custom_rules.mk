# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

SRC += custom_code.c
SRC += custom_combos.c
SRC += custom_oled.c
SRC += custom_rgb.c

COMBO_ENABLE = yes

RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
OLED_ENABLE = yes

# debug
CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# decrease firmware size
LTO_ENABLE = yes
MAGIC_ENABLE = no
MUSIC_ENABLE = no
MIDI_ENABLE = no
AUDIO_ENABLE = no
BLUETOOTH_ENABLE = no
