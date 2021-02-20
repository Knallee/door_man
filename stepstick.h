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
#include "timer1.h"
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


#define OUTPUT		(1)				///< Sets pin to act on output
#define INPUT		(0)				///<

#define STOP		(0)
#define START		(1)

#define N_ENA		(0)
#define MS1			(1)
#define MS2			(2)
#define MS3			(3)
#define N_RST		(4)
#define N_SLEEP		(5)
#define DIR			(6)

uint16_t stepstick_period;				/**< Controls the period time of the stepstick. */


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

/**
*	\brief Initializes the stepstick stepper circuit
**/
void stepstick_init();
/**
*	\brief Sets and changes direction of the step motor
*	@param dir is the desired direction
**/
void stepstick_set_direction(uint8_t dir);
/**
*	\brief Stops the stepstick circuit, and thus the also the motor
*	@param start_stop is the parameter to start or stop the engine. 
*	Use defined values START, STOP
**/
void stepstick_start_stop(uint8_t start_stop);

/**
*	\brief Returns the period time that sets the stepstick speed.
**/
uint16_t get_stepstick_speed();
/**
*	\brief Sets the period time that controls the stepstick speed.
*	@param is the value of the period time.
**/
void set_stepstick_speed(uint16_t stepstick_speed);


#endif /* STEPSTICK_H_ */