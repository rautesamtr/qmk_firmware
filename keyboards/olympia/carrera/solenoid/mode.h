#ifndef SOLENOID_MODE_H
#define SOLENOID_MODE_H

/*
 * Interface for a solenoid mode
 *
 * init - called when switching to the mode, a good place to reset variables
 * fire - called on key press
 * stop - called on key release
 * check - called on every matrix scan
 *
 * If you don't need one of the hooks set it to &do_nothing. See auto_mode1 as
 * an example of a mode that doesn't need stop.
 *
 */

typedef struct SolenoidMode {
  void (* init)(void);
  void (* fire)(void);
  void (* stop)(void);
  void (* check)(void);
} SolenoidMode;

void do_nothing(void);

/*
 * Off mode is an implementation of the solenoid mode interface with &do_nothing
 * set for every function pointer.
 *
 */
const struct SolenoidMode solenoid_off_mode;

#endif
