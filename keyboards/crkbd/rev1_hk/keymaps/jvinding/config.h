#pragma once

// Pull in all holykeebs hardware configuration.
// This handles MASTER_RIGHT, PS/2 pin assignments, SPLIT_WATCHDOG,
// EECONFIG_USER_DATA_SIZE, etc.
#include "users/holykeebs/config.h"

// Give the USB link a moment to settle after a host wake before resuming
// HID report sending, in case the state bounces right after resume.
#define USB_SUSPEND_WAKEUP_DELAY 200

// Gate the pointing device to the right (master) side only.
// Without these, ps2_mouse_init() and the PS/2 polling loop would run on the
// left (slave) too, stalling its matrix scan and causing taps to be missed.
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

// Throttle PS/2 polling so the trackpoint doesn't starve the matrix loop.
#define POINTING_DEVICE_TASK_THROTTLE_MS 16

// Split state sync so the slave-side (left) OLED can read layer_state.
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR

// RGB matrix tuning
#ifdef RGB_MATRIX_ENABLE
// Per-channel color correction for HolyKeebs CRKBD LEDs.
// Formula: output = (cache * 64 * MULT) >> 16; 1024 = no correction.
// Tune left/right independently to compensate for LED variance between halves.
// #define JV_RGB_CORRECT_LEFT_R   40u
// #define JV_RGB_CORRECT_LEFT_G   60u
// #define JV_RGB_CORRECT_LEFT_B  1024u
#define JV_RGB_CORRECT_LEFT_R   40u
#define JV_RGB_CORRECT_LEFT_G   40u
#define JV_RGB_CORRECT_LEFT_B  640u
#define JV_RGB_CORRECT_RIGHT_R  80u
#define JV_RGB_CORRECT_RIGHT_G  72u
#define JV_RGB_CORRECT_RIGHT_B 600u
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_LED_PROCESS_LIMIT ((RGB_MATRIX_LED_COUNT + 4) / 5)
#define RGB_MATRIX_LED_FLUSH_LIMIT   16
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#define RGB_MATRIX_HUE_STEP  8
#define RGB_MATRIX_SAT_STEP  8
#define RGB_MATRIX_VAL_STEP  8
#define RGB_MATRIX_SPD_STEP  10
#endif
