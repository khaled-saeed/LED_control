#ifndef __SW_INTERFACE_H__
#define __SW_INTERFACE_H__
#include "SW_config.h"

typedef enum{
	DISABLED,
	ENABLED	
}INTERRUPT_STATUS_t; 

typedef enum{
	UNPRESSED,
	PRESSED	
}SW_STATUS_t; 
typedef struct{
	PORT_t PORT;
	PIN_t PIN ;
	INTERRUPT_STATUS_t int_status; 
	Internal_Resistor_t Resistor_type; 
}SW_t;


void SW_init(SW_t*,PORT_t,PIN_t,INTERRUPT_STATUS_t,Internal_Resistor_t); 
SW_STATUS_t SW_status(SW_t*); 


#endif
