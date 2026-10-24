#pragma once

// I2C for OLED (D1=GP2=SDA, D0=GP3=SCL on SparkFun ProMicro RP2040)
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

// Same split/USB handling as the sofle_choc_rgb_trackpad board.
#define MASTER_RIGHT
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000
#define NO_USB_STARTUP_CHECK
#define USB_SUSPEND_WAKEUP_DELAY 200

// Split link: vendor (PIO) serial driver, selected in the keymap rules.mk
#define SERIAL_USART_TX_PIN GP1
