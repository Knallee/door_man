/*
 * timer1.c
 *
 * Created: 2021-01-24 00:16:47
 *  Author: Knalle
 */ 

#include "timer1.h"

volatile tccr1a_reg_t *timer1_control_reg_a	= (volatile tccr1a_reg_t *) TCCR1A_ADDR;
volatile tccr1b_reg_t *timer1_control_reg_b	= (volatile tccr1b_reg_t *) TCCR1B_ADDR;
volatile tccr1c_reg_t *timer1_control_reg_c	= (volatile tccr1c_reg_t *) TCCR1C_ADDR;



void timer1_init() {
		timer1_control_reg_a->comp_match_a		= TIMER1_CLEAR_ON_MATCH;
		timer1_control_reg_a->wave_gen_mode_1a	= TIMER1_FAST_PWM_1A;
		
		timer1_control_reg_b->prescaler			= TIMER1_PRESCALER_DIV1;
		timer1_control_reg_b->wave_gen_mode_1b	= TIMER1_FAST_PWM_1B;
		// Set OC-pin to an output
		DDRD |= (1 << PORTD5); 
}

void timer1_set_fast_pwm_period(uint16_t period)
{
	ICR1 = period;
}


void timer1_set_fast_pwm_duty_cycle_ch_a(uint16_t duty_cycle)
{
	OCR1A = duty_cycle;
}

void timer1_set_fast_pwm_duty_cycle_ch_b(uint16_t duty_cycle)
{
	OCR1B = duty_cycle;
}

uint8_t timer1_get_prescaler(){
	switch(timer1_control_reg_b->prescaler){
		case TIMER1_PRESCALER_DIV1:
			return 1;
			break;
		case TIMER1_PRESCALER_DIV8:
			return 8;
			break;
		case TIMER1_PRESCALER_DIV64:
			return 64;
			break;
		case TIMER1_PRESCALER_DIV256:
			return 256;
			break;
		case TIMER1_PRESCALER_DIV1024:
			return 1024;
			break;
		default:
			return 1;
	}
	return 1;
}