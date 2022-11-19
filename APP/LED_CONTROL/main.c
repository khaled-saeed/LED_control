#include "LED_control.h"


int main()
{
	LED_init(PORT_F,PF3,1,5); 
		while(1)
		{

		}
	
}

void SysTick_Handler(void)
{
	SYSTICK_Callback_Func();  
}