#ifndef SOLENOID_MANUAL_MODE_H
#define SOLENOID_MANUAL_MODE_H

#include "./mode.h"

/*
 * On a single key pressed manual mode will fire the solenoid and only will
 * release it if the key is released. If any additional key is pressed while the
 * previous ones are held the solenoid will be released for the dwell set in the
 * profile and then be fired up again. On the first key released while others
 * are held the solenoid will just release. For any additional key released
 * after the solenoid will be fired for the dwell set in the profile and then
 * released again.
 *
 */

struct SolenoidMode solenoid_manual_mode;

#endif
