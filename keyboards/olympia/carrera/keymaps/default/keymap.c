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
#include "solenoid/solenoid.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum my_keycodes {
  KC_R2_1 = SAFE_RAGE,
  KC_R2_2,
  KC_R4_1,
  KC_R4_2,
  KC_TGLA,
  KC_NKRO,
};

#define QWE 0 // QWERTZ Base Layer
#define COL 1 // Colemak inspired Base Layer
#define NEO 2 // Neo Layer 1 inspired Base Layer
#define FNL 3 // FN Keys (Layer 2)
#define FAR 4 // FN and Arrow Keys (Layer 1 1/2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWE] = KEYMAP( /* QWERTZ Base Layer */
  KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_DEL,  KC_BSPC,                      \
  KC_TAB,   DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UE,   DE_PLUS,         DE_LESS,    KC_R4_2, KC_R4_1, \
  KC_TGLA,   DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,   DE_AE,   DE_HASH,         KC_ENT,             KC_NKRO, \
  KC_LSFT,     DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,   /*RSFT=LSFT*/                    KC_R2_2, KC_R2_1, \
  KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                                  KC_ALGR,      KC_RCTL,                             KC_LCAP  \
),
[COL] = KEYMAP( /* Colemak Base Layer */
  KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_DEL,  KC_BSPC,                      \
  KC_TAB,   DE_Q,    DE_W,    DE_F,    DE_P,    DE_G,    DE_J,    DE_L,    DE_U,    DE_Z,    DE_OE,   DE_UE,   DE_PLUS,         DE_LESS,    KC_R4_2, KC_R4_1, \
  KC_TGLA,   DE_A,    DE_R,    DE_S,    DE_T,    DE_D,    DE_H,    DE_N,    DE_E,    DE_I,    DE_O,    DE_AE,   DE_HASH,         KC_ENT,             KC_NKRO, \
  KC_LSFT,     DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_K,    DE_M,    DE_COMM, DE_DOT,  DE_MINS,   /*RSFT=LSFT*/                    KC_R2_2, KC_R2_1, \
  KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                                  KC_ALGR,      KC_RCTL,                             KC_LCAP  \
),
[NEO] = KEYMAP( /* Neo Base Layer */
  KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_MINS, DE_ACUT, KC_DEL,  KC_BSPC,                      \
  KC_TAB,   DE_X,    DE_V,    DE_L,    DE_C,    DE_W,    DE_K,    DE_H,    DE_G,    DE_F,    DE_Q,    DE_SS,   DE_HASH,         DE_LESS,    KC_R4_2, KC_R4_1, \
  KC_TGLA,   DE_U,    DE_I,    DE_A,    DE_E,    DE_O,    DE_S,    DE_N,    DE_R,    DE_T,    DE_D,    DE_Y,    DE_PLUS,         KC_ENT,             KC_NKRO, \
  KC_LSFT,     DE_UE,   DE_OE,   DE_AE,   DE_P,    DE_Z,    DE_B,    DE_M,    DE_COMM, DE_DOT,  DE_J,      /*RSFT=LSFT*/                    KC_R2_2, KC_R2_1, \
  KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                                  KC_ALGR,      KC_RCTL,                             KC_LCAP  \
),
[FNL] = KEYMAP( /* FN Keys */
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,   KC_F14,                     \
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______,   _______, _______, \
  _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,            _______, \
  _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  /*RSFT=LSFT*/                   _______, _______, \
  _______, _______,  _______,                            _______,                                 _______,      _______,                            _______  \
),
[FAR] = KEYMAP( /* Arrow Keys */
  DE_CIRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU,                     \
  _______,  KC_SOP0, KC_SOP1, KC_SOP2, _______, _______, _______, KC_BSPC, KC_UP,   KC_DEL,  _______, _______, KC_SDP,        _______,    _______, _______, \
  _______,   _______, KC_STOG, KC_SOIN, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  _______, _______,         RESET,             _______, \
  _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_SDM,  /*RSFT=LSFT*/                   _______, _______, \
  _______, _______,  _______,                            _______,                                 _______,      _______,                            _______  \
)
};

bool process_solenoid_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_NO:
    case KC_R2_1:
    case KC_R2_2:
    case KC_R4_1:
    case KC_R4_2:
    case KC_NKRO:
    case KC_LCAP: return false;
    default: return true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_R2_1:
      if (record->event.pressed) {
        layer_on(FNL);
      } else {
        if (!layer_state_is(FAR)) layer_off(FNL);
      }
      led_set(host_keyboard_leds());
      return false; // Skip all further processing of this key
    case KC_R2_2:
      if (record->event.pressed) {
        layer_on(FAR);
        layer_on(FNL);
      } else {
        layer_off(FAR);
      }
      led_set(host_keyboard_leds());
      return false; // Skip all further processing of this key
    case KC_R4_1:
      if (record->event.pressed) {
        layer_move(COL);
      } else {
        if (!layer_state_is(NEO)) layer_move(QWE);
      }
      led_set(host_keyboard_leds());
      return false; // Skip all further processing of this key
    case KC_R4_2:
      if (record->event.pressed) {
        layer_move(NEO);
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
      break;
    case KC_NKRO:
      keymap_config.nkro = !keymap_config.nkro;
      return false; // Skip all further processing of this key
    case KC_SOP0:
      if (record->event.pressed) {
        solenoid_switch_profile(0);
      }
      break;
    case KC_SOP1:
      if (record->event.pressed) {
        solenoid_switch_profile(1);
      }
      break;
    case KC_SOP2:
      if (record->event.pressed) {
        solenoid_switch_profile(2);
      }
      break;
  }
  return true;
}

bool led_update_user(led_t led_state) {
  if (3<<3 & layer_state) {
    PORTF &= ~(1<<4);
  } else {
    PORTF |= (1<<4);
  }
  return true;
}
