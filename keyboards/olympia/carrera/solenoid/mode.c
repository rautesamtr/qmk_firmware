#include "./mode.h"

#include <stdbool.h>
#include "./pins.h"

void do_nothing(void) {}

void solenoid_off_mode_init(void) {
  solenoid_power(false);
}

const struct SolenoidMode solenoid_off_mode = {&solenoid_off_mode_init, &do_nothing, &do_nothing, &do_nothing};
