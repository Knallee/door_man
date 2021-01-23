/*
 * door_man.c
 *
 * Created: 2021-01-18 21:13:43
 * Author : Knalle and Krille W
 */ 

#define F_CPU	16000000UL

#include <avr/io.h>
#include "atmega1284p.h"
#include "door_man.h"
#include "bldc.h"
#include <util/delay.h>

volatile stepstick_control_t *stepstick				= (volatile stepstick_control_t *) PORTA_ADDR;
volatile stepstick_data_dir_t *stepstick_data_dir	= (volatile stepstick_data_dir_t *) DDRA_ADDR;



int main(void)
{	
	door_man_init();
	    //test kw
    while (1) {
		
		
		_delay_us(1000);
		
    }
}

void door_man_init()
{
	
	stepstick_data_dir->n_enable	= OUTPUT;
	stepstick_data_dir->ms_res		= 0b111;
	stepstick_data_dir->n_reset		= OUTPUT;
	stepstick_data_dir->n_sleep		= OUTPUT;
	stepstick_data_dir->dir			= OUTPUT;
	

	
	
}

