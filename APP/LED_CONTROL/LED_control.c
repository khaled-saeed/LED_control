#include "LED_control.h"
volatile int32_t T_ON;
volatile int32_t T_OFF; 
volatile bool FLAG ; 

LED_t RED ;
void APP_init(void)
{

	SW_t switch1,switch2; 
	LED_init(&RED,PORT_F,PF1);
	SW_init(&switch1,PORT_F,PF0,ENABLED,PULL_UP); 
	SW_init(&switch2,PORT_F,PF4,ENABLED,PULL_UP); 
	SYSTICK_SetCallbackFunc(LED_intensity_control); 
	T_ON = 1 ; 
	T_OFF = 1; 
	FLAG = False ;
	SYSTICK_init(T_OFF);
}


void LED_intensity_control()
{
	if (FLAG == False)
	{
		SYSTICK_init(T_ON); 
		FLAG = True ; 
	}
	else
	{
		SYSTICK_init(T_OFF); 
		FLAG = False ; 
	}
	LED_Toggle(&RED); 
	
}
