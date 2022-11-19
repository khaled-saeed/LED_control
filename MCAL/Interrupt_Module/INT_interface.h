#ifndef __INT_INTERFACE_H__
#define __INT_INTERFACE_H__
#include "INT_config.h"


typedef void(*callback_fptr_t)(uint32_t); 
typedef void(*Timer_callback_fptr_t)(void); 
typedef void(*SYSTICK_callback_fptr_t)(void); 

/********************************************************************************************
													GPIO INTERRUPT
*********************************************************************************************/

extern callback_fptr_t  GPIOA_callBack_FuncPtr ;
extern callback_fptr_t  GPIOB_callBack_FuncPtr ; 
extern callback_fptr_t  GPIOC_callBack_FuncPtr ; 
extern callback_fptr_t  GPIOD_callBack_FuncPtr ; 
extern callback_fptr_t  GPIOE_callBack_FuncPtr ; 
extern callback_fptr_t  GPIOF_callBack_FuncPtr ;

void GPIOA_setCallBack(callback_fptr_t );
void GPIOB_setCallBack(callback_fptr_t );
void GPIOC_setCallBack(callback_fptr_t );
void GPIOD_setCallBack(callback_fptr_t );
void GPIOE_setCallBack(callback_fptr_t );
void GPIOF_setCallBack(callback_fptr_t );

void GPIOA_INT_Handler(uint32_t);
void GPIOB_INT_Handler(uint32_t);
void GPIOC_INT_Handler(uint32_t);
void GPIOD_INT_Handler(uint32_t);
void GPIOE_INT_Handler(uint32_t);
void GPIOF_INT_Handler(uint32_t);

/********************************************************************************************
													TIMER INTERRUPT
*********************************************************************************************/
extern Timer_callback_fptr_t  TIMER0_Callback; 
extern Timer_callback_fptr_t  TIMER1_Callback; 
extern Timer_callback_fptr_t  TIMER2_Callback; 
extern Timer_callback_fptr_t  TIMER3_Callback; 
extern Timer_callback_fptr_t  TIMER4_Callback; 
extern Timer_callback_fptr_t  TIMER5_Callback; 

void TIMER0_INT_HANDLER(void);
void TIMER1_INT_HANDLER(void);
void TIMER2_INT_HANDLER(void);
void TIMER3_INT_HANDLER(void);
void TIMER4_INT_HANDLER(void);
void TIMER5_INT_HANDLER(void);

void TIMER0_SetCallbackFunc(Timer_callback_fptr_t) ; 
void TIMER1_SetCallbackFunc(Timer_callback_fptr_t) ; 
void TIMER2_SetCallbackFunc(Timer_callback_fptr_t) ; 
void TIMER3_SetCallbackFunc(Timer_callback_fptr_t) ; 
void TIMER4_SetCallbackFunc(Timer_callback_fptr_t) ; 
void TIMER5_SetCallbackFunc(Timer_callback_fptr_t) ; 
/********************************************************************************************
													SYSTICK INTERRUPT
*********************************************************************************************/
extern SYSTICK_callback_fptr_t  SYSTICK_Callback_Func;
void SYSTICK_INT_HANDLER(void);
void SYSTICK_SetCallbackFunc(SYSTICK_callback_fptr_t) ; 





#endif
