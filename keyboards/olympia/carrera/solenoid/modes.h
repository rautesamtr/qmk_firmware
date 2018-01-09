#ifndef SOLENOID_MODES_H
#define SOLENOID_MODES_H

#include "./manual_mode.h"
#include "./auto_mode.h"
#include "./buzz_mode.h"

typedef enum {
  SOLENOID_MODE_OFF = 0,
  SOLENOID_MODE_MANUAL,
  SOLENOID_MODE_AUTO1,
  SOLENOID_MODE_AUTO2,
  SOLENOID_MODE_BUZZ,
  SOLENOID_NUM_MODES,
} SolenoidModus;

#endif
