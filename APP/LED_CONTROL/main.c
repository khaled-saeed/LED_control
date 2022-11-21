#include "LED_control.h"


int main()
{
	APP_init(); 
		while(1)
		{
		}
}

void SysTick_Handler(void)
{
	SYSTICK_Callback_Func();  
}
void GPIOF_Handler(void)
{
	#if BUS_TYPE == APB
			uint32_t pin = GPIOF->MIS &0xFF ; 
	#elif BUS_TYPE == AHB 
			uint32_t pin = GPIOF_AHB->MIS &0xFF ; 
	#endif
	GPIOF_callBack_FuncPtr(pin); 
}