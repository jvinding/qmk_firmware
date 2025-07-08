# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

SRC += custom_code.c
# SRC += rgb_matrix_user.c
SRC += rgb_matrix2.c

## TODO JJV: disable console
# CONSOLE_ENABLE = yes
COMBO_ENABLE = yes
# VIA_ENABLE = yes

## TODO JJV: I shouldn't need this
# BOOTLOADER = caterin

RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no

# Reduce firmware size to make room for RGB Matrix
# MOUSEKEY_ENABLE = no
# EXTRAKEY_ENABLE = no
COMMAND_ENABLE = no

# BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
# MOUSEKEY_ENABLE = yes       # Mouse keys
# EXTRAKEY_ENABLE = no       # Audio control and System control
# CONSOLE_ENABLE = no         # Console for debug
# COMMAND_ENABLE = no        # Commands for debug and configuration
# NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
# UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
# RGBLIGHT_ENABLE = no
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
