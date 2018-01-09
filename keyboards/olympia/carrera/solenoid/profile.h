#ifndef SOLENOID_PROFILE_H
#define SOLENOID_PROFILE_H

#include <stdbool.h>
#include <stdint.h>

#define EECONFIG_SOLENOID_PROFILE (uint16_t *)18

uint8_t solenoid_profile;

typedef union {
  uint16_t raw;
  struct {
    uint8_t dwell : 8;
    uint8_t mode : 4;
    bool invert : 1;
  };
} solenoid_config_t;

solenoid_config_t solenoid;

void solenoid_read_profile(void);

void solenoid_update_profile(void);

#endif
