#ifndef SOLENOID_PINS_H
#define SOLENOID_PINS_H

#include <avr/io.h>

#define SOLENOID_PORT PORTB
#define SOLENOID_REGISTER DDRB
#define SOLENOID_PIN 0

#define solenoid_power(on) if (on) SOLENOID_PORT |= (1 << SOLENOID_PIN); \
                           else SOLENOID_PORT &= ~(1 << SOLENOID_PIN);   \

#define solenoid_is_up() (SOLENOID_PORT & (1 << SOLENOID_PIN))

#endif
