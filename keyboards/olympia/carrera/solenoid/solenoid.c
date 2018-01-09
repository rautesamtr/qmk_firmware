#include "solenoid.h"

#include "./modes.h"
#include "./pins.h"
#include "./profile.h"

const SolenoidMode *solenoid_modes[SOLENOID_NUM_MODES] = {
  [SOLENOID_MODE_OFF] = &solenoid_off_mode,
  [SOLENOID_MODE_MANUAL] = &solenoid_manual_mode,
  [SOLENOID_MODE_AUTO1] = &solenoid_auto_mode1,
  [SOLENOID_MODE_AUTO2] = &solenoid_auto_mode2,
  [SOLENOID_MODE_BUZZ] = &solenoid_buzz_mode,
};

void solenoid_fire(void) {
  solenoid_modes[solenoid.mode]->fire();
}

void solenoid_stop(void) {
  solenoid_modes[solenoid.mode]->stop();
}

void solenoid_check(void) {
  solenoid_modes[solenoid.mode]->check();
}

void solenoid_switch_mode(SolenoidModus mode) {
  solenoid.mode = mode % SOLENOID_NUM_MODES;
  solenoid_update_profile();
  solenoid_power(solenoid.invert);
  solenoid_modes[solenoid.mode]->init();
}

void solenoid_toggle_mode(void) {
  solenoid_switch_mode((++solenoid.mode) % SOLENOID_NUM_MODES);
}

void solenoid_toggle_invert(void) {
  solenoid.invert = !solenoid.invert;
  solenoid_update_profile();
}

void solenoid_dwell_decrease(void) {
  if (solenoid.dwell > 0) {
    solenoid.dwell--;
    solenoid_update_profile();
  }
}

void solenoid_dwell_increase(void) {
  if (solenoid.dwell < SOLENOID_MAX_DWELL) {
    solenoid.dwell++;
    solenoid_update_profile();
  }
}

void solenoid_dwell_set(uint8_t dwell) {
  solenoid.dwell = dwell;
  solenoid_update_profile();
}

void solenoid_switch_profile(uint8_t profile) {
  solenoid_profile = profile;
  solenoid_read_profile();
  solenoid_switch_mode(solenoid.mode);
}

uint8_t solenoid_current_profile(void) {
  return solenoid_profile;
}

void solenoid_init(void) {
  SOLENOID_REGISTER |= (1 << SOLENOID_PIN);
  solenoid_switch_profile(0);
}
