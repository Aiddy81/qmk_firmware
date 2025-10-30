// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

// Pin definitions
static const pin_t row_pins[3] = {GP7, GP6, GP5};  // Scanned matrix rows
static const pin_t col_pins[3] = {GP4, GP3, GP2};  // Scanned matrix columns
static const pin_t direct_pins[2] = {GP11, GP14};  // Direct pins for encoder buttons

void matrix_init_custom(void) {
    // Initialize scanned matrix - rows as outputs
    for (uint8_t i = 0; i < 3; i++) {
        setPinOutput(row_pins[i]);
        writePinHigh(row_pins[i]);
    }
    
    // Initialize scanned matrix - columns as inputs with pullup
    for (uint8_t i = 0; i < 3; i++) {
        setPinInputHigh(col_pins[i]);
    }
    
    // Initialize direct pins as inputs with pullup
    for (uint8_t i = 0; i < 2; i++) {
        setPinInputHigh(direct_pins[i]);
    }
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

    // Scan the 3x3 matrix (rows 0-2)
    for (uint8_t row = 0; row < 3; row++) {
        matrix_row_t current_row_data = 0;

        // Select row
        writePinLow(row_pins[row]);
        matrix_output_select_delay();

        // Read columns
        for (uint8_t col = 0; col < 3; col++) {
            if (!readPin(col_pins[col])) {
                current_row_data |= (1 << col);
            }
        }

        // Unselect row
        writePinHigh(row_pins[row]);
        matrix_output_unselect_delay(row, current_row_data != 0);

        // Check if row changed
        if (current_matrix[row] != current_row_data) {
            current_matrix[row] = current_row_data;
            matrix_has_changed = true;
        }
    }

    // Read direct pins (rows 3 and 4)
    for (uint8_t i = 0; i < 2; i++) {
        uint8_t row = 3 + i;
        matrix_row_t current_row_data = 0;
        
        // Read direct pin (active low)
        if (!readPin(direct_pins[i])) {
            current_row_data = 1;  // Use column 0 for direct pins
        }

        // Check if row changed
        if (current_matrix[row] != current_row_data) {
            current_matrix[row] = current_row_data;
            matrix_has_changed = true;
        }
    }

    return matrix_has_changed;
}