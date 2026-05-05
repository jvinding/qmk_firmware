#pragma once

// Right half is master (USB-connected).
#define MASTER_RIGHT

// Bootmagic keys — moved one column inward because the outer columns have no
// switches.  Coordinates are local (per-half) matrix positions.
//   Left  half: Q key = [row 0, col 1]
//   Right half: ' key = [row 0, col 4]
#define BOOTMAGIC_ROW           0
#define BOOTMAGIC_COLUMN        1
#define BOOTMAGIC_ROW_RIGHT     0
#define BOOTMAGIC_COLUMN_RIGHT  4

// Split state sync.  keyboard.json already enables layer_state, modifiers,
// matrix_state, and indicators; add WPM so the slave-left OLED can display it.
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_TRANSPORT_MIRROR

// Custom RPC for caps word state (master → slave).
#define SPLIT_TRANSACTION_IDS_USER JV_SYNC_CAPS_WORD

// Reliable master detection on RP2040.  MASTER_RIGHT alone uses a one-shot
// USB-bus check at early boot; the RP2040 USB driver often hasn't reached
// USB_ACTIVE yet, so both halves latch as slave.  SPLIT_USB_DETECT polls
// until the bus is active, ensuring the right half wins as master.
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500

// Recover if the keyboard is already plugged in when the MCU boots.
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

// RGB matrix tuning — mirrors crkbd/rev1_hk values; adjust after first flash.
#ifdef RGB_MATRIX_ENABLE
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
