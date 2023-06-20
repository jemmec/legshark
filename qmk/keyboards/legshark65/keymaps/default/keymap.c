// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_default(
        KC_ESCAPE,     KC_GRAVE,      KC_1,        KC_2,        KC_3,  KC_4,         KC_5,  KC_6,  KC_7,      KC_8,      KC_9,         KC_0,         KC_MINUS,        KC_EQUAL,         KC_DELETE,
        KC_NO,         KC_TAB,        KC_Q,        KC_W,        KC_E,  KC_R,         KC_T,  KC_Y,  KC_U,      KC_I,      KC_O,         KC_P,         KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_BACKSLASH,
        KC_CAPS_LOCK,  KC_TRNS,       KC_A,        KC_S,        KC_D,  KC_F,         KC_G,  KC_H,  KC_J,      KC_K,      KC_L,         KC_SEMICOLON, KC_QUOTE,        KC_NO,            KC_ENTER,
        KC_NO,         KC_LEFT_SHIFT, KC_Z,        KC_X,        KC_C,  KC_V,         KC_B,  KC_N,  KC_M,      KC_COMMA,  KC_DOT,       KC_SLASH,     KC_NO,           KC_UP,            KC_NO,
        KC_LEFT_CTRL,  KC_NO,         KC_LEFT_GUI, KC_LEFT_ALT, KC_NO, KC_BACKSPACE, KC_NO, KC_NO, KC_SPACE,  KC_NO,     KC_RIGHT_ALT, KC_RIGHT_GUI, KC_LEFT,         KC_DOWN,          KC_RIGHT
    )
};
