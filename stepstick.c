/*
 * stepstick.c
 *
 * Created: 2021-01-24 00:07:36
 *  Author: Knalle
 */ 


#include "stepstick.h"


volatile stepstick_control_t *stepstick				= (volatile stepstick_control_t *) PORTA_ADDR;
volatile stepstick_data_dir_t *stepstick_data_dir	= (volatile stepstick_data_dir_t *) DDRA_ADDR;


void stepstick_init() {
	
	stepstick_data_dir->n_enable	= OUTPUT;
	stepstick_data_dir->ms_res		= 0b111;
	stepstick_data_dir->n_reset		= OUTPUT;
	stepstick_data_dir->n_sleep		= OUTPUT;
	stepstick_data_dir->dir			= OUTPUT;
	stepstick->ms_res				= 0b110;
	timer1_init();
}



void stepstick_set_direction(uint8_t dir) {
	stepstick->dir		= dir;

}

void stepstick_start_stop(uint8_t start_stop) {
	stepstick->n_sleep	= start_stop;
	stepstick->n_enable = 0;
	stepstick->n_reset = 1;
	
}

void set_stepstick_speed(uint16_t stepstick_speed){
	stepstick_period = stepstick_speed;
	timer1_set_fast_pwm_period(stepstick_speed);
	timer1_set_fast_pwm_duty_cycle_ch_a(stepstick_speed>>1);
}

uint16_t get_stepstick_speed(){
	return stepstick_period;
}
