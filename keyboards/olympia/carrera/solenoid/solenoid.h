#ifndef SOLENOID_H
#define SOLENOID_H

#include <stdbool.h>
#include <stdint.h>
#include "./modes.h"
#include "./keycodes.h"

#define SOLENOID_MAX_DWELL 255

void solenoid_fire(void);
void solenoid_stop(void);
void solenoid_check(void);
void solenoid_switch_mode(SolenoidModus mode);
void solenoid_toggle_mode(void);
void solenoid_toggle_invert(void);
void solenoid_dwell_decrease(void);
void solenoid_dwell_increase(void);
void solenoid_dwell_set(uint8_t dwell);
void solenoid_switch_profile (uint8_t profile);
uint8_t solenoid_current_profile(void);
void solenoid_init(void);

#endif
