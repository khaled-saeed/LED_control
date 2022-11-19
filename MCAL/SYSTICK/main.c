#include "SYSTICK_interface.h"
#include "../GPIO_API/GPIO_interface.h"


bool LED_ON = False ; 
int main ()
{
	GPIO_pinInit(PORT_F,PF3,OUTPUT,NONE,ANALOG_DIS,ALT_DIS); 
	SYSTICK_init(500); 
	SYSTICK_SetCallbackFunc(SYSTICK_INT_HANDLER); 
	while(1)
	{
	}
}



void SysTick_Handler(void)
{

}
