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
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    Nerdtisan
#define PRODUCT         3bmp
#define DESCRIPTION     Three-button foot switch for media control
*/

/* Key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 4

/* Pin mapping — change to match your wiring */
//#define MATRIX_ROW_PINS { GP26 }
//#define MATRIX_COL_PINS { GP27, GP28, GP29 }
#define DIRECT_PINS { { GP26, GP27, GP28, GP29 } }

/* Diode direction */
//#define DIODE_4
/* Debounce time in ms */
//#define DEBOUNCE 5
