#ifndef __GPIO_INTERFACE_H__
#define __GPIO_INTERFACE_H__
#include "GPIO_config.h"



/*********************************************************************************
														Typedefs & #defines 
***********************************************************************************/


typedef enum{
	False,
	True
}bool;
typedef enum
{
	NONE, 
	PULL_UP,
	PULL_DOWN,
	OPEN_DRAIN
}Internal_Resistor_t;	


typedef enum 
{
	INPUT,
	OUTPUT
}PIN_DIR_t; 

typedef enum
{
	LOW, 
	HIGH
}PIN_LEVEL_t;

typedef enum 
{
	ALT_DIS,
	one,
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	eleven,
	twelv,
	thrteen,
	fourteen,
	fifteen,
}ALTER_FUNC_t; 

typedef enum 
{
	ANALOG_DIS,
	ANALOG_EN
}ANALOG_CTL_t;


typedef enum{
	Rising_Edge,
	Falling_Edge,
	Rising_Falling_Edge, 
	High_Level,
	Low_Level
	
}INT_Trig_t ; 

#define NVIC_PORTA_INT 0
#define NVIC_PORTB_INT 1
#define NVIC_PORTC_INT 2
#define NVIC_PORTD_INT 3
#define NVIC_PORTE_INT 4
#define NVIC_PORTF_INT 30



#define U0Tx		one 
#define U0Rx		one 
#define U1Rx		one 
#define U1Tx		one 
#define TCK			one 
#define TMS			one 
#define TDI			one 
#define TDO			one 
#define U4Rx		one 
#define U4Tx		one 
#define U3Rx		one 
#define U3Tx		one 
#define SSI3CLK	one 
#define SSI3Fss	one 
#define SSI3Rx  one 
#define SSI3Tx  one 
#define U6Rx		one 
#define U6Tx		one 
#define U7Rx		one 
#define U7Tx		one 
#define U5Rx		one 
#define U5Tx		one 
#define U1RTS		one 
#define U1CTS		one 


#define SSI1CLK	two 
#define SSI1Fss	two 
#define SS1Rx  	two 
#define SS13Tx  two 
#define SSI2CLK	two 
#define SSI2Fss	two 
#define SS2Rx  	two 
#define SS23Tx  two 

#define I2C1SCL	three
#define I2C1SDA	three
#define I2C0SCL	three
#define I2C0SDA	three
#define I2C3SCL	three
#define I2C3SDA	three
#define I2C2SCL	three
#define I2C2SDA	three
#define CAN0Rx	three
#define CAN0Tx	three

#define M0PWM2	four
#define M0PWM3	four
#define M0PWM0	four
#define M0PWM1	four
#define M0PWM6	four
#define M0PWM7	four
#define M0FAULT0 four
#define M0PWM4	four
#define M0PWM5	four

#define M1PWM2	five
#define M1PWM3	five
#define M1PWM0	five
#define M1PWM1	five
#define M1PWM2	five
#define M1PWM4	five
#define M1PWM5	five
#define M1PWM6	five
#define M1PWM7	five
#define M1FAULT0 five

#define IDx1 		six
#define PhA1 		six
#define PhB1 		six
#define IDx0 		six
#define PhA0 		six
#define PhB0 		six

#define T2CCP0	seven
#define T2CCP1	seven
#define T3CCP0	seven
#define T3CCP1	seven
#define T1CCP0	seven
#define T1CCP1	seven
#define T0CCP0	seven
#define T0CCP1	seven
#define T4CCP0	seven
#define T4CCP1	seven
#define T5CCP0	seven
#define T5CCP1	seven
#define WT0CCP0	seven
#define WT0CCP1	seven
#define WT1CCP0	seven
#define WT1CCP1	seven
#define WT2CCP0	seven
#define WT2CCP1	seven
#define WT3CCP0	seven
#define WT3CCP1	seven
#define WT4CCP0	seven
#define WT4CCP1	seven
#define WT5CCP0	seven
#define WT5CCP1	seven


#define CAN1Rx	eight
#define CAN1Tx	eight
#define CAN0Rx_2	eight
#define CAN0Tx_2	eight


/*********************************************************************************
														BIT Manpulation 
***********************************************************************************/
void GPIO_pinInit(PORT_t,PIN_t,PIN_DIR_t,Internal_Resistor_t, ANALOG_CTL_t,ALTER_FUNC_t);
void GPIO_digitalPin_write(PORT_t,PIN_t,PIN_LEVEL_t); 
bool GPIO_digitalPin_read(PORT_t,PIN_t) ; 
void GPIO_digitalPin_toggle(PORT_t,PIN_t); 



/*********************************************************************************
														PORT Manpulation 
***********************************************************************************/
void GPIO_portInit(PORT_t,PIN_t,PIN_DIR_t,Internal_Resistor_t, ANALOG_CTL_t);
void GPIO_digitalPort_write(PORT_t,uint8_t ); 
uint8_t GPIO_digitalPort_read(PORT_t ); 



/*********************************************************************************
														External Interrupt Manpulation 
***********************************************************************************/


void EXT_INT_init(PORT_t ,PIN_t ,Internal_Resistor_t ,INT_Trig_t  ,callback_fptr_t  );
#endif 
