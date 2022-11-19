#include "LED_control.h"
volatile uint32_t T_ON;
volatile uint32_t T_OFF; 
volatile bool LED_ON  ;
void LED_init(PORT_t port,PIN_t pin ,uint32_t time_on,uint32_t time_off )
{
	GPIO_pinInit(port,pin,OUTPUT,NONE,ANALOG_DIS,ALT_DIS); 
	SYSTICK_SetCallbackFunc(LED_intensity_control); 
	T_ON = time_on ; 
	T_OFF = time_off; 
	LED_ON = False ;
	SYSTICK_init(T_OFF); 			
}
void LED_intensity_control()
{
	if (LED_ON == False)
	{
		SYSTICK_init(T_ON); 
		LED_ON = True ; 
	}
	else
	{
		SYSTICK_init(T_OFF); 
		LED_ON = False ; 
	}
	GPIO_digitalPin_toggle(PORT_F,PF3); 
	
}
