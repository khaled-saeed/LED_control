#include "GPIO_interface.h"


extern callback_fptr_t callBack_FuncPtr; 
int main()
{	
	GPIO_pinInit(PORT_F,PF2,OUTPUT,NONE,ANALOG_DIS,ALT_DIS) ; 
	EXT_INT_init(PORT_F,PF0,PULL_UP,Falling_Edge,GPIOF_INT_Handler);
	while(1)
	{

	}

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

