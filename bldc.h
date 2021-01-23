/*
 * bldc.h
 *
 * Created: 2021-01-23 20:44:28
 *  Author: Knalle
 */ 


#ifndef BLDC_H_
#define BLDC_H_

typedef struct bldc_control_t
{
	volatile uint8_t lock			: 1;
	volatile uint8_t start_stop		: 1;
	volatile uint8_t cw_ccw			: 1;
	volatile uint8_t brake			: 1;
	volatile uint8_t reserved_1		: 1;	
	volatile uint8_t reserved_2		: 1;
	volatile uint8_t clock			: 1;
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
};



#endif /* BLDC_H_ */