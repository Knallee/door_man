/*
 * door_man.c
 *
 * Created: 2021-01-18 21:13:43
 * Author : Knalle and Krille W
 */ 

#include <avr/io.h>
#include "atmega1284p.h"
#include "door_man.h"

volatile stepstick_control1_t *st_control1 = (volatile stepstick_control1_t *) PORTB_ADDR;
volatile stepstick_control2_t *st_control2 = (volatile stepstick_control2_t *) PORTD_ADDR;
volatile stepstick_control3_t *st_control3 = (volatile stepstick_control3_t *) PORTC_ADDR;

int main(void)
{	
	door_man_init();
	    
    while (1) {
		
    }
}

void door_man_init()
{
	door_man_data_dir();
	
	st_control1->dir		= 1;
	st_control1->step		= 1;
	st_control2->n_sleep	= 1;
	st_control2->n_reset	= 1;
	st_control3->ms1		= 1;
	st_control3->ms2		= 1;
	st_control3->ms3		= 1;
	st_control3->n_enable	= 1;
	
	
}

void door_man_data_dir() 
{
	
	DDRB |= (1 << DIR)		| (1 << STEP);
	DDRD |= (1 << N_SLEEP)	| (1 << N_RST);
	DDRC |= (1 << MS1)		| (1 << MS2) | (1 << MS3) | (1 << N_ENABLE); 
	
}