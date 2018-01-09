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

#include "auto_mode.h"

#include <timer.h>
#include <stdbool.h>
#include <stdint.h>
#include "./profile.h"
#include "./pins.h"

bool solenoid_auto_on = false;
uint16_t solenoid_auto_start = 0;

void solenoid_auto_mode_init (void) {
  solenoid_auto_on = false;
  solenoid_auto_start = 0;
}

void solenoid_auto_mode_fire(void) {
  if (!solenoid_auto_on) {
    solenoid_auto_on = true;
    solenoid_auto_start = timer_read();
    solenoid_power(!solenoid.invert);
  }
}

void solenoid_auto_mode_check(void) {
  uint16_t elapsed = 0;

  if (!solenoid_auto_on) return;

  elapsed = timer_elapsed(solenoid_auto_start);

  if (elapsed > solenoid.dwell) {
    solenoid_power(solenoid.invert);
    solenoid_auto_on = false;
  }
}

struct SolenoidMode solenoid_auto_mode1 = {
  &solenoid_auto_mode_init,
  &solenoid_auto_mode_fire,
  &do_nothing,
  &solenoid_auto_mode_check
};

struct SolenoidMode solenoid_auto_mode2 = {
  &solenoid_auto_mode_init,
  &solenoid_auto_mode_fire,
  &solenoid_auto_mode_fire,
  &solenoid_auto_mode_check
};
