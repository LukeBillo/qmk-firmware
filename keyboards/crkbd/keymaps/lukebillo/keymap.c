/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define RGB_LIGHTS_COUNT_TOTAL  12

#define BASE_LAYER              0
#define SYMBOL_LAYER            1
#define NUMBER_NAV_LAYER        2
#define FUNCTION_LAYER          3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_LAYER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SC_LSPO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, SC_RSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_BSPC
                                      //`--------------------------'  `--------------------------'

  ),

    [SYMBOL_LAYER] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------------.                    ,------------------------------------------------------------------------------------------------.
        KC_TAB,          KC_GRAVE,       LSFT(KC_8),  LSFT(KC_EQUAL),    LSFT(KC_1),     XXXXXXX,                            XXXXXXX,        KC_EQUAL,       KC_KP_MINUS,    KC_KP_SLASH,    LSFT(KC_5),     LSFT(KC_2),
  //|---------------+---------------+---------------+---------------+---------------+---------------+|                    |---------------+---------------+---------------+---------------+---------------+---------------+|
        SC_LSPO,        KC_NUHS,        LSFT(KC_7),    LSFT(KC_9),     LSFT(KC_LBRC),   KC_LBRC,                             KC_RBRC,      LSFT(KC_RBRC),    LSFT(KC_0),   LSFT(KC_SLASH),    KC_SCLN,    SC_RSPC,
  //|---------------+---------------+---------------+---------------+---------------+---------------+|                    |---------------+---------------+---------------+---------------+---------------+---------------+|
        KC_LCTL,        KC_NUBS,      LSFT(KC_NUBS),   LSFT(KC_4),     LSFT(KC_2),      XXXXXXX,                             XXXXXXX,      LSFT(KC_MINUS),  LSFT(KC_COMMA), LSFT(KC_DOT),    LSFT(KC_SCLN), XXXXXXX,
  //|---------------+---------------+---------------+---------------+---------------+---------------+|                    |---------------+---------------+---------------+---------------+---------------+---------------+|
                                                                                    KC_LALT, _______,  KC_SPC,     KC_ENT,   MO(3), KC_BSPC
                                                                                //`--------------------------'  `--------------------------'
  ),

    [NUMBER_NAV_LAYER] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------------.                   ,------------------------------------------------------------------------------------------------.
        KC_TAB,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                   KC_6,           KC_7,           KC_8,           KC_9,          KC_0,         KC_BSPC,
  //|---------------+---------------+---------------+---------------+---------------+---------------+|                   |---------------+---------------+---------------+---------------+---------------+---------------+|
        SC_LSPO,        KC_HOME,      LCTL(KC_LEFT),     KC_UP,      LCTL(KC_RIGHT),    KC_END,                                 XXXXXXX,        KC_BTN1,        KC_MS_U,       KC_BTN2,        KC_WH_U,       SC_RSPC,
  //|---------------+---------------+---------------+---------------+---------------+---------------+|                   |---------------+---------------+---------------+---------------+---------------+---------------+|
        KC_LCTL,        XXXXXXX,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       XXXXXXX,                                KC_PSCR,        KC_MS_L,        KC_MS_D,       KC_MS_R,        KC_WH_D,      KC_DELETE,
  //|---------------+---------------+---------------+---------------+---------------+---------------+|                   |---------------+---------------+---------------+---------------+---------------+---------------+|
                                                                                    KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_BSPC
                                                                                //`--------------------------'  `--------------------------'
  ),

    [FUNCTION_LAYER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

const rgblight_segment_t PROGMEM base_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, RGB_LIGHTS_COUNT_PER_SIDE, HSV_PURPLE }
);

const rgblight_segment_t PROGMEM symbols_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, RGB_LIGHTS_COUNT_PER_SIDE, HSV_WHITE }
);

const rgblight_segment_t PROGMEM numbers_nav_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, RGB_LIGHTS_COUNT_PER_SIDE, HSV_BLUE }
);

const rgblight_segment_t PROGMEM function_layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, RGB_LIGHTS_COUNT_PER_SIDE, HSV_RED }
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer_rgb,
    symbols_layer_rgb,
    numbers_nav_layer_rgb,
    function_layer_rgb
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE_LAYER));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, SYMBOL_LAYER));
    rgblight_set_layer_state(2, layer_state_cmp(state, NUMBER_NAV_LAYER));
    rgblight_set_layer_state(3, layer_state_cmp(state, FUNCTION_LAYER));
    return state;
}