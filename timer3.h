/*
 * timer3.h
 *
 * Created: 2021-01-23 20:51:52
 *  Author: Knalle
 */ 


#ifndef TIMER3_H_
#define TIMER3_H_

#include <avr/io.h>
#include "atmega1284p.h"

// Compare match behavior macros
#define TIMER3_NO_PORT_OP			(0)
#define TIMER3_TOGGLE_ON_MATCH		(1)
#define TIMER3_CLEAR_ON_MATCH		(2)
#define TIMER3_SET_ON_MATCH			(3)

// Prescaler macros
#define TIMER3_PRESCALER_NO_CLK			(0)
#define TIMER3_PRESCALER_DIV1			(1)
#define TIMER3_PRESCALER_DIV8			(2)
#define TIMER3_PRESCALER_DIV64			(3)
#define TIMER3_PRESCALER_DIV256			(4)
#define TIMER3_PRESCALER_DIV1024		(5)
#define TIMER3_PRESCALER_EXT_CLK_FEDGE	(6)
#define TIMER3_PRESCALER_EXT_CLK_REDGE	(7)

// Wave generation mode macros for reg 3A 
#define TIMER3_FAST_PWM_3A			(2)

// Wave generation mode macros for reg 3A
#define TIMER3_FAST_PWM_3B			(3)




typedef struct tccr3a_reg_t {
	
	volatile uint8_t wave_gen_mode_3a 	: 2;	/**< Wave generation mode. Two bits in the A reg and two in B. */
	volatile uint8_t res				: 2;
	volatile uint8_t comp_match_b		: 2;	/**< Compare match behavior for channel B. */	
	volatile uint8_t comp_match_a		: 2;	/**< Compare match behavior for channel A. */
	
} tccr3a_reg_t;

typedef struct tccr3b_reg_t {
	
	volatile uint8_t prescaler			: 3;	/**< Clock prescaler, Sets the increment frequency. */
	volatile uint8_t wave_gen_mode_3b	: 2;	/**< Wave generation mode. Two bits in the A reg and two in B. */
	volatile uint8_t res				: 1;
	volatile uint8_t input_cap_noise	: 1;	/**< Input Capture Noise Canceler. */
	volatile uint8_t input_cap_edge_sel : 1;	/**< Input Capture Edge Select. */
	
} tccr3b_reg_t;


typedef struct tccr3c_reg_t {
	
	volatile uint8_t res		: 6;
	volatile uint8_t foc3b		: 1;	/**<  Force Output Compare for Channel A. */
	volatile uint8_t foc3a		: 1;	/**<  Force Output Compare for Channel B. */
	
} tccr3c_reg_t;

void timer3_init();
void timer3_set_fast_pwm_period(uint16_t);
void timer3_set_fast_pwm_duty_cycle_ch_a(uint16_t);
void timer3_set_fast_pwm_duty_cycle_ch_b(uint16_t);


#endif /* TIMER3_H_ */