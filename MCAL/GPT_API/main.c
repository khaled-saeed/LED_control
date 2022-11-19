#include "GPT_interface.h"


int main()
{
	GPIO_pinInit(PORT_F,PF3, OUTPUT,NONE,ANALOG_DIS,ALT_DIS); 
	TIMER_init(); 
	TIMER_INT_init(1000); 
	while(1)
	{
		
	}
}	


void TIMER0A_Handler(void)
{
	TIMER0_Callback();
}