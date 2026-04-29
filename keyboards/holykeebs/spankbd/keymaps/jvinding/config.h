#pragma once

// Pull in all holykeebs hardware configuration.
// This handles MASTER_RIGHT, PS/2 pin assignments, SPLIT_WATCHDOG,
// EECONFIG_USER_DATA_SIZE, etc.
#include "users/holykeebs/config.h"

// Gate the pointing device to the right (master) side only.
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT

// Throttle PS/2 polling so the trackpoint doesn't starve the matrix loop.
#define POINTING_DEVICE_TASK_THROTTLE_MS 16

// Split state sync so the slave-side (left) OLED can read layer_state.
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR
