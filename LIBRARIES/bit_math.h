#ifndef  __BIT_MATH_H__
#define __BIT_MATH_H__ 
    
typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F

}PORT_t; 

typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15,
	PIN_16,
	PIN_17,
	PIN_18,
	PIN_19,
	PIN_20,
	PIN_21,
	PIN_22,
	PIN_23,
	PIN_24,
	PIN_25,
	PIN_26,
	PIN_27,
	PIN_28,
	PIN_29,
	PIN_30,
	PIN_31

}PIN_t; 

#define PA0 	PIN_0 
#define PA1 	PIN_1
#define PA2 	PIN_2
#define PA3 	PIN_3
#define PA4 	PIN_4
#define PA5 	PIN_5
#define PA6 	PIN_6
#define PA7 	PIN_7


#define PB0 	PIN_0 
#define PB1 	PIN_1
#define PB2 	PIN_2
#define PB3 	PIN_3
#define PB4 	PIN_4
#define PB5 	PIN_5
#define PB6 	PIN_6
#define PB7 	PIN_7

#define PC0 	PIN_0 
#define PC1 	PIN_1
#define PC2 	PIN_2
#define PC3 	PIN_3
#define PC4 	PIN_4
#define PC5 	PIN_5
#define PC6 	PIN_6
#define PC7 	PIN_7

#define PD0 	PIN_0 
#define PD1 	PIN_1
#define PD2 	PIN_2
#define PD3 	PIN_3
#define PD4 	PIN_4
#define PD5 	PIN_5
#define PD6 	PIN_6
#define PD7 	PIN_7

#define PE0 	PIN_0 
#define PE1 	PIN_1
#define PE2 	PIN_2
#define PE3 	PIN_3
#define PE4 	PIN_4
#define PE5 	PIN_5


#define PF0 	PIN_0 
#define PF1 	PIN_1
#define PF2 	PIN_2
#define PF3 	PIN_3
#define PF4 	PIN_4

#define AIN10	PB4
#define AIN11 PB5 
#define AIN7 	PD0
#define AIN6 	PD1
#define AIN5 	PD2
#define AIN4 	PD3
#define AIN3 	PE0
#define AIN2 	PE1
#define AIN1 	PE2
#define AIN0 	PE3
#define AIN9 	PE4
#define AIN8 	PE5


#define SET_BIT(PORT,PIN)			(PORT |=(1U<<PIN))
#define CLEAR_BIT(PORT,PIN)		(PORT &=~(1U<<PIN))
#define READ_BIT(PORT,PIN)		((PORT&(1U<<PIN))>>PIN)
#define TOGGLE_BIT(PORT,PIN)	( PORT ^= (1U<<PIN))
#define PORT_WRITE(PORT,DATA)	(PORT = DATA) 
#define PORT_READ(PORT)				(PORT) 




#endif // ! __BIT_MATH_H__
