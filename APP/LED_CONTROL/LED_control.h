#ifndef __LED_CONTROL_H__
#define __LED_CONTROL_H__
#include "../../MCAL/Interrupt_Module/INT_interface.h"
#include "../../MCAL/GPIO_API/GPIO_interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_interface.h"
#include "../../HAL/LED/LED_interface.h"
#include "../../HAL/SWITCh/SW_interface.h"
extern volatile int32_t T_ON;
extern volatile int32_t T_OFF; 
extern volatile bool FLAG ;

void APP_init(void); 
//void LED_init(PORT_t port,PIN_t pin ,uint32_t time_on,uint32_t time_off );
void LED_intensity_control(void); 


#endif 
