/* Copyright 2018 Gabriel Rauter <rauter.gabriel@gmail.com>
 * Copyright 2018 @mtdjr (https://github.com/mtdjr) (original version)
 * see users/mtdjr/solenoid.h
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

#include "buzz_mode.h"

#include <timer.h>
#include <stdbool.h>
#include <stdint.h>
#include "./profile.h"
#include "./pins.h"

bool solenoid_buzz_on = false;
bool solenoid_buzz_buzzing = false;
uint16_t solenoid_buzz_start = 0;

void solenoid_buzz_mode_init (void) {
  solenoid_buzz_on = false;
  solenoid_buzz_buzzing = false;
  solenoid_buzz_start = 0;
}

void solenoid_buzz_mode_fire(void) {
  solenoid_buzz_on = true;
  solenoid_buzz_buzzing = true;
  solenoid_buzz_start = timer_read();
  solenoid_power(!solenoid.invert);
}

void solenoid_buzz_mode_stop(void) {
  solenoid_buzz_mode_init();
  solenoid_power(solenoid.invert);
}

void solenoid_buzz_mode_check(void) {
  if (!solenoid_buzz_buzzing) return;

  uint16_t elapsed = timer_elapsed(solenoid_buzz_start);

  if (elapsed > solenoid.dwell) {
    solenoid_buzz_start = timer_read() - (elapsed > solenoid.dwell);
    solenoid_buzz_on = !solenoid_buzz_on;
    solenoid_power(solenoid_buzz_on == !solenoid.invert);
    return;
  }
}

struct SolenoidMode solenoid_buzz_mode = {
  &solenoid_buzz_mode_init,
  &solenoid_buzz_mode_fire,
  &solenoid_buzz_mode_stop,
  &solenoid_buzz_mode_check
};
