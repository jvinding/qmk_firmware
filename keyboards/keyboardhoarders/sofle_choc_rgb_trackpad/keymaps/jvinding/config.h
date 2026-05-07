#pragma once

#define JV_RGB_BRIGHTNESS 16u

// Adds JV_GAME + JV_GAME_FN on top of the 11 shared layers in users/jvinding
#undef  DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 13

// Caps word split sync (handled in users/jvinding/jvinding.c)
#define SPLIT_TRANSACTION_IDS_USER JV_SYNC_CAPS_WORD

// Split state sync used by jv_oled_render_status (users/jvinding/oled.c)
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
