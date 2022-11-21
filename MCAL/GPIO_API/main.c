#include "GPIO_interface.h"


extern callback_fptr_t callBack_FuncPtr; 
int main()
{	
	GPIO_portInit(PORT_F,PF1,OUTPUT,NONE,ANALOG_DIS); 
	GPIOF_AHB->DATA_BITS[2] = 0x2; 
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

