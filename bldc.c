/*
 * bldc.c
 *
 * Created: 2021-01-23 20:44:42
 *  Author: Knalle
 */ 


#include "bldc.h"
#include "timer3.h"

volatile bldc_control_t *bldc_control = (volatile bldc_control_t *) PORTB_ADDR;
volatile bldc_control_dir_t *bldc_control_dir = (volatile bldc_control_dir_t *) DDRB_ADDR;


 void bldc_init()
 {
	 
	 bldc_control_dir->lock			= 0;
	 bldc_control_dir->start_stop	= 1;
	 bldc_control_dir->cw_ccw		= 1;
	 bldc_control_dir->brake		= 1;
	 bldc_control_dir->clock		= 1;
	 
	 // Initialize to stand still
	 bldc_control->start_stop	= 1;		// Stop
	 bldc_control->brake		= 1;		// No brake
	 bldc_control->cw_ccw		= 1;		// Clockwise		

	timer3_init();

 }
 
 void bldc_set_speed(uint16_t period)
 {
	 timer3_set_fast_pwm_period(period);
	 timer3_set_fast_pwm_duty_cycle_ch_a(period >> 1);
 }
 
 void bldc_start()
 {
	
	bldc_control->start_stop = 0;
	
 }