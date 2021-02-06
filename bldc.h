/*
 * bldc.h
 *
 * Created: 2021-01-23 20:44:28
 *  Author: Knalle
 */ 


#ifndef BLDC_H_
#define BLDC_H_

#include <avr/io.h>
#include "atmega1284p.h"

// ###############################################
// BLDC control pin			AVR pin
// ###############################################
// LOCK						PB0
// START/STOP				PB1
// CW/CCW					PB2
// BRAKE					PB3
// CLOCK					PB6

#define BLDC_MIN_RPM	45703
#define BLDC_MAX_RPM	6500

typedef struct bldc_control_t
{
	volatile uint8_t lock			: 1;	/**< Not sure, probably used to signal that the controller has reach the target rpm. */
	volatile uint8_t start_stop		: 1;	/**< Set high to stop. */
	volatile uint8_t cw_ccw			: 1;	/**< Set high for clockwise. */
	volatile uint8_t brake			: 1;	/**< Set low to brake. */
	volatile uint8_t reserved_1		: 1;	
	volatile uint8_t reserved_2		: 1;
	volatile uint8_t clock			: 1;	/**< Clock signal to control speed. From 500 Hz to 2.35 kHz. */
	volatile uint8_t reserved_3		: 1;	
} bldc_control_t;

typedef struct bldc_control_dir_t
{
	volatile uint8_t lock			: 1;
	volatile uint8_t start_stop		: 1;
	volatile uint8_t cw_ccw			: 1;
	volatile uint8_t brake			: 1;
	volatile uint8_t reserved_1		: 1;
	volatile uint8_t reserved_2		: 1;
	volatile uint8_t clock			: 1;
	volatile uint8_t reserved_3		: 1;
} bldc_control_dir_t;

void bldc_init(void);
void bldc_set_speed(uint16_t);
void bldc_start(void);


#endif /* BLDC_H_ */