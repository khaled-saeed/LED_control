#ifndef __LED_INTERFACE_H__
#define __LED_INTERFACE_H__
#include "LED_config.h"

typedef struct
{
	PORT_t port ; 
	PIN_t pin ; 
	
}LED_t;

void LED_init(LED_t* , PORT_t,PIN_t); 
void LED_ON(LED_t* ) ;
void LED_OFF(LED_t* ) ;
void LED_Toggle(LED_t*); 
#endif
