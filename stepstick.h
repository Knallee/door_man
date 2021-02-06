/*
 * stepstick.h
 *
 * Created: 2021-01-24 00:07:53
 *  Author: Knalle
 */ 


#ifndef STEPSTICK_H_
#define STEPSTICK_H_

#include <avr/io.h>
#include "atmega1284p.h"

// ###############################################
// Stepstick pin			AVR pin
// ###############################################
// N_ENA					PA0
// MS1						PA1
// MS2						PA2
// MS3						PA3
// N_RST					PA4
// N_SLEEP					PA5
// DIR						PA6
// ###############################################


#define OUTPUT		(1)
#define INPUT		(0)



#define N_ENA		(0)
#define MS1			(1)
#define MS2			(2)
#define MS3			(3)
#define N_RST		(4)
#define N_SLEEP		(5)
#define DIR			(6)

// volatile uint8_t step		: 1;	/**< The motor steps at the positive flank. */

typedef struct stepstick_control_t {
	
	volatile uint8_t n_enable	: 1;	/**< Enables the driver when pulled low. */
	volatile uint8_t ms_res		: 3;	/**< Micro step resolution. */
	volatile uint8_t n_reset	: 1;	/**< Reset driver if pulled low. */
	volatile uint8_t n_sleep	: 1;	/**< Motor driver goes to sleep if pulled low. */
	volatile uint8_t dir		: 1;	/**< Control direction of the stepper motor. */
	volatile uint8_t reserved	: 1;
	
} stepstick_control_t;

typedef struct stepstick_data_dir_t {
	
	volatile uint8_t n_enable	: 1;
	volatile uint8_t ms_res		: 3;
	volatile uint8_t n_reset	: 1;
	volatile uint8_t n_sleep	: 1;
	volatile uint8_t dir		: 1;
	volatile uint8_t reserved	: 1;
	
} stepstick_data_dir_t;


void stepstick_init();

#endif /* STEPSTICK_H_ */