#Copyright 2025 Adrian Cafarella <qmk@nerdtisan.com>
BOARD = GENERIC_RP_RP2040
MCU = RP2040

LTO_ENABLE = yes
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Required for media keys
#CONSOLE_ENABLE = no
#COMMAND_ENABLE = no
NKRO_ENABLE = no
# Bootloader selection
BOOTLOADER = rp2040
#ANALOG_DRIVER_REQUIRED = yes
ENCODER_ENABLE = yes
RGBLIGHT_ENABLE = yes    # Enable RGB lighting
RGBLED_OPTION_TYPE = backlight
WPM_ENABLE = yes

OLED_ENABLE = yes
#oled_driver = yes
OLED_FONT_H = "keyboards/00_nerdtisan/cyberpad/lib/glcdfont.c"
#OLED_DRIVER = ssd1306
WS2812_DRIVER = vendor
WS2812_DI_PIN = GP8
RGBLIGHT_LED_COUNT = 9 # Number of LEDs
I2C_DRIVER_REQUIRED = yes

MCUCONF = keyboards/00_nerdtisan/cyberpad/rev1/mcuconf.h


