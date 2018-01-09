#ifndef SOLENOID_AUTO_MODE_H
#define SOLENOID_AUTO_MODE_H

#include "./mode.h"

/*
 * Auto mode will fire the solenoid and release it after the set dwell value for
 * the profile. Auto mode 1 will only fire the solenoid on evey key pressed
 * while auto mode 2 will also fire it on a key released.
 *
 */

struct SolenoidMode solenoid_auto_mode1;
struct SolenoidMode solenoid_auto_mode2;

#endif
