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
#include "timer3.h"
#include "stepstick.h"
#include <util/delay.h>

//volatile stepstick_control_t *stepstick				= (volatile stepstick_control_t *) PORTA_ADDR;
//volatile stepstick_data_dir_t *stepstick_data_dir	= (volatile stepstick_data_dir_t *) DDRA_ADDR;


uint16_t period = BLDC_MAX_RPM;

int main(void)
{	
	
	door_man_init();
	    //test kw
    while (1) {
		bldc_set_speed(period);
		

		
    }
}

void door_man_init()
{
	
	stepstick_init();
	bldc_init();
	
	bldc_start();
	
}





