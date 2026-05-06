#pragma once

// Cirque SPI trackpad pacing (driver + pins already configured at keyboard level).
#define POINTING_DEVICE_TASK_THROTTLE_MS 16

// RGB Matrix tuning. City42 is unibody (single MCU), so jv_led_on_this_hand()
// always returns true and is_keyboard_left() evaluates true — only the LEFT
// correction values are in effect. Start at unity; tune if colors look off.
#define JV_RGB_BRIGHTNESS         64u
#define JV_RGB_CORRECT_LEFT_R   1024u
#define JV_RGB_CORRECT_LEFT_G   1024u
#define JV_RGB_CORRECT_LEFT_B   1024u

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_LED_PROCESS_LIMIT ((RGB_MATRIX_LED_COUNT + 4) / 5)
#define RGB_MATRIX_LED_FLUSH_LIMIT   16
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 10
