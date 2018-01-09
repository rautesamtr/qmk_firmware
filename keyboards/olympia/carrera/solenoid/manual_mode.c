#include "manual_mode.h"

#include <timer.h>
#include <stdbool.h>
#include <stdint.h>
#include "./profile.h"
#include "./pins.h"

#if defined(SOLENOID_MANUAL_MODE_REFIRE_DELAY) || defined(SOLENOID_MANUAL_MODE_RESTOP_DELAY)

#ifndef SOLENOID_MANUAL_MODE_REFIRE_DELAY
#define SOLENOID_MANUAL_MODE_REFIRE_DELAY 0
#endif

#ifndef SOLENOID_MANUAL_MODE_RESTOP_DELAY
#define SOLENOID_MANUAL_MODE_RESTOP_DELAY 0
#endif

#define solenoid_delay(refire) ((refire) ? solenoid.dwell + SOLENOID_MANUAL_MODE_REFIRE_DELAY \
                               : solenoid.dwell + SOLENOID_MANUAL_MODE_RESTOP_DELAY)
#else

#define solenoid_delay(refire) solenoid.dwell

#endif

uint8_t solenoid_manual_count = 0;
bool solenoid_manual_just_release = false;
bool solenoid_manual_refire = false;
bool solenoid_manual_restop = false;
uint16_t solenoid_manual_refire_start = 0;
uint16_t solenoid_manual_restop_start = 0;

void solenoid_manual_mode_init(void) {
  solenoid_manual_count = 0;
  solenoid_manual_just_release = false;
  solenoid_manual_refire = false;
  solenoid_manual_restop = false;
  solenoid_manual_refire_start = 0;
  solenoid_manual_restop_start = 0;
}

void solenoid_manual_mode_fire(void) {
  solenoid_manual_count++;
  solenoid_manual_just_release = true;

  if (solenoid_manual_count > 1) {
    solenoid_power(solenoid.invert);
    solenoid_manual_refire = true;
    solenoid_manual_refire_start = timer_read();
  } else {
    solenoid_power(!solenoid.invert);
  }
}

void solenoid_manual_mode_stop(void) {
  if (solenoid_manual_count < 1) return;

  solenoid_manual_count--;

  if (!solenoid_manual_just_release) {
    solenoid_power(!solenoid.invert);
    solenoid_manual_restop = true;
    solenoid_manual_restop_start = timer_read();
  } else {
    solenoid_manual_just_release = false;
    solenoid_power(solenoid.invert);
  }
}

void solenoid_manual_mode_check(void) {
  uint16_t elapsed = 0;

  if (solenoid_manual_refire) {
    if (solenoid_is_up() == !solenoid.invert) {
      solenoid_manual_refire = false;
      return;
    }
    elapsed = timer_elapsed(solenoid_manual_refire_start);
    if (elapsed > solenoid_delay(!solenoid.invert)) {
      solenoid_power(!solenoid.invert);
      solenoid_manual_refire = false;
    }
  }

  if (solenoid_manual_restop) {
    if (solenoid_is_up() == solenoid.invert) {
      solenoid_manual_restop = false;
      return;
    }
    elapsed = timer_elapsed(solenoid_manual_restop_start);
    if (elapsed > solenoid_delay(solenoid.invert)) {
      solenoid_power(solenoid.invert);
      solenoid_manual_restop = false;
    }
  }
}

struct SolenoidMode solenoid_manual_mode = {
  &solenoid_manual_mode_init,
  &solenoid_manual_mode_fire,
  &solenoid_manual_mode_stop,
  &solenoid_manual_mode_check
};
