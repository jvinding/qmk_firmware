#pragma once

// I2C for OLED (D1=GP2=SDA, D0=GP3=SCL on SparkFun ProMicro RP2040)
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

// Split handedness: USB-connected half is master; left side is master when USB
// is on both (or on neither). Matches vendor vial config.
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000
#define MASTER_RIGHT
#define JV_WINDOWS_FIRST
// Skip the boot-time SUSPENDED busy-loop. Required when SPLIT_USB_DETECT is
// set on Windows hosts — long S3 sleep can leave the master half wedged in
// the chibios protocol loop on resume, preventing matrix scan and RGB output
// until USB is replugged.
#define NO_USB_STARTUP_CHECK
// Settle delay after the host signals wakeup. Windows resume often bounces
// SUSPEND/RESUME edges; 200 ms prevents HID endpoint races.
#define USB_SUSPEND_WAKEUP_DELAY 200

// Trackpad (Azoteq TPS43, right half, I2C on same GP2/GP3 pins as left OLED)
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_TASK_THROTTLE_MS 16

#define AZOTEQ_IQS5XX_WIDTH_MM  43
#define AZOTEQ_IQS5XX_HEIGHT_MM 30
#define AZOTEQ_IQS5XX_RESOLUTION_X 1400
#define AZOTEQ_IQS5XX_RESOLUTION_Y 1400

#define AZOTEQ_IQS5XX_TAP_ENABLE              true
#define AZOTEQ_IQS5XX_TWO_FINGER_TAP_ENABLE   true
#define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE   true
#define AZOTEQ_IQS5XX_SWIPE_X_ENABLE          false
#define AZOTEQ_IQS5XX_SWIPE_Y_ENABLE          false
#define AZOTEQ_IQS5XX_ZOOM_ENABLE             false

#define AZOTEQ_IQS5XX_TAP_TIME              110
#define AZOTEQ_IQS5XX_TAP_DISTANCE          12
#define AZOTEQ_IQS5XX_HOLD_TIME             320
#define AZOTEQ_IQS5XX_TIMEOUT_MS            6
#define AZOTEQ_IQS5XX_SCROLL_INITIAL_DISTANCE 18

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_LED_PROCESS_LIMIT ((RGB_MATRIX_LED_COUNT + 4) / 5)
#define RGB_MATRIX_LED_FLUSH_LIMIT   16
// RGB_MATRIX_SLEEP is set via keyboard.json rgb_matrix.sleep
#define RGB_MATRIX_HUE_STEP  8
#define RGB_MATRIX_SAT_STEP  8
#define RGB_MATRIX_VAL_STEP  8
#define RGB_MATRIX_SPD_STEP  10
#endif
