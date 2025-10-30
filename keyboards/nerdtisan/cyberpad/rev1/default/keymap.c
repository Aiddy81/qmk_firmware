#include QMK_KEYBOARD_H

#ifdef VIA_ENABLE
    #include "via.h"
#endif

// Layer definitions
enum layers {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum keycodes {
  KC_CLAY = QK_USER,
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
        KC_CLAY,  // Encoder 1 button (matrix 3,0)
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


// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   3

// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CLAY:
      if (record->event.pressed) {
        uint8_t current_layer = get_highest_layer(layer_state);
        uint8_t next_layer = (current_layer + 1) % 4;  // Cycle through 0,1,2,3
        layer_move(next_layer);
      }
      return false;

    default:
      return true;
  }
}

// Place `KC_CLAY` as a keycode in your keymap

// Encoder mappings - VIA will allow remapping these through the Encoder tab
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { 
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  // Encoder 0 (Encoder 1)
        ENCODER_CCW_CW(KC_MNXT, KC_MPRV)   // Encoder 1 (Encoder 2)
    },
    [_FN1]  = { 
        ENCODER_CCW_CW(QK_RGB_MATRIX_VALUE_UP, QK_RGB_MATRIX_VALUE_DOWN),
        ENCODER_CCW_CW(QK_RGB_MATRIX_HUE_UP, QK_RGB_MATRIX_HUE_DOWN)    
    },
    [_FN2]  = { 
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    },
    [_FN3]  = { 
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
        ENCODER_CCW_CW(KC_TRNS, KC_TRNS)   
    }
};
#endif



// RGB Matrix per-layer colors
/*
bool rgb_matrix_indicators_user(void) {
    // Function called when layer state changes
    // Get the highest active layer
    uint8_t highest_layer = get_highest_layer(state);
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
*/
/*
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_sethsv (0x00,  0x00, 0xFF);
        break;
    case _FN1:
        rgblight_sethsv (0xFF,  0x00, 0x00);
        break;
    case _FN2:
        rgblight_sethsv (0x00,  0xFF, 0x00);
        break;
    case _FN3:
        rgblight_sethsv (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}
*/
/*
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
    //oled_delay(1000); // Display for 1 second
    //oled_clear_line();
}

bool oled_task_user(void) {
    render_logo();
    return false;
}
*/

#if defined(DIP_SWITCH_MAP_ENABLE)
const uint16_t PROGMEM dip_switch_map[NUM_DIP_SWITCHES][NUM_DIP_STATES] = {
    DIP_SWITCH_OFF_ON(DF(0), DF(1)),
    DIP_SWITCH_OFF_ON(EC_NORM, EC_SWAP)
};
#endif


// Place this AFTER the keyboard_post_init_user function
// and BEFORE any existing encoder_update_user function

// ============================================================================
// OLED DISPLAY WITH SPACE INVADERS GAME
// ============================================================================

// Animation state - must be before #ifdef so encoder function can access them
static uint32_t last_input_time = 0;
static bool game_active = false;
static uint8_t ship_x = 64;

#ifdef OLED_ENABLE

// Space Invaders game state
#define NUM_INVADERS 12
static uint8_t invader_x[NUM_INVADERS] = {10, 25, 40, 55, 10, 25, 40, 55, 10, 25, 40, 55};
static uint8_t invader_y[NUM_INVADERS] = {8, 8, 8, 8, 16, 16, 16, 16, 24, 24, 24, 24};
static bool invader_alive[NUM_INVADERS] = {true, true, true, true, true, true, true, true, true, true, true, true};
static int8_t invader_direction = 1;  // 1 = right, -1 = left
static uint8_t invader_move_counter = 0;

// Ship and bullet
static uint8_t ship_y = 56;
static uint8_t bullet_x = 0;
static uint8_t bullet_y = 0;
static bool bullet_active = false;

// Timing
static uint32_t last_game_update = 0;
static uint32_t last_bullet_update = 0;
static uint32_t last_fire_time = 0;

