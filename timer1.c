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