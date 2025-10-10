#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer
     * ┌─────┬─────┬─────┐
     * │ ENC1│     │     │
     * ├─────┼─────┼─────┤
     * │ ENC2│     │     │
     * ├─────┼─────┼─────┤
     * │  1  │  2  │  3  │
     * ├─────┼─────┼─────┤
     * │  4  │  5  │  6  │
     * ├─────┼─────┼─────┤
     * │  7  │  8  │  9  │
     * └─────┴─────┴─────┘
     */
    [_BASE] = LAYOUT(
        KC_MUTE,  // Encoder 1 button (matrix 3,0)
        KC_MPLY,  // Encoder 2 button (matrix 4,0)
        KC_1, KC_2, KC_3,  // Row 0
        KC_4, KC_5, KC_6,  // Row 1
        KC_7, KC_8, KC_9   // Row 2
    ),

    /* Function Layer 1 */
    [_FN1] = LAYOUT(
        QK_RGB_MATRIX_TOGGLE,
        QK_RGB_MATRIX_MODE_NEXT,
        KC_F13, KC_F14, KC_F15,
        KC_F16, KC_F17, KC_F18,
        KC_F19, KC_F20, KC_F21
    ),

    /* Function Layer 2 */
    [_FN2] = LAYOUT(
        KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* Function Layer 3 */
    [_FN3] = LAYOUT(
        KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// Encoder mappings per layer
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_FN1]  = { ENCODER_CCW_CW(QK_RGB_MATRIX_VALUE_UP, QK_RGB_MATRIX_VALUE_DOWN), ENCODER_CCW_CW(QK_RGB_MATRIX_HUE_UP, QK_RGB_MATRIX_HUE_DOWN) },
    [_FN2]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN3]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

// RGB Matrix per-layer colors
bool rgb_matrix_indicators_user(void) {
    switch(get_highest_layer(layer_state)) {
        case _BASE:
            // Layer 0 - Blue theme
            rgb_matrix_set_color_all(0, 100, 255);
            break;
        case _FN1:
            // Layer 1 - Green theme
            rgb_matrix_set_color_all(0, 255, 100);
            break;
        case _FN2:
            // Layer 2 - Red theme
            rgb_matrix_set_color_all(255, 50, 0);
            break;
        case _FN3:
            // Layer 3 - Purple theme
            rgb_matrix_set_color_all(200, 0, 255);
            break;
    }
    return false;
}

// OLED display
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // Try different rotations if display is wrong:
    // OLED_ROTATION_0   - Normal
    // OLED_ROTATION_90  - 90 degrees
    // OLED_ROTATION_180 - Upside down
    // OLED_ROTATION_270 - 270 degrees
    return OLED_ROTATION_0;
}

// Draw layer name
void render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _FN1:
            oled_write_ln_P(PSTR("FN1"), false);
            break;
        case _FN2:
            oled_write_ln_P(PSTR("FN2"), false);
            break;
        case _FN3:
            oled_write_ln_P(PSTR("FN3"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
    }
}

// Draw key icons (simplified 3x3 grid)
void render_keymap_icons(void) {
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("Key Layout:"), false);
    oled_write_ln_P(PSTR(""), false);
    
    // Simple representation of the 3x3 grid
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR(" 1   2   3"), false);
            oled_write_ln_P(PSTR(" 4   5   6"), false);
            oled_write_ln_P(PSTR(" 7   8   9"), false);
            break;
        case _FN1:
            oled_write_ln_P(PSTR("F13 F14 F15"), false);
            oled_write_ln_P(PSTR("F16 F17 F18"), false);
            oled_write_ln_P(PSTR("F19 F20 F21"), false);
            break;
        default:
            oled_write_ln_P(PSTR("--- --- ---"), false);
            oled_write_ln_P(PSTR("--- --- ---"), false);
            oled_write_ln_P(PSTR("--- --- ---"), false);
            break;
    }
}

bool oled_task_user(void) {
    // Display layer state
    render_layer_state();
    
    // Display keymap icons
    render_keymap_icons();
    
    return false;
}

#endif