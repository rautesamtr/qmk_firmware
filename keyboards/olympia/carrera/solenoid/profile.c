#include "profile.h"
#include "eeprom.h"

uint8_t solenoid_profile = 0;

void solenoid_read_profile(void) {
  solenoid.raw = eeprom_read_word(EECONFIG_SOLENOID_PROFILE + solenoid_profile * 2);
}

void solenoid_update_profile(void) {
  eeprom_update_word(EECONFIG_SOLENOID_PROFILE + solenoid_profile * 2, solenoid.raw);
}
