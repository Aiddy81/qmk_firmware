// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include <math.h>
#include <string.h>

// Define the number of rows and columns in your matrix
#define MATRIX_ROWS 3
#define MATRIX_COLS 3


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BUFFER_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 8)
static uint8_t framebuffer[BUFFER_SIZE];
static uint32_t lastInputTime = 0;
static bool booting = true;
static uint8_t bootPhase = 0;
static uint8_t time = 0;
static uint8_t frame = 0;

enum ThemeMode {
    THEME_NERDTISAN,
    THEME_ROBOT
};
static enum ThemeMode currentTheme = THEME_NERDTISAN;

enum custom_keycodes {
    TOGGLE_THEME = SAFE_RANGE,
};

//Pixel and Framebuffer Functions
void drawPixel(int x, int y) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) return;
    framebuffer[x + (y / 8) * SCREEN_WIDTH] |= (1 << (y % 8));
}

void clearBuffer() {
    memset(framebuffer, 0, BUFFER_SIZE);
}

//Logo Scroll-In and Scanline Flicker
extern const uint8_t nerdtisan_logo[]; // Your converted logo array

void drawLogoScrollIn(const uint8_t *logo, uint8_t offsetX) {
    for (int y = 0; y < 64; y++) {
        for (int x = 0; x < 128; x++) {
            if (x - offsetX >= 0 && x - offsetX < 128) {
                uint8_t byte = logo[(x - offsetX) + (y / 8) * 128];
                if (byte & (1 << (y % 8))) {
                    drawPixel(x, y);
                }
            }
        }
    }
}

void drawScanlineFlicker(uint8_t phase) {
    for (int y = 0; y < 64; y += 2) {
        if ((y + phase) % 4 == 0) {
            for (int x = 0; x < 128; x++) {
                drawPixel(x, y);
            }
        }
    }
}

//Idle Logo Pulse + Plasma
void drawLogoPulse(const uint8_t *logo, uint8_t phase) {
    for (int y = 0; y < 64; y++) {
        for (int x = 0; x < 128; x++) {
            uint8_t byte = logo[x + (y / 8) * 128];
            if (byte & (1 << (y % 8))) {
                if (((x + y + phase) % 6) < 3) {
                    drawPixel(x, y);
                }
            }
        }
    }
}

void drawPlasma(uint8_t t) {
    for (int y = 0; y < 64; y++) {
        for (int x = 0; x < 128; x++) {
            int value = (int)(sin(x * 0.1 + t * 0.1) + sin(y * 0.1 + t * 0.15)) * 127;
            if ((value & 0x80) == 0) {
                drawPixel(x, y);
            }
        }
    }
}


//Robot Silhouette and Scan Beam
extern const uint8_t robotFrames[6][16]; // Define your robot sprite frames

void drawRobotFrame(uint8_t frame, int x, int y) {
    for (int row = 0; row < 16; row++) {
        uint8_t line = robotFrames[frame][row];
        for (int col = 0; col < 8; col++) {
            if (line & (1 << col)) drawPixel(x + col, y + row);
        }
    }
}

void drawScanBeam(uint8_t angle) {
    float rad = angle * 3.14159 / 180.0;
    int x = 64 + (int)(60 * cos(rad));
    int y = 32 + (int)(30 * sin(rad));
    int dx = abs(x - 64), sx = 64 < x ? 1 : -1;
    int dy = -abs(y - 32), sy = 32 < y ? 1 : -1;
    int err = dx + dy;

    while (1) {
        drawPixel(64, 32);
        if (64 == x && 32 == y) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x += sx; }
        if (e2 <= dx) { err += dx; y += sy; }
    }
}

//Terminal Logs
void drawText(const char *text, int x, int y) {
    while (*text) {
        // Replace with your font renderer or use oled_write_char if using QMK OLED font
        oled_write_char(*text++, false);
    }
}

//Keypress Handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        lastInputTime = timer_read32();
        switch (keycode) {
            case TOGGLE_THEME:
                currentTheme = (currentTheme == THEME_NERDTISAN) ? THEME_ROBOT : THEME_NERDTISAN;
                return false;
        }
    }
    return true;
}


// Define layers
enum layers {
    _0,
    _1,
    _2
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        //KC_MUTE, KC_NO, KC_NO, // Encoder switches here
        KC_1, KC_2, KC_3, KC_4,
        KC_5, KC_6, KC_7, KC_8,
        KC_9
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Handle first encoder
    } else if (index == 1) {
        // Handle second encoder
    }
    return true;
}
//static void render_logo(void) {
//    static const char PROGMEM qmk_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//    };
//
//    oled_write_P(qmk_logo, false);
//}
//
//bool oled_task_user(void) {
//    render_logo();
//    return false;
//}

//#ifdef OLED_ENABLE
//bool oled_task_user(void) {
//    // Host Keyboard Layer Status
//    oled_write_P(PSTR("Layer: "), false);
//
//    switch (get_highest_layer(layer_state)) {
//        case _0:
//            oled_write_P(PSTR("Default\n"), false);
//            break;
//        case _1:
//            oled_write_P(PSTR("FN\n"), false);
//            break;
//        case _2:
//            oled_write_P(PSTR("ADJ\n"), false);
//            break;
//        default:
//            // Or use the write_ln shortcut over adding '\n' to the end of your string
//            oled_write_ln_P(PSTR("Undefined"), false);
//    }
//
//    // Host Keyboard LED Status
//    led_t led_state = host_keyboard_led_state();
//    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
//    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
//    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
//    
//    return false;
//}
//#endif




//Main OLED Render Loop
void oled_task_user(void) {
    clearBuffer();

    if (booting) {
        if (currentTheme == THEME_NERDTISAN) {
            drawLogoScrollIn(nerdtisan_logo, bootPhase);
            drawScanlineFlicker(bootPhase);
            drawText("System: Artisan Ready", 0, 56);
        } else {
            drawRobotFrame(bootPhase % 6, bootPhase * 2, 40);
            drawText("Servo array online", 0, 0);
            drawText("Matrix stable", 0, 10);
            drawText("Thermal sync OK", 0, 20);
        }
        oled_write_raw(framebuffer, sizeof(framebuffer));
        bootPhase++;
        if (bootPhase > 128) booting = false;
        return;
    }

    if (timer_elapsed32(lastInputTime) > 10000) {
        if (currentTheme == THEME_NERDTISAN) {
            drawLogoPulse(nerdtisan_logo, time);
            drawPlasma(time);
        } else {
            drawRobotFrame(time % 6, time % 128, 48);
            drawScanBeam(time * 5);
        }
    } else {
        if (currentTheme == THEME_NERDTISAN) {
            drawText("Layer: 1", 0, 0);
            drawText("Caps Lock: OFF", 0, 10);
        } else {
            drawText("Power: 98%", 0, 0);
            drawText("Core Temp: 42C", 0, 10);
        }
    }

    oled_write_raw(framebuffer, sizeof(framebuffer));
    time++;
}
