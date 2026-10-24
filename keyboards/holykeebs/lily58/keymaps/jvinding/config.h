#pragma once

#define JV_WINDOWS_FIRST

// Adds JV_GAME + JV_GAME_FN on top of the 11 shared layers in users/jvinding
#undef  DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 13

// Caps word split sync (handled in users/jvinding/jvinding.c)
#define SPLIT_TRANSACTION_IDS_USER JV_SYNC_CAPS_WORD

// Split state sync used by jv_oled_render_status (users/jvinding/oled.c),
// so the left OLED works even when USB is plugged into the right half.
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

// RGB matrix (per-key + 6 underglow LEDs per half) — layer colors come from users/jvinding/rgb.c
#define JV_RGB_BRIGHTNESS 64u
// Per-channel color correction (1024 = none), crkbd values x4 on red/green; the crkbd values crush hue (BASE vs GAME looked identical).
// Left half runs a bit more orange than the right, hence the lower red/green there.
#define JV_RGB_CORRECT_LEFT_R   90u
#define JV_RGB_CORRECT_LEFT_G  120u
#define JV_RGB_CORRECT_LEFT_B  640u
#define JV_RGB_CORRECT_RIGHT_R 320u
#define JV_RGB_CORRECT_RIGHT_G 288u
#define JV_RGB_CORRECT_RIGHT_B 600u
#define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_DISABLE_WHEN_USB_SUSPENDED
