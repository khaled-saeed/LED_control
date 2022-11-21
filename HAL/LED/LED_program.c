#include "LED_interface.h"
void LED_init(LED_t* led, PORT_t port,PIN_t pin)
{
	led->pin = pin ; 
	led->port = port ; 
	GPIO_pinInit(port,pin,OUTPUT,NONE,ANALOG_DIS,ALT_DIS); 
}
void LED_ON(LED_t* led) 
{
	GPIO_digitalPin_write(led->port,led->pin,HIGH); 
}
void LED_OFF(LED_t* led) 
{
	GPIO_digitalPin_write(led->port,led->pin,LOW); 
}
void LED_Toggle(LED_t* led)
{
	GPIO_digitalPin_toggle(led->port,led->pin); 
}