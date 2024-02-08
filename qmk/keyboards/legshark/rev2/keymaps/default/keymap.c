// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define DFT 0 //Default layer (QWERTY)
#define FNC 1 //Function layer
#define MCR 2 //Macro layer

enum custom_keycodes {
    LS_DKTP = SAFE_RANGE,
    LS_OCMD,
    LS_PUSH,
    LS_PULL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode){
        //Opens windows desktops when key is held
        case LS_DKTP :
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_TAB);
                unregister_code(KC_LGUI);
            } else {
                tap_code(KC_ESC);
            }
            break;
        //Open cmd prompt
        case LS_OCMD :
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_R);
                unregister_code(KC_LGUI);
                SEND_STRING("cmd");
                tap_code(KC_ENT);
            }
            break;
        //type "git push" and enter
        case LS_PUSH :
            if (record->event.pressed) {
                SEND_STRING("git push");
                tap_code(KC_ENT);
            }
            break;
        //type "git pull" and enter
        case LS_PULL :
            if (record->event.pressed) {
                SEND_STRING("git pull");
                tap_code(KC_ENT);
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DFT] = LAYOUT_default(
        KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,
        KC_NO,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_NO,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,
        KC_NO,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT, LS_DKTP,
        KC_NO,   KC_LCTL, KC_LGUI, KC_LALT, MO(MCR), KC_TRNS, KC_BSPC, KC_TRNS, KC_SPC,  KC_TRNS, MO(FNC), KC_LEFT, KC_DOWN, KC_RGHT, KC_NO
    ),
    [FNC] = LAYOUT_default(
        KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
    ),
    [MCR] = LAYOUT_default(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        LS_PUSH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        LS_PULL, KC_TRNS, KC_TRNS, KC_TRNS, LS_OCMD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
    )
};