/*
Copyright 2025 Nerdtisan

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* USB Device descriptor parameter */
/*#define VENDOR_ID       0x7810
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    Nerdtisan
#define PRODUCT         cyberpad
#define DESCRIPTION     Three-button foot switch for media control
*/

/* Key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

/* Pin mapping — change to match your wiring */
//#define MATRIX_ROW_PINS { GP26 }
//#define MATRIX_COL_PINS { GP27, GP28, GP29 }
#define ENCODER_A_PINS { GP9, GP10 }
#define ENCODER_B_PINS { GP13, GP12 }
#define DIRECT_PINS { { GP11, GP14 } }
#define MATRIX_ROW_PINS { GP7, GP6, GP5 }
#define MATRIX_COL_PINS { GP4, GP3, GP2 }

/* Diode direction */
#define DIODE_4
/* Debounce time in ms */
//#define DEBOUNCE 5

// Tell QMK which I2C driver/peripheral to use:
#define I2C_DRIVER        I2CD1

// Map the logical I2C1 SDA/SCL to your GPIOs:
#define I2C1_SDA_PIN      GP26
#define I2C1_SCL_PIN      GP27

// WS2812 (RGBLIGHT) PIO driver settings
#define WS2812_DRIVER_VENDOR
#define WS2812_DI_PIN     GP8


