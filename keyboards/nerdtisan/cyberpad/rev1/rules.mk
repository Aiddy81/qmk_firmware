#Copyright 2025 Adrian Cafarella <qmk@nerdtisan.com>
BOARD = GENERIC_RP_RP2040
MCU = RP2040
BOOTLOADER = rp2040


# Custom matrix implementation for encoder buttons
CUSTOM_MATRIX = lite
SRC += matrix.c

# Build Options
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes     # Enable RGB Matrix
RGB_MATRIX_DRIVER = ws2812  # RGB Matrix driver
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = yes        # Enable rotary encoder support
ENCODER_MAP_ENABLE = yes    # Enable encoder map feature
OLED_ENABLE = yes           # Enable OLED display
OLED_DRIVER = ssd1306       # OLED driver

# VIA support
VIA_ENABLE = yes



