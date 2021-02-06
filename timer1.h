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
#define TIMER1_NO_PORT_OP			(0)
#define TIMER1_TOGGLE_ON_MATCH		(1)
#define TIMER1_CLEAR_ON_MATCH		(2)
#define TIMER1_SET_ON_MATCH			(3)

// Prescaler macros
#define TIMER1_PRESCALER_NO_CLK			(0)
#define TIMER1_PRESCALER_DIV1			(1)
#define TIMER1_PRESCALER_DIV8			(2)
#define TIMER1_PRESCALER_DIV64			(3)
#define TIMER1_PRESCALER_DIV256			(4)
#define TIMER1_PRESCALER_DIV1024		(5)
#define TIMER1_PRESCALER_EXT_CLK_FEDGE	(6)
#define TIMER1_PRESCALER_EXT_CLK_REDGE	(7)

// Wave generation mode macros for reg 3A
#define TIMER1_FAST_PWM_1A			(3)

// Wave generation mode macros for reg 3A
#define TIMER1_FAST_PWM_1B			(3)




typedef struct tccr1a_reg_t {
	
	volatile uint8_t wave_gen_mode_1a 	: 2;
	volatile uint8_t res				: 2;
	volatile uint8_t comp_match_b		: 2;	/**< Compare match behavior for channel B. */
	volatile uint8_t comp_match_c		: 2;	/**< Compare match behavior for channel A. */
	
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



#endif /* TIMER1_H_ */