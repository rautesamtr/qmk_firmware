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
#include "solenoid/solenoid.h"

extern bool process_solenoid_user(uint16_t keycode, keyrecord_t *record);

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  // enable led1
  DDRF |= (1<<4);

  solenoid_init();

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)
  solenoid_check();
  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware
  if (process_solenoid_user(keycode, record)) {
    if (record->event.pressed) {
      solenoid_fire();
      switch (keycode) {
        case SOLENOID_TOGGLE: solenoid_toggle_mode(); break;
        case SOLENOID_DWELL_PLUS: solenoid_dwell_increase(); break;
        case SOLENOID_DWELL_MINUS: solenoid_dwell_decrease(); break;
        case SOLENOID_INVERT: solenoid_toggle_invert(); break;
      }
    } else {
      solenoid_stop();
    }
  }
  return process_record_user(keycode, record);
}
