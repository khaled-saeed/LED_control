#ifndef __GPT_INTERFACE_H__
#define __GPT_INTERFACE_H__
#include "GPT_config.h"
typedef void(*callback_fptr)(void); 
		extern callback_fptr INT_Callback; 
		void INT_HANDLER(void); 
		

	#if Timer_MODE == ONE_SHOT_MODE
		#if Timer_NUMBER == TIMER_0
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_1
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_2
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_3
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_4
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_5
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#endif
		
	#elif Timer_MODE == PERIODIC_MODE
		#if Timer_NUMBER == TIMER_0
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_1
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);

		#elif Timer_NUMBER == TIMER_2
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_3
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_4
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#elif Timer_NUMBER == TIMER_5
			void TIMER_init(void);
			void delay_ms(uint32_t ms);
			void TIMER_INT_init(uint32_t);
		#endif
	#elif Timer_MODE == EDGE_TIME_CAPTURE_MODE
		#if Timer_NUMBER == TIMER_0
			void TIMER_init(TIMER_CLASS_t timer_class)
			{
				
			}
		#elif Timer_NUMBER == TIMER_1
		
		#elif Timer_NUMBER == TIMER_2
		
		#elif Timer_NUMBER == TIMER_3
		
		#elif Timer_NUMBER == TIMER_4
		
		#elif Timer_NUMBER == TIMER_5
	
		#endif
	#endif


	
#endif
