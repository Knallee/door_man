/*
 * door_man.h
 *
 * Created: 2021-01-18 21:14:54
 *  Author: Knalle
 */ 


#ifndef DOOR_MAN_H_
#define DOOR_MAN_H_


// ###############################################
//	Stepstick pin			AVR pin
// ###############################################
//	DIR						PB0
//	STEP					PB1
//	N_SLEEP					PD2
//	N_RST					PD3
//	MS1						PC0
//	MS2						PC1
//	MS3						PC6
//	N_ENABLE				PC7
// ###############################################


#define DIR						(0)
#define STEP					(1)
#define N_SLEEP					(2)
#define N_RST					(3)
#define MS1						(0)
#define MS2						(1)
#define MS3						(6)
#define N_ENABLE				(7)



typedef struct stepstick_control1 {
	
	volatile uint8_t dir		: 1;	/**< Control direction of the stepper motor. */
	volatile uint8_t step		: 1;	/**< The motor steps at the positive flank. */	
	volatile uint8_t reserved1	: 1;
	volatile uint8_t reserved2	: 1;
	volatile uint8_t reserved3	: 1;
	volatile uint8_t reserved4	: 1;
	volatile uint8_t reserved5	: 1;
	volatile uint8_t reserved6	: 1;
	
} stepstick_control1_t;

typedef struct stepstick_control2 {
	
	volatile uint8_t reserved1	: 1;
	volatile uint8_t reserved2	: 1;
	volatile uint8_t n_sleep	: 1;	/**< Motor driver goes to sleep if pulled low. */
	volatile uint8_t n_reset	: 1;	/**< Reset driver if pulled low. */
	volatile uint8_t reserved3	: 1;
	volatile uint8_t reserved4	: 1;
	volatile uint8_t reserved5	: 1;
	volatile uint8_t reserved6	: 1;
	
} stepstick_control2_t;

typedef struct stepstick_control3 {
	
	volatile uint8_t ms1		: 1;	/**< Micro step resolution 1. */
	volatile uint8_t ms2		: 1;	/**< Micro step resolution 2. */
	volatile uint8_t reserved3	: 1;
	volatile uint8_t reserved4	: 1;
	volatile uint8_t reserved5	: 1;
	volatile uint8_t reserved6	: 1;
	volatile uint8_t ms3		: 1;	/**< Micro step resolution 3. */
	volatile uint8_t n_enable	: 1;	/**< Enables the driver when pulled low. */
	
} stepstick_control3_t;

void door_man_data_dir();
void door_man_init();




#endif /* DOOR_MAN_H_ */