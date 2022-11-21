#include "INT_interface.h"
#include "../GPIO_API/GPIO_interface.h"
#include "../GPT_API/GPT_interface.h"
#include "../../APP/LED_CONTROL/LED_control.h" 
/***********************************************************************************
												GPIO Callback Functions pointers 
************************************************************************************/
callback_fptr_t  GPIOA_callBack_FuncPtr ;
callback_fptr_t  GPIOB_callBack_FuncPtr ; 
callback_fptr_t  GPIOC_callBack_FuncPtr ; 
callback_fptr_t  GPIOD_callBack_FuncPtr ; 
callback_fptr_t  GPIOE_callBack_FuncPtr ; 
callback_fptr_t  GPIOF_callBack_FuncPtr ; 
/***********************************************************************************
												TIMERS Callback Functions pointers 
************************************************************************************/

Timer_callback_fptr_t  TIMER0_Callback; 
Timer_callback_fptr_t  TIMER1_Callback; 
Timer_callback_fptr_t  TIMER2_Callback; 
Timer_callback_fptr_t  TIMER3_Callback; 
Timer_callback_fptr_t  TIMER4_Callback; 
Timer_callback_fptr_t  TIMER5_Callback; 

/***********************************************************************************
												SYSTICK Callback Functions pointers 
************************************************************************************/

SYSTICK_callback_fptr_t SYSTICK_Callback_Func;



/***********************************************************************************
												GPIO Set Callback Functions definition 
************************************************************************************/

void GPIOA_setCallBack(callback_fptr_t callback)
{
	GPIOA_callBack_FuncPtr = callback ; 
	
}

void GPIOB_setCallBack(callback_fptr_t callback)
{
	GPIOB_callBack_FuncPtr = callback ; 
	
}

void GPIOC_setCallBack(callback_fptr_t callback)
{
	GPIOC_callBack_FuncPtr = callback ; 
	
}

void GPIOD_setCallBack(callback_fptr_t callback)
{
	GPIOD_callBack_FuncPtr = callback ; 
	
}

void GPIOE_setCallBack(callback_fptr_t callback)
{
	GPIOE_callBack_FuncPtr = callback ; 
	
}

void GPIOF_setCallBack(callback_fptr_t callback)
{
	GPIOF_callBack_FuncPtr = callback ; 
	
}

/***********************************************************************************
												GPIO Interrupt Handlers
************************************************************************************/

void GPIOA_INT_Handler(uint32_t pin)
{
	#if BUS_TYPE == APB
		if(pin == (1U<<PA0))
			{
				SET_BIT(GPIOA->ICR,PA0);
			}
		else if (pin == (1U<<PA1))
			{
				SET_BIT(GPIOA->ICR,PA1);
			}
		else if (pin ==(1U<<PA2))
			{
				SET_BIT(GPIOA->ICR,PA2);
			}
		else if (pin == (1U<<PA3))
			{
				SET_BIT(GPIOA->ICR,PA3);
			}
		else if (pin == (1U<<PA4))
			{
				SET_BIT(GPIOA->ICR,PA4);
			}
		else if (pin ==(1U<<PA5))
			{
				SET_BIT(GPIOA->ICR,PA5);
			}
		else if (pin ==(1U<<PA6))
			{
				SET_BIT(GPIOA->ICR,PA6);
			}
		else if (pin == (1U<<PA7))
			{
				SET_BIT(GPIOA->ICR,PA7);
			}
	#elif BUS_TYPE == AHB 
		if(pin == (1U<<PA0))
			{
				SET_BIT(GPIOA_AHB->ICR,PA0);
			}
		else if (pin == (1U<<PA1))
			{
				SET_BIT(GPIOA_AHB->ICR,PA1);
			}
		else if (pin ==(1U<<PA2))
			{
				SET_BIT(GPIOA_AHB->ICR,PA2);
			}
		else if (pin == (1U<<PA3))
			{
				SET_BIT(GPIOA_AHB->ICR,PA3);
			}
		else if (pin == (1U<<PA4))
			{
				SET_BIT(GPIOA_AHB->ICR,PA4);
			}
		else if (pin ==(1U<<PA5))
			{
				SET_BIT(GPIOA_AHB->ICR,PA5);
			}
		else if (pin ==(1U<<PA6))
			{
				SET_BIT(GPIOA_AHB->ICR,PA6);
			}
		else if (pin == (1U<<PA7))
			{
				SET_BIT(GPIOA_AHB->ICR,PA7);
			}
	#endif 
}
void GPIOB_INT_Handler(uint32_t pin)
{
	#if BUS_TYPE == APB
			if(pin == (1U<<PB0))
			{
				SET_BIT(GPIOB->ICR,PB0);
			}
		else if (pin ==  (1U<<PB1))
			{
				SET_BIT(GPIOB->ICR,PB1);
			}
		else if (pin == (1U<<PB2))
			{
				SET_BIT(GPIOB->ICR,PB2);
			}
		else if (pin ==  (1U<<PB3))
			{
				SET_BIT(GPIOB->ICR,PB3);
			}
		else if (pin == (1U<<PB4))
			{
				SET_BIT(GPIOB->ICR,PB4);
			}
		else if (pin == (1U<<PB5))
			{
				SET_BIT(GPIOB->ICR,PB5);
			}
		else if (pin == (1U<<PB6))
			{
				SET_BIT(GPIOB->ICR,PB6);
			}
		else if (pin == (1U<<PB7))
			{
				SET_BIT(GPIOB->ICR,PB7);
			}
	#elif BUS_TYPE == AHB 
		if(pin == (1U<<PB0))
			{
				SET_BIT(GPIOB_AHB->ICR,PB0);
			}
		else if (pin ==  (1U<<PB1))
			{
				SET_BIT(GPIOB_AHB->ICR,PB1);
			}
		else if (pin == (1U<<PB2))
			{
				SET_BIT(GPIOB_AHB->ICR,PB2);
			}
		else if (pin ==  (1U<<PB3))
			{
				SET_BIT(GPIOB_AHB->ICR,PB3);
			}
		else if (pin == (1U<<PB4))
			{
				SET_BIT(GPIOB_AHB->ICR,PB4);
			}
		else if (pin == (1U<<PB5))
			{
				SET_BIT(GPIOB_AHB->ICR,PB5);
			}
		else if (pin == (1U<<PB6))
			{
				SET_BIT(GPIOB_AHB->ICR,PB6);
			}
		else if (pin == (1U<<PB7))
			{
				SET_BIT(GPIOB_AHB->ICR,PB7);
			}
	#endif 
}
void GPIOC_INT_Handler(uint32_t pin)
{
		#if BUS_TYPE == APB
		if(pin == (1U<<PC0))
			{
				SET_BIT(GPIOC->ICR,PC0);
			}
		else if (pin == (1U<<PC1))
			{
				SET_BIT(GPIOC->ICR,PC1);
			}
		else if (pin == (1U<<PC2))
			{
				SET_BIT(GPIOC->ICR,PC2);
			}
		else if (pin == (1U<<PC3))
			{
				SET_BIT(GPIOC->ICR,PC3);
			}
		else if (pin == (1U<<PC4))
			{
				SET_BIT(GPIOC->ICR,PC4);
			}
		else if (pin == (1U<<PC5))
			{
				SET_BIT(GPIOC->ICR,PC5);	
			}
		else if (pin == (1U<<PC6))
			{
				SET_BIT(GPIOC->ICR,PC6);
			}
		else if (pin == (1U<<PC7))
			{
				SET_BIT(GPIOC->ICR,PC7);
			}
	#elif BUS_TYPE == AHB 
		if(pin == (1U<<PC0))
			{
				SET_BIT(GPIOC_AHB->ICR,PC0);
			}
		else if (pin == (1U<<PC1))
			{
				SET_BIT(GPIOC_AHB->ICR,PC1);
			}
		else if (pin == (1U<<PC2))
			{
				SET_BIT(GPIOC_AHB->ICR,PC2);
			}
		else if (pin == (1U<<PC3))
			{
				SET_BIT(GPIOC_AHB->ICR,PC3);
			}
		else if (pin == (1U<<PC4))
			{
				SET_BIT(GPIOC_AHB->ICR,PC4);
			}
		else if (pin == (1U<<PC5))
			{
				SET_BIT(GPIOC_AHB->ICR,PC5);	
			}
		else if (pin == (1U<<PC6))
			{
				SET_BIT(GPIOC_AHB->ICR,PC6);
			}
		else if (pin == (1U<<PC7))
			{
				SET_BIT(GPIOC_AHB->ICR,PC7);
			}
	#endif 
}
void GPIOD_INT_Handler(uint32_t pin)
{
		#if BUS_TYPE == APB
		if(pin ==(1U<<PD0))
			{
				SET_BIT(GPIOD->ICR,PD0);
			}
		else if (pin ==(1U<<PD1))
			{
				SET_BIT(GPIOD->ICR,PD1);
			}
		else if (pin ==(1U<<PD2))
			{
				SET_BIT(GPIOD->ICR,PD2);
			}
		else if (pin ==(1U<<PD3))
			{
				SET_BIT(GPIOD->ICR,PD3);
			}
		else if (pin ==(1U<<PD4))
			{
				SET_BIT(GPIOD->ICR,PD4);
			}
		else if (pin ==(1U<<PD5))
			{
				SET_BIT(GPIOD->ICR,PD5);
			}
		else if (pin ==(1U<<PD6))
			{
				SET_BIT(GPIOD->ICR,PD6);
			}
		else if (pin ==(1U<<PD7))
			{
				SET_BIT(GPIOD->ICR,PD7);
			}
	#elif BUS_TYPE == AHB 
		if(pin ==(1U<<PD0))
			{
				SET_BIT(GPIOD_AHB->ICR,PD0);
			}
		else if (pin ==(1U<<PD1))
			{
				SET_BIT(GPIOD_AHB->ICR,PD1);
			}
		else if (pin ==(1U<<PD2))
			{
				SET_BIT(GPIOD_AHB->ICR,PD2);
			}
		else if (pin ==(1U<<PD3))
			{
				SET_BIT(GPIOD_AHB->ICR,PD3);
			}
		else if (pin ==(1U<<PD4))
			{
				SET_BIT(GPIOD_AHB->ICR,PD4);
			}
		else if (pin ==(1U<<PD5))
			{
				SET_BIT(GPIOD_AHB->ICR,PD5);
			}
		else if (pin ==(1U<<PD6))
			{
				SET_BIT(GPIOD_AHB->ICR,PD6);
			}
		else if (pin ==(1U<<PD7))
			{
				SET_BIT(GPIOD_AHB->ICR,PD7);
			}
	#endif 
}
void GPIOE_INT_Handler(uint32_t pin)
{
	#if BUS_TYPE == APB
		if(pin == (1U<<PE0))
			{
				SET_BIT(GPIOE->ICR,PE0);
			}
		else if (pin == (1U<<PE1))
			{
				SET_BIT(GPIOE->ICR,PE1);
			}
		else if (pin == (1U<<PE2))
			{
				SET_BIT(GPIOE->ICR,PE2);
			}
		else if (pin == (1U<<PE3))
			{
				SET_BIT(GPIOE->ICR,PE3);
			}
		else if (pin == (1U<<PE4))
			{
				SET_BIT(GPIOE->ICR,PE4);
			}
		else if (pin == (1U<<PE5))
			{
				SET_BIT(GPIOE->ICR,PE5);
			}


	#elif BUS_TYPE == AHB 
		if(pin == (1U<<PE0))
			{
				SET_BIT(GPIOE_AHB->ICR,PE0);
			}
		else if (pin == (1U<<PE1))
			{
				SET_BIT(GPIOE_AHB->ICR,PE1);
			}
		else if (pin == (1U<<PE2))
			{
				SET_BIT(GPIOE_AHB->ICR,PE2);
			}
		else if (pin == (1U<<PE3))
			{
				SET_BIT(GPIOE_AHB->ICR,PE3);
			}
		else if (pin == (1U<<PE4))
			{
				SET_BIT(GPIOE_AHB->ICR,PE4);
			}
		else if (pin == (1U<<PE5))
			{
				SET_BIT(GPIOE_AHB->ICR,PE5);
			}

	#endif 
}
void GPIOF_INT_Handler(uint32_t pin)
{
	#if BUS_TYPE == APB
		if(pin == (1U<<PF0))
			{

				SET_BIT(GPIOF->ICR,PF0);
			}
		else if (pin == (1U<<PF1))
			{
				SET_BIT(GPIOF->ICR,PF1);
			}
		else if (pin == (1U<<PF2))
			{
				SET_BIT(GPIOF->ICR,PF2);
			}
		else if (pin == (1U<<PF3))
			{
				SET_BIT(GPIOF->ICR,PF3);
			}
		else if (pin == (1U<<PF4))
			{
				SET_BIT(GPIOF->ICR,PF4);
			}

	#elif BUS_TYPE == AHB 
		if(pin == (1U<<PF0))
			{
				
				T_ON += 5; 
				T_OFF -= 5 ; 
				if(T_ON > 200)
				{
					T_ON = 1  ; 
				}
				if(T_OFF<=0)
				{
					T_OFF = 1 ; 
				}
				SET_BIT(GPIOF_AHB->ICR,PF0);
			}
		else if (pin == (1U<<PF1))
			{
				SET_BIT(GPIOF_AHB->ICR,PF1);
			}
		else if (pin == (1U<<PF2))
			{
				SET_BIT(GPIOF_AHB->ICR,PF2);
			}
		else if (pin == (1U<<PF3))
			{
				SET_BIT(GPIOF_AHB->ICR,PF3);
			}
		else if (pin == (1U<<PF4))
			{
				T_OFF += 5 ; 
				T_ON -= 5 ; 
				if(T_OFF > 200)
				{
					T_OFF = 1  ; 
				}
				if(T_ON <= 0)
				{
					T_ON = 1 ; 
				}
				
				SET_BIT(GPIOF_AHB->ICR,PF4);
				
			}
	
	#endif 
}


/***********************************************************************************
												TIMERS Interrupt Handlers
************************************************************************************/

void TIMER0_INT_HANDLER(void)
{
	GPIO_digitalPin_toggle(PORT_F,PF3); 
	SET_BIT(TIMER0->ICR,0);
}
void TIMER1_INT_HANDLER(void)
{
	SET_BIT(TIMER0->ICR,0);
}
void TIMER2_INT_HANDLER(void)
{
	SET_BIT(TIMER0->ICR,0);
}
void TIMER3_INT_HANDLER(void)
{
	SET_BIT(TIMER0->ICR,0);
}
void TIMER4_INT_HANDLER(void)
{
	SET_BIT(TIMER0->ICR,0);
}
void TIMER5_INT_HANDLER(void)
{
	SET_BIT(TIMER0->ICR,0);
}
/***********************************************************************************
												TIMERS Set Callback Functions Defintion 
************************************************************************************/

void TIMER0_SetCallbackFunc(Timer_callback_fptr_t INT_callbackEunc) 
{
	TIMER0_Callback =INT_callbackEunc ; 
}
void TIMER1_SetCallbackFunc(Timer_callback_fptr_t INT_callbackEunc) 
{
	TIMER1_Callback =INT_callbackEunc ; 
}
void TIMER2_SetCallbackFunc(Timer_callback_fptr_t INT_callbackEunc) 
{
	TIMER2_Callback =INT_callbackEunc ; 
}
void TIMER3_SetCallbackFunc(Timer_callback_fptr_t INT_callbackEunc) 
{
	TIMER3_Callback =INT_callbackEunc ; 
}
void TIMER4_SetCallbackFunc(Timer_callback_fptr_t INT_callbackEunc) 
{
	TIMER4_Callback =INT_callbackEunc ; 
}
void TIMER5_SetCallbackFunc(Timer_callback_fptr_t INT_callbackEunc) 
{
	TIMER5_Callback =INT_callbackEunc ; 
}

/***********************************************************************************
												SYSTICK Set Callback Functions Defintion 
************************************************************************************/
void SYSTICK_SetCallbackFunc(SYSTICK_callback_fptr_t callback_fptr)
{
	SYSTICK_Callback_Func = callback_fptr ; 
}

/***********************************************************************************
												SYSTICK Interrupt Handler  
************************************************************************************/
void SYSTICK_INT_HANDLER(void)
{
		GPIO_digitalPin_toggle(PORT_F,PF3); 
}
