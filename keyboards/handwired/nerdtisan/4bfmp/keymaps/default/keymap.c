// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Define the number of rows and columns in your matrix
#define MATRIX_ROWS 1
#define MATRIX_COLS 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,   // Switch 1
        KC_1,     // Switch 2
        KC_ESC,   // Switch 3
        QK_BOOT
    )
};