#define IDLE_TIMEOUT 10000  // 10 seconds of no input = screensaver
#define GAME_UPDATE_INTERVAL 200  // Update invaders every 200ms
#define BULLET_UPDATE_INTERVAL 30  // Update bullet every 30ms (faster)
#define FIRE_INTERVAL 800  // Fire every 800ms

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    last_input_time = timer_read32();
    return OLED_ROTATION_0;
}

// Reset game state
static void reset_game(void) {
    // Reset invader positions (3 rows of 4)
    for (int i = 0; i < NUM_INVADERS; i++) {
        invader_alive[i] = true;
        invader_x[i] = 10 + (i % 4) * 15;
        invader_y[i] = 8 + (i / 4) * 8;
    }
    invader_direction = 1;
    invader_move_counter = 0;
    bullet_active = false;
    ship_x = 64;
}

// Check if bullet hit an invader
static void check_collisions(void) {
    if (!bullet_active) return;
    
    for (int i = 0; i < NUM_INVADERS; i++) {
        if (!invader_alive[i]) continue;
        
        // Convert to character positions for collision detection
        uint8_t inv_char_x = invader_x[i] / 6;
        uint8_t inv_char_y = invader_y[i] / 8;
        uint8_t bul_char_x = bullet_x / 6;
        uint8_t bul_char_y = bullet_y / 8;
        
        // Check if bullet hit invader
        if (bul_char_x == inv_char_x && bul_char_y == inv_char_y) {
            invader_alive[i] = false;
            bullet_active = false;
            break;
        }
    }
}

// Update game logic
static void update_game(void) {
    uint32_t now = timer_read32();
    
    // Update bullet position (faster than invaders)
    if (bullet_active && (now - last_bullet_update > BULLET_UPDATE_INTERVAL)) {
        last_bullet_update = now;
        if (bullet_y > 0) {
            bullet_y -= 4;  // Move bullet up
        } else {
            bullet_active = false;
        }
        check_collisions();
    }
    
    // Auto-fire bullets
    if (!bullet_active && (now - last_fire_time > FIRE_INTERVAL)) {
        last_fire_time = now;
        bullet_active = true;
        bullet_x = ship_x;
        bullet_y = ship_y - 2;
    }
    
    // Update invader positions
    if (now - last_game_update < GAME_UPDATE_INTERVAL) {
        return;
    }
    last_game_update = now;
    
    // Move invaders
    bool hit_edge = false;
    for (int i = 0; i < NUM_INVADERS; i++) {
        if (!invader_alive[i]) continue;
        
        invader_x[i] += invader_direction * 2;
        
        // Check if any invader hit the edge
        if (invader_x[i] <= 5 || invader_x[i] >= 120) {
            hit_edge = true;
        }
    }
    
    // If hit edge, reverse direction and move down
    if (hit_edge) {
        invader_direction = -invader_direction;
        for (int i = 0; i < NUM_INVADERS; i++) {
            if (invader_alive[i]) {
                invader_y[i] += 2;
                // Keep them in bounds
                if (invader_y[i] > 50) {
                    reset_game();  // Game over - reset
                }
            }
        }
    }
    
    // Move ship autonomously
    invader_move_counter++;
    if (invader_move_counter > 2) {
        invader_move_counter = 0;
        // Move ship toward nearest invader
        int8_t target_x = 64;
        for (int i = 0; i < NUM_INVADERS; i++) {
            if (invader_alive[i]) {
                target_x = invader_x[i];
                break;
            }
        }
        
        if (ship_x < target_x && ship_x < 120) {
            ship_x += 2;
        } else if (ship_x > target_x && ship_x > 5) {
            ship_x -= 2;
        }
    }
    
    // Check if all invaders are dead - reset game
    bool all_dead = true;
    for (int i = 0; i < NUM_INVADERS; i++) {
        if (invader_alive[i]) {
            all_dead = false;
            break;
        }
    }
    if (all_dead) {
        reset_game();
    }
}

// Render Space Invaders game
static void render_game(void) {
    static char display[8][22];
    
    // Initialize with spaces
    for (uint8_t row = 0; row < 8; row++) {
        for (uint8_t col = 0; col < 21; col++) {
            display[row][col] = ' ';
        }
        display[row][21] = '\0';
    }
    
    // Draw invaders (different characters for different rows)
    for (int i = 0; i < NUM_INVADERS; i++) {
        if (!invader_alive[i]) continue;
        
        uint8_t char_x = invader_x[i] / 6;
        uint8_t char_y = invader_y[i] / 8;
        
        if (char_x < 21 && char_y < 8) {
            // Use different characters for visual variety
            if (i < 4) {
                display[char_y][char_x] = 'W';  // Top row
            } else if (i < 8) {
                display[char_y][char_x] = 'M';  // Middle row
            } else {
                display[char_y][char_x] = 'V';  // Bottom row
            }
        }
    }
    
    // Draw bullet
    if (bullet_active) {
        uint8_t bul_char_x = bullet_x / 6;
        uint8_t bul_char_y = bullet_y / 8;
        if (bul_char_x < 21 && bul_char_y < 8) {
            display[bul_char_y][bul_char_x] = '|';
        }
    }
    
    // Draw ship at bottom
    uint8_t ship_char_x = ship_x / 6;
    uint8_t ship_char_y = ship_y / 8;
    if (ship_char_x < 21 && ship_char_y < 8) {
        display[ship_char_y][ship_char_x] = 'A';
    }
    
    // Render to OLED
    for (uint8_t row = 0; row < 8; row++) {
        oled_set_cursor(0, row);
        oled_write(display[row], false);
    }
}

// Simple layer display
static void render_layer(void) {
    oled_write_P(PSTR("Layer: "), false);
    
    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_P(PSTR("BASE\n"), false); break;
        case 1: oled_write_P(PSTR("LAYER 1\n"), false); break;
        case 2: oled_write_P(PSTR("LAYER 2\n"), false); break;
        case 3: oled_write_P(PSTR("LAYER 3\n"), false); break;
        default: oled_write_P(PSTR("?\n"), false); break;
    }
    oled_write_P(PSTR("\n"), false);
}

// Safe keycode to string - returns PROGMEM strings, no memory allocation
static const char* get_key_name(uint16_t keycode) {
    // Custom keycodes
    if (keycode == KC_CLAY) return PSTR("LAY");
    
    // Macros - QMK_MACRO_0 through QMK_MACRO_15
    if (keycode >= QK_MACRO && keycode <= QK_MACRO_MAX) {
        uint8_t macro_id = keycode - QK_MACRO;
        switch(macro_id) {
            case 0: return PSTR("MC0");
            case 1: return PSTR("MC1");
            case 2: return PSTR("MC2");
            case 3: return PSTR("MC3");
            case 4: return PSTR("MC4");
            case 5: return PSTR("MC5");
            case 6: return PSTR("MC6");
            case 7: return PSTR("MC7");
            case 8: return PSTR("MC8");
            case 9: return PSTR("MC9");
            case 10: return PSTR("M10");
            case 11: return PSTR("M11");
            case 12: return PSTR("M12");
            case 13: return PSTR("M13");
            case 14: return PSTR("M14");
            case 15: return PSTR("M15");
            default: return PSTR("MAC");
        }
    }
    
    // Letters A-Z
    if (keycode >= KC_A && keycode <= KC_Z) {
        switch(keycode) {
            case KC_A: return PSTR("A");
            case KC_B: return PSTR("B");
            case KC_C: return PSTR("C");
            case KC_D: return PSTR("D");
            case KC_E: return PSTR("E");
            case KC_F: return PSTR("F");
            case KC_G: return PSTR("G");
            case KC_H: return PSTR("H");
            case KC_I: return PSTR("I");
            case KC_J: return PSTR("J");
            case KC_K: return PSTR("K");
            case KC_L: return PSTR("L");
            case KC_M: return PSTR("M");
            case KC_N: return PSTR("N");
            case KC_O: return PSTR("O");
            case KC_P: return PSTR("P");
            case KC_Q: return PSTR("Q");
            case KC_R: return PSTR("R");
            case KC_S: return PSTR("S");
            case KC_T: return PSTR("T");
            case KC_U: return PSTR("U");
            case KC_V: return PSTR("V");
            case KC_W: return PSTR("W");
            case KC_X: return PSTR("X");
            case KC_Y: return PSTR("Y");
            case KC_Z: return PSTR("Z");
        }
    }
    
    // Numbers 0-9
    if (keycode >= KC_1 && keycode <= KC_9) {
        switch(keycode) {
            case KC_1: return PSTR("1");
            case KC_2: return PSTR("2");
            case KC_3: return PSTR("3");
            case KC_4: return PSTR("4");
            case KC_5: return PSTR("5");
            case KC_6: return PSTR("6");
            case KC_7: return PSTR("7");
            case KC_8: return PSTR("8");
            case KC_9: return PSTR("9");
        }
    }
    
    // Function keys F1-F24
    if (keycode >= KC_F1 && keycode <= KC_F24) {
        switch(keycode) {
            case KC_F1: return PSTR("F1");
            case KC_F2: return PSTR("F2");
            case KC_F3: return PSTR("F3");
            case KC_F4: return PSTR("F4");
            case KC_F5: return PSTR("F5");
            case KC_F6: return PSTR("F6");
            case KC_F7: return PSTR("F7");
            case KC_F8: return PSTR("F8");
            case KC_F9: return PSTR("F9");
            case KC_F10: return PSTR("F10");
            case KC_F11: return PSTR("F11");
            case KC_F12: return PSTR("F12");
            case KC_F13: return PSTR("F13");
            case KC_F14: return PSTR("F14");
            case KC_F15: return PSTR("F15");
            case KC_F16: return PSTR("F16");
            case KC_F17: return PSTR("F17");
            case KC_F18: return PSTR("F18");
            case KC_F19: return PSTR("F19");
            case KC_F20: return PSTR("F20");
            case KC_F21: return PSTR("F21");
            case KC_F22: return PSTR("F22");
            case KC_F23: return PSTR("F23");
            case KC_F24: return PSTR("F24");
        }
    }
    
    // Everything else
    switch(keycode) {
        // Special
        case KC_NO: return PSTR("XXX");
        case KC_TRNS: return PSTR("---");
        case KC_0: return PSTR("0");
        
        // Punctuation
        case KC_MINS: return PSTR("-");
        case KC_EQL: return PSTR("=");
        case KC_LBRC: return PSTR("[");
        case KC_RBRC: return PSTR("]");
        case KC_BSLS: return PSTR("\\");
        case KC_SCLN: return PSTR(";");
        case KC_QUOT: return PSTR("'");
        case KC_GRV: return PSTR("`");
        case KC_COMM: return PSTR(",");
        case KC_DOT: return PSTR(".");
        case KC_SLSH: return PSTR("/");
        
        // Whitespace & Control
        case KC_SPC: return PSTR("SPC");
        case KC_ENT: return PSTR("ENT");
        case KC_ESC: return PSTR("ESC");
        case KC_TAB: return PSTR("TAB");
        case KC_BSPC: return PSTR("BSP");
        case KC_DEL: return PSTR("DEL");
        case KC_INS: return PSTR("INS");
        
        // Navigation
        case KC_HOME: return PSTR("HOM");
        case KC_END: return PSTR("END");
        case KC_PGUP: return PSTR("PGU");
        case KC_PGDN: return PSTR("PGD");
        case KC_LEFT: return PSTR("LFT");
        case KC_DOWN: return PSTR("DWN");
        case KC_UP: return PSTR("UP");
        case KC_RGHT: return PSTR("RGT");
        
        // Modifiers
        case KC_LSFT: return PSTR("LSF");
        case KC_RSFT: return PSTR("RSF");
        case KC_LCTL: return PSTR("LCT");
        case KC_RCTL: return PSTR("RCT");
        case KC_LALT: return PSTR("LAL");
        case KC_RALT: return PSTR("RAL");
        case KC_LGUI: return PSTR("LGU");
        case KC_RGUI: return PSTR("RGU");
        
        // Locks
        case KC_CAPS: return PSTR("CAP");
        case KC_NUM: return PSTR("NUM");
        case KC_SCRL: return PSTR("SCR");
        
        // Numpad
        case KC_P0: return PSTR("P0");
        case KC_P1: return PSTR("P1");
        case KC_P2: return PSTR("P2");
        case KC_P3: return PSTR("P3");
        case KC_P4: return PSTR("P4");
        case KC_P5: return PSTR("P5");
        case KC_P6: return PSTR("P6");
        case KC_P7: return PSTR("P7");
        case KC_P8: return PSTR("P8");
        case KC_P9: return PSTR("P9");
        case KC_PDOT: return PSTR("P.");
        case KC_PSLS: return PSTR("P/");
        case KC_PAST: return PSTR("P*");
        case KC_PMNS: return PSTR("P-");
        case KC_PPLS: return PSTR("P+");
        case KC_PENT: return PSTR("PEN");
        
        // Media keys
        case KC_MUTE: return PSTR("MUT");
        case KC_VOLU: return PSTR("V+");
        case KC_VOLD: return PSTR("V-");
        case KC_MPLY: return PSTR("PLY");
        case KC_MSTP: return PSTR("STP");
        case KC_MNXT: return PSTR("NXT");
        case KC_MPRV: return PSTR("PRV");
        case KC_BRIU: return PSTR("BR+");
        case KC_BRID: return PSTR("BR-");
        
        // System
        case KC_PWR: return PSTR("PWR");
        case KC_PSCR: return PSTR("PSC");
        case KC_PAUS: return PSTR("PAU");
        case KC_APP: return PSTR("APP");
        
        // Mouse
        case MS_UP: return PSTR("MU");
        case MS_DOWN: return PSTR("MD");
        case MS_LEFT: return PSTR("ML");
        case MS_RGHT: return PSTR("MR");
        case MS_BTN1: return PSTR("MB1");
        case MS_BTN2: return PSTR("MB2");
        case MS_BTN3: return PSTR("MB3");
        
        // RGB Matrix
        case QK_RGB_MATRIX_ON: return PSTR("RON");
        case QK_RGB_MATRIX_OFF: return PSTR("ROF");
        case QK_RGB_MATRIX_TOGGLE: return PSTR("RGB");
        case QK_RGB_MATRIX_MODE_NEXT: return PSTR("MD+");
        case QK_RGB_MATRIX_MODE_PREVIOUS: return PSTR("MD-");
        case QK_RGB_MATRIX_HUE_UP: return PSTR("H+");
        case QK_RGB_MATRIX_HUE_DOWN: return PSTR("H-");
        case QK_RGB_MATRIX_SATURATION_UP: return PSTR("S+");
        case QK_RGB_MATRIX_SATURATION_DOWN: return PSTR("S-");
        case QK_RGB_MATRIX_VALUE_UP: return PSTR("V+");
        case QK_RGB_MATRIX_VALUE_DOWN: return PSTR("V-");
        case QK_RGB_MATRIX_SPEED_UP: return PSTR("SP+");
        case QK_RGB_MATRIX_SPEED_DOWN: return PSTR("SP-");
        
        // Layer switching
        case QK_MOMENTARY: return PSTR("M0");
        case QK_MOMENTARY+1: return PSTR("M1");
        case QK_MOMENTARY+2: return PSTR("M2");
        case QK_MOMENTARY+3: return PSTR("M3");
        case QK_TOGGLE_LAYER: return PSTR("T0");
        case QK_TOGGLE_LAYER+1: return PSTR("T1");
        case QK_TOGGLE_LAYER+2: return PSTR("T2");
        case QK_TOGGLE_LAYER+3: return PSTR("T3");
        
        // System
        case QK_BOOTLOADER: return PSTR("BOT");
        case QK_REBOOT: return PSTR("RST");
        case QK_CLEAR_EEPROM: return PSTR("CLR");
        
        default: return PSTR("???");
    }
}

