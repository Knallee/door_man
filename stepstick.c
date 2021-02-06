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
	
}