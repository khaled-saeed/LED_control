#include "SW_interface.h"


void SW_init(SW_t* sw,PORT_t port,PIN_t pin,INTERRUPT_STATUS_t int_status,Internal_Resistor_t res)
{
	sw->PIN = pin ; 
	sw->PORT = port ; 
	sw->int_status = int_status; 
	sw->Resistor_type = res ; 
	GPIO_pinInit(port,pin,INPUT,res,ANALOG_DIS,ALT_DIS); 
	if(int_status == ENABLED)
	{
		EXT_INT_init(port,pin,res,Falling_Edge,GPIOF_INT_Handler); 
	}
}	
SW_STATUS_t SW_status(SW_t* sw)
{
	return ((SW_STATUS_t)GPIO_digitalPin_read(sw->PORT, sw->PIN)); 
}