// Dynamic keymap display - reads from VIA EEPROM
static void render_keys(void) {
    uint8_t layer = get_highest_layer(layer_state);
    
    #ifdef VIA_ENABLE
    // Show encoder 1: Button, CW, CCW
    oled_write_P(PSTR("E1:"), false);
    uint16_t e1_btn = dynamic_keymap_get_keycode(layer, 3, 0);
    oled_write_P(get_key_name(e1_btn), false);
    
    #ifdef ENCODER_MAP_ENABLE
    uint16_t e1_cw = dynamic_keymap_get_encoder(layer, 0, true);
    uint16_t e1_ccw = dynamic_keymap_get_encoder(layer, 0, false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(get_key_name(e1_ccw), false);
    oled_write_P(PSTR("/"), false);
    oled_write_P(get_key_name(e1_cw), false);
    #endif
    oled_write_P(PSTR("\n"), false);
    
    // Show encoder 2: Button, CW, CCW
    oled_write_P(PSTR("E2:"), false);
    uint16_t e2_btn = dynamic_keymap_get_keycode(layer, 4, 0);
    oled_write_P(get_key_name(e2_btn), false);
    
    #ifdef ENCODER_MAP_ENABLE
    uint16_t e2_cw = dynamic_keymap_get_encoder(layer, 1, true);
    uint16_t e2_ccw = dynamic_keymap_get_encoder(layer, 1, false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(get_key_name(e2_ccw), false);
    oled_write_P(PSTR("/"), false);
    oled_write_P(get_key_name(e2_cw), false);
    #endif
    oled_write_P(PSTR("\n\n"), false);
    
    // Show 3x3 key grid
    for (uint8_t row = 0; row < 3; row++) {
        for (uint8_t col = 0; col < 3; col++) {
            uint16_t keycode = dynamic_keymap_get_keycode(layer, row, col);
            const char* name = get_key_name(keycode);
            oled_write_P(name, false);
            if (col < 2) oled_write_P(PSTR(" "), false);
        }
        oled_write_P(PSTR("\n"), false);
    }
    #else
    // Fallback if VIA not enabled
    oled_write_P(PSTR("E1:LAY V-/V+\n"), false);
    oled_write_P(PSTR("E2:PLY PRV/NXT\n\n"), false);
    oled_write_P(PSTR("1 2 3\n"), false);
    oled_write_P(PSTR("4 5 6\n"), false);
    oled_write_P(PSTR("7 8 9\n"), false);
    #endif
}

bool oled_task_user(void) {
    uint32_t now = timer_read32();
    
    // Check if idle timeout reached
    if (now - last_input_time > IDLE_TIMEOUT) {
        if (!game_active) {
            game_active = true;
            last_game_update = now;
            oled_clear();
            reset_game();
        }
        update_game();
        render_game();
    } else {
        if (game_active) {
            game_active = false;
            oled_clear();
        }
        render_layer();
        render_keys();
    }
    
    return false;
}

// Track user activity to reset screensaver
void matrix_scan_user(void) {
    if (is_keyboard_master()) {
        static matrix_row_t matrix_last[MATRIX_ROWS] = {0};
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            matrix_row_t curr = matrix_get_row(row);
            if (curr != matrix_last[row]) {
                last_input_time = timer_read32();
                matrix_last[row] = curr;
            }
        }
    }
}

#endif  // OLED_ENABLE

// ============================================================================
// ENCODER CONTROL (must be outside #ifdef OLED_ENABLE)
// ============================================================================
bool encoder_update_user(uint8_t index, bool clockwise) {
    last_input_time = timer_read32();
    
    // Block encoder actions during game
    if (game_active) {
        return false;
    }
    
    return true;
}