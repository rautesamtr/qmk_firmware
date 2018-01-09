#ifndef SOLENOID_BUZZ_MODE_H
#define SOLENOID_BUZZ_MODE_H

#include "./mode.h"

/*
 * In buzz mode the solenoid will be fired on any key pressed and while at least
 * one key is held down it will switch between being fired and being released
 * for the dwell set in the profile.
 *
 */

struct SolenoidMode solenoid_buzz_mode;

#endif
