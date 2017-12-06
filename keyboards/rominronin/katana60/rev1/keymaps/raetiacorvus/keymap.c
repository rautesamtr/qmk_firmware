/* Copyright 2017 Gabriel Rauter, Baris Tosun
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
#include <keymap_german.h>

// Layer switch with tap
#define ST(LAYER) LT(LAYER, KC_SPACE)
#define ET(LAYER) LT(LAYER, KC_ESC)

// NAV keys
#define K_PRVWD LCTL(KC_LEFT)      // Previous word
#define K_NXTWD LCTL(KC_RIGHT)     // Next worde

enum layers {
    STD = 0,
    GAM,
    SYM,
    NAV,
    NUM,
    NUP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[STD] = LAYOUT( /* Base */
  KC_ESC,  DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    TG(NUP), DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT,
  KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    _______,          _______, DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
  ET(NAV), DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    KC_HOME,          KC_PGUP, DE_H,    DE_J,    DE_K,    DE_L,    DE_HASH, KC_ENT,
  KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    KC_END,  RESET,   KC_PGDN, DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
  MO(NUP), KC_LCTL, KC_LGUI, KC_LALT,                   ST(NUM), KC_ENT,  ST(SYM),          KC_LCTL, KC_RALT, KC_RALT, _______, MO(SYM)
    ),
[GAM] = LAYOUT( /* Game */
  KC_ESC,  DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    TG(NUP), DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT,
  KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    _______,          _______, DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC,
  ET(NUM), DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    KC_HOME,          KC_PGUP, DE_H,    DE_J,    DE_K,    DE_L,    DE_HASH, KC_ENT,
  KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    KC_END,  RESET,   KC_PGDN, DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
  KC_LCTL, XXXXXXX, XXXXXXX, KC_LALT,                   KC_SPC,  KC_ENT,  ST(SYM),          KC_ALGR, KC_DOWN, KC_UP,   KC_RGHT, MO(NUM)
    ),
[SYM] = LAYOUT(
  RESET,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, DE_AT,   DE_DEG,  DE_EURO, DE_SS,   _______, _______,          _______, _______, DE_UDIA, DE_QUES, DE_ODIA, DE_ASTR, KC_DEL,
  _______, DE_ADIA, DE_LCBR, DE_LBRC, DE_LPRN, DE_SLSH, KC_VOLD,          KC_VOLU, DE_TILD, DE_RPRN, DE_RBRC, DE_RCBR, DE_DQUO, _______,
  _______, DE_LABK, DE_RABK, DE_PIPE, _______, DE_BSLS, KC_MPRV, KC_MPLY, KC_MNXT, _______, DE_CIRC, DE_ACUT, DE_GRV,  DE_PLUS, _______,
  _______, _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    ),
[NAV] = LAYOUT(
  C(KC_ESC),  DF(STD), DF(GAM), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  C(KC_TAB),  C(DE_Q), C(DE_W), C(DE_E), C(DE_R), C(DE_T), _______,          _______, _______, K_PRVWD, KC_UP,   K_NXTWD, _______, _______,
  _______,    C(DE_A), C(DE_S), C(DE_D), C(DE_F), C(DE_G), _______,          _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______,
  C(KC_LSFT), C(DE_Z), C(DE_X), C(DE_C), C(DE_V), C(DE_B), _______, _______, _______, _______, KC_HOME, _______, KC_END,  _______, _______,
  _______, _______, _______, _______,                      _______, _______, _______,          _______, _______, _______, _______, _______
    ),
[NUM] = LAYOUT(
  KC_PWR,  KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    _______,          _______, DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    _______,
  _______, DE_EXLM, DE_DQUO, DE_SECT, DE_DLR,  DE_PERC, _______, _______, _______, DE_AMPR, DE_SLSH, DE_LPRN, DE_RPRN, DE_EQL,  _______,
  _______, _______, _______, _______,                   _______, _______, _______,          _______, _______, _______, _______, _______
    ),
[NUP] = LAYOUT(
  _______, TO(STD), TO(GAM), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_7,    KC_8,    KC_9,    _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  _______, KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PMNS, _______,          _______, _______, _______, _______, _______, _______, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_PAST, KC_PSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_0,    KC_PDOT, KC_PENT,                   _______, _______, _______,          _______, _______, _______, _______, _______
    )
};
