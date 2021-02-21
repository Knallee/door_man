/*
 * timer1.h
 *
 * Created: 2021-01-23 21:45:58
 *  Author: Knalle
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include <avr/io.h>
#include "atmega1284p.h"

// Compare match behavior macros
#define TIMER1_NO_PORT_OP			(0)		///< Normal port operation on OC1A/OC1B, for timer1
#define TIMER1_TOGGLE_ON_MATCH		(1)		///< Toggle OC1A/OC1B on compare match, for timer1
#define TIMER1_CLEAR_ON_MATCH		(2)		///< Clear OC1A/OC1B on compare match, for timer1
#define TIMER1_SET_ON_MATCH			(3)		///< Set OC1A/OC1B on compare match, for timer1

// Prescaler macros
#define TIMER1_PRESCALER_NO_CLK			(0)	///< Prescaler No clock, for timer1
#define TIMER1_PRESCALER_DIV1			(1)	///< No prescaler, clk, for timer1
#define TIMER1_PRESCALER_DIV8			(2)	///< Prescaler clk/8, for timer1
#define TIMER1_PRESCALER_DIV64			(3)	///< Prescaler clk/64, for timer1
#define TIMER1_PRESCALER_DIV256			(4)	///< Prescaler clk/256, for timer1
#define TIMER1_PRESCALER_DIV1024		(5)	///< Prescaler clk/1024, for timer1	
#define TIMER1_PRESCALER_EXT_CLK_FEDGE	(6)	///< External clock source on T1 pin, falling edge, for timer1
#define TIMER1_PRESCALER_EXT_CLK_REDGE	(7)	///< External clock source on T1 pin, rising edge, for timer1

// Wave generation mode macros for reg 1A
#define TIMER1_FAST_PWM_1A			(2)		///< Fast PWM on register OC1A, Wave generation macro

// Wave generation mode macros for reg 1A
#define TIMER1_FAST_PWM_1B			(3)		///< Fast PWM on register OC1B, Wave generation macro




typedef struct tccr1a_reg_t {
	
	volatile uint8_t wave_gen_mode_1a 	: 2;
	volatile uint8_t res				: 2;
	volatile uint8_t comp_match_b		: 2;	/**< Compare match behavior for channel B. */
	volatile uint8_t comp_match_a		: 2;	/**< Compare match behavior for channel A. */
	
} tccr1a_reg_t;

typedef struct tccr1b_reg_t {
	
	volatile uint8_t prescaler			: 3;
	volatile uint8_t wave_gen_mode_1b	: 2;
	volatile uint8_t res				: 1;
	volatile uint8_t input_cap_noise	: 1;
	volatile uint8_t input_cap_edge_sel : 1;
	
} tccr1b_reg_t;


typedef struct tccr1c_reg_t {
	
	volatile uint8_t res		: 6;
	volatile uint8_t foc1b		: 1;
	volatile uint8_t foc1a		: 1;
	
} tccr1c_reg_t;


/**
*	\brief Setups the necessary bits in the TCCR1A, TCCR1B, TCCR1C, registers
*	and initializes timer1 with defined settings
**/
void timer1_init();														
/**
*	\brief Sets the period for fast PWM on timer1
*	@param period is used to set which the period time
**/
void timer1_set_fast_pwm_period(uint16_t period);
/**
*	\brief Sets the duty cycle for fast PWM on timer1, channel A
*	@param duty_cycle is used to set which the period time
**/
void timer1_set_fast_pwm_duty_cycle_ch_a(uint16_t duty_cycle);
/**
*	\brief Sets the duty cycle for fast PWM on timer1, channel B
*	@param duty_cycle is used to set which the period time
**/
void timer1_set_fast_pwm_duty_cycle_ch_b(uint16_t duty_cycle);
/**
*	\brief Returns the set prescaler of timer1 as an integer. 
*	If no value has been put into the timer1 structs prescaler, it will return
*	1 as a default value.
**/
uint8_t timer1_get_prescaler();



#endif /* TIMER1_H_ */