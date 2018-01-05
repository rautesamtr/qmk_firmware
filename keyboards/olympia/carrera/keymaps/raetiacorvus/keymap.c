/* Copyright 2017 Gabriel Rauter <rauter.gabriel@gmail.com>
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
#include "carrera.h"
#include <keymap_german.h>

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum my_keycodes {
  KC_R4_1 = SAFE_RANGE,
  KC_R4_2,
  KC_TGLA, //Invert Layers
  KC_NKRO,
  KC_RSET,
};

#define BAS 0 // Default
#define FNL 1 // FN Keys (Layer 1 1/2)
#define FAR 2 // Arrow Keys (Layer 2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BAS] = KEYMAP( /* Default */
  KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, DE_LESS, KC_DEL,                      \
  KC_TAB,   DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UE,   DE_PLUS,        KC_BSPC,    XXXXXXX, XXXXXXX, \
  KC_TGLA,   DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,   DE_AE,   DE_HASH,        KC_ENT,             KC_NKRO, \
  KC_LSFT,     DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,   /*RSFT=LSFT*/                   KC_R4_2, KC_R4_1, \
  KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                                  DE_ALGR,      KC_RCTL,                            KC_LCAP  \
),
[FNL] = KEYMAP( /* FN Keys */
  DE_CIRC, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,                      \
  _______,  KC_RSET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,    _______, _______, \
  _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,             _______, \
  _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  /*RSFT=LSFT*/                   _______, _______, \
  _______, _______,  _______,                            _______,                                 _______,      _______,                            _______  \
),
[FAR] = KEYMAP( /* Arrow Keys */
  RESET,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU,                      \
  _______,  _______, _______, _______, _______, _______, _______, KC_BSPC, KC_UP,  KC_DEL,  _______, _______, _______,        _______,    _______, _______, \
  _______,    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,       _______,             _______, \
  _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  /*RSFT=LSFT*/                   _______, _______, \
  _______, _______,  _______,                            _______,                                 _______,      _______,                            _______  \
)
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_R4_1:
      if (record->event.pressed) {
        layer_on(FNL);
      } else {
        layer_off(FNL);
      }
      led_set(host_keyboard_leds());
      return false; // Skip all further processing of this key
    case KC_R4_2:
      if (record->event.pressed) {
        layer_on(FAR);
        layer_on(FNL);
      } else {
        layer_off(FAR);
      }
      led_set(host_keyboard_leds());
      return false; // Skip all further processing of this key
    case KC_TGLA:
      if (record->event.pressed) {
        layer_invert(FNL);
        layer_invert(FAR);
      } else {
        layer_invert(FNL);
        layer_invert(FAR);
      }
      led_set(host_keyboard_leds());
      return false; // Skip all further processing of this key
    case KC_NKRO:
      if (record->event.pressed) {
        keymap_config.nkro = false;
      } else {
        keymap_config.nkro = true;
      }
    return false; // Skip all further processing of this key
    case KC_RSET:
      reset_keyboard();
  }
  return true;
}

void led_set_user(uint8_t usb_led) {
  if (3<<1 & layer_state) {
    PORTF &= ~(1<<4);
  } else {
    PORTF |= (1<<4);
  }
}
