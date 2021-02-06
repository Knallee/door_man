/*
 * timer3.c
 *
 * Created: 2021-01-24 00:02:31
 *  Author: Knalle
 */ 

#include "timer3.h"

volatile tccr3a_reg_t *timer3_control_reg_a	= (volatile tccr3a_reg_t *) TCCR3A_ADDR;
volatile tccr3b_reg_t *timer3_control_reg_b	= (volatile tccr3b_reg_t *) TCCR3B_ADDR;
volatile tccr3c_reg_t *timer3_control_reg_c	= (volatile tccr3c_reg_t *) TCCR3C_ADDR;

void timer3_init() {
	
	timer3_control_reg_a->comp_match_a		= TIMER3_CLEAR_ON_MATCH;
	timer3_control_reg_a->wave_gen_mode_3a	= TIMER3_FAST_PWM_3A;
	
	timer3_control_reg_b->prescaler			= TIMER3_PRESCALER_DIV1;
	timer3_control_reg_b->wave_gen_mode_3b	= TIMER3_FAST_PWM_3B;
	
	// Set OC-pin to an output
	DDRB |= (1 << PORTB6);
	
}


void timer3_set_fast_pwm_period(uint16_t period) 
{
	ICR3 = period;
}


void timer3_set_fast_pwm_duty_cycle_ch_a(uint16_t duty_cycle)
{
	OCR3A = duty_cycle;
}

void timer3_set_fast_pwm_duty_cycle_ch_b(uint16_t duty_cycle)
{
	OCR3B = duty_cycle;
}