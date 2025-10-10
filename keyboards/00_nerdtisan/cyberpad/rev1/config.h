#pragma once

// VIA Configuration
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

// Debounce reduces chatter
#define DEBOUNCE 5

// Encoder configuration
#define ENCODER_RESOLUTION 4

// WS2812 RGB LED configuration for RP2040
#define WS2812_PIO_USE_PIO1

// RGB Matrix configuration
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_HUE 128
#define RGB_MATRIX_STARTUP_SAT 255
#define RGB_MATRIX_STARTUP_VAL 200
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

// Enable specific RGB Matrix effects
#define ENABLE_RGB_MATRIX_SOLID_COLOR
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON

// OLED configuration
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 30000
#define OLED_BRIGHTNESS 128
// Try changing address if display is garbled/blank
// Common addresses: 0x3C (default) or 0x3D
#define OLED_DISPLAY_ADDRESS 0x3C