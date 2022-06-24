/* Copyright 2022 Pascal Jaeger / Schievel https://github.com/Schievel1/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "tapdance.h"

enum custom_layers {
    _DVORAK,
    _LOWER,
    _RAISE,
};


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_5x6_right(
                         KC_GRV,     KC_1,    KC_2,    KC_3 ,    KC_4 ,    KC_5,                  KC_6    ,    KC_7 ,       KC_8 ,      KC_9 ,      KC_0        ,KC_EQL,
                         KC_TAB,     KC_QUOT, KC_COMM, KC_DOT  , KC_P    , KC_Y   ,               KC_F    ,    KC_G       , KC_C      , KC_R      , KC_L ,       KC_SLSH,
                         TD(ESC_TM), KC_A ,   KC_O   , KC_E    , KC_U    , KC_I   ,               KC_D    ,    KC_H       , KC_T      , KC_N      , KC_S        ,KC_MINS,
                         KC_NO,      KC_SCLN, KC_Q   , KC_J    , KC_K    , KC_X   ,               KC_B    ,    KC_M       , KC_W   ,    KC_V    ,   KC_Z     ,   KC_BSLS,
                                          KC_LBRC, KC_RBRC,                                                       KC_PGUP, KC_PGDN,
                                                            TD(SFT_TM),    KC_SPC,                 KC_RSFT,
                                                            TD(CTL_TM),    TD(LOW_TM),                     KC_BSPC,
                                                            TD(ALT_TM),    TD(GUI_TM),        KC_ENT, KC_RALT
                         ),

  [_LOWER] = LAYOUT_5x6_right(

                        KC_TILD,     KC_F1,    KC_F2,    KC_F3,         KC_F4,     KC_F5,        KC_F6,   KC_F7,     KC_F8,     KC_F9,       KC_F10,     KC_DEL ,
                        _______,    _______, _______,  MOMO,       CUSTOMM,   KC_LCBR,        KC_RCBR, KC_BTN2,   _______,   _______  ,   _______ ,   _______,
                        _______,    _______, _______,  TD(RAI_TM),     KC_DEL,   KC_LPRN,        KC_RPRN, KC_LEFT ,  KC_UP,     KC_DOWN,     KC_RGHT,    KC_PIPE,
                        KC_CAPS ,   _______, _______,  LCTL(KC_X), LCTL(KC_C),LCTL(KC_V),        _______, KC_BTN1  , _______,   _______,     _______,    _______,
                                           _______,_______,                                                       _______,_______,
                                                                 _______,_______,                         _______,
                                                                 _______,_______,                         _______,
                                                                 _______,_______,                 _______,_______
                        ),

  [_RAISE] = LAYOUT_5x6_right(

                        _______, RGB_TOG, _______, _______, _______, _______,                    _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_CALC,
                        RGB_HUI, RGB_HUD, _______, _______, _______, KC_LBRC,                    KC_RBRC, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_MUTE,
                        RGB_SAI, RGB_SAD, _______, _______, _______, KC_LPRN,                    KC_RPRN, KC_P4,   KC_P5,   KC_P6,   _______, KC_VOLU,
                        RGB_VAI, RGB_VAD, _______, _______, _______, _______,                    KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_VOLD,
                                           _______,_______,                                                         KC_DOT, KC_COMM,
                                                                 _______,_______,                     _______,
                                                                 _______,_______,                     _______,
                                                                 _______,_______,             _______,_______
                        ),
};

void matrix_init_user() {
  rgblight_setrgb(0,213,255);
}

void keyboard_post_init_user(void) {
  wait_ms(100);
  rgblight_setrgb(0,213,255);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:
            if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
                rgblight_setrgb(236, 72, 110);
            }
            else {
                rgblight_setrgb(149, 151, 204);
            }

            break;
        case _LOWER:
            rgblight_setrgb(55, 198, 192);
            break;
        default:
            rgblight_setrgb(0,213,255);
            break;
    }
  return state;
}