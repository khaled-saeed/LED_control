#include "GPT_interface.h"

	#if Timer_MODE == ONE_SHOT_MODE
		#if Timer_NUMBER == TIMER_0
			void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<<0) ; // provide a clock for timer 0
				TIMER0->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER0->CFG = 0x00	;					// select 32 bit configuration
				TIMER0->TAMR |= (1U<<0);			// for one shot
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER0->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER0->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER0->TAILR = 16000 * ms - 1;
				TIMER0->ICR = 0x1;						// clear the flag 
				TIMER0->CTL |= (1U<<0) ;
				while ((TIMER0->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER0_SetCallbackFunc(TIMER0_INT_HANDLER); 
				TIMER0->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER0->TAILR = 16000 * time - 1;
				TIMER0->ICR = 0x1;						// clear the flag 
				TIMER0->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[0] |= (1U<<19); 
			}
		#elif Timer_NUMBER == TIMER_1
		void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<<1) ; // provide a clock for timer 1
				TIMER1->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER1->CFG = 0x00	;					// select 32 bit configuration
				TIMER1->TAMR |= (1U<<0);			// for one shot
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER1->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER1->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER1->TAILR = 16000 * ms - 1;
				TIMER1->ICR = 0x1;						// clear the flag 
				TIMER1->CTL |= (1U<<0) ;
				while ((TIMER1->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER1_SetCallbackFunc(TIMER1_INT_HANDLER); 
				TIMER1->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER1->TAILR = 16000 * time - 1;
				TIMER1->ICR = 0x1;						// clear the flag 
				TIMER1->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[0] |= (1U<<21); 
			}
		#elif Timer_NUMBER == TIMER_2
		void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<2) ; // provide a clock for timer 2
				TIMER2->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER2->CFG = 0x00	;					// select 32 bit configuration
				TIMER2->TAMR |= (1U<<0);			// for one shot
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER2->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER2->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER2->TAILR = 16000 * ms - 1;
				TIMER2->ICR = 0x1;						// clear the flag 
				TIMER2->CTL |= (1U<<0) ;
				while ((TIMER2->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER2_SetCallbackFunc(TIMER2_INT_HANDLER); 
				TIMER2->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER2->TAILR = 16000 * time - 1;
				TIMER2->ICR = 0x1;						// clear the flag 
				TIMER2->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[0] |= (1U<<23); 
			}
		#elif Timer_NUMBER == TIMER_3
		void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<3) ; // provide a clock for timer 2
				TIMER3->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER3->CFG = 0x00	;					// select 32 bit configuration
				TIMER3->TAMR |= (1U<<0);			// for one shot
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER3->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER3->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER3->TAILR = 16000 * ms - 1;
				TIMER3->ICR = 0x1;						// clear the flag 
				TIMER3->CTL |= (1U<<0) ;
				while ((TIMER3->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER3_SetCallbackFunc(TIMER3_INT_HANDLER); 
				TIMER3->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER3->TAILR = 16000 * time - 1;
				TIMER3->ICR = 0x1;						// clear the flag 
				TIMER3->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[1] |= (1U<<4);
			}
		#elif Timer_NUMBER == TIMER_4
		void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<4) ; // provide a clock for timer 2
				TIMER4->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER4->CFG = 0x00	;					// select 32 bit configuration
				TIMER4->TAMR |= (1U<<0);			// for one shot
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER4->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER4->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER4->TAILR = 16000 * ms - 1;
				TIMER4->ICR = 0x1;						// clear the flag 
				TIMER4->CTL |= (1U<<0) ;
				while ((TIMER4->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER4_SetCallbackFunc(TIMER4_INT_HANDLER); 
				TIMER4->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER4->TAILR = 16000 * time - 1;
				TIMER4->ICR = 0x1;						// clear the flag 
				TIMER4->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[2] |= (1U<<7);
			}
		#elif Timer_NUMBER == TIMER_5
			void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<5) ; // provide a clock for timer 2
				TIMER5->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER5->CFG = 0x00	;					// select 32 bit configuration
				TIMER5->TAMR |= (1U<<0);			// for one shot
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER5->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER5->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER5->TAILR = 16000 * ms - 1;
				TIMER5->ICR = 0x1;						// clear the flag 
				TIMER5->CTL |= (1U<<0) ;
				while ((TIMER5->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER5_SetCallbackFunc(TIMER5_INT_HANDLER); 
				TIMER5->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER5->TAILR = 16000 * time - 1;
				TIMER5->ICR = 0x1;						// clear the flag 
				TIMER5->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[2] |= (1U<<23);
			}
		#endif
		
	#elif Timer_MODE == PERIODIC_MODE
		#if Timer_NUMBER == TIMER_0
			void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<<0) ; // provide a clock for timer 0
				TIMER0->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER0->CFG = 0x00	;					// select 32 bit configuration
				TIMER0->TAMR |= (2U<<0);			// for Periodic
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER0->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER0->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER0->TAILR = 16000 * ms - 1;
				TIMER0->ICR = 0x1;						// clear the flag 
				TIMER0->CTL |= (1U<<0) ;
				while ((TIMER0->RIS & 0x1) == 0);
				TIMER0->ICR = 0x1;
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER0_SetCallbackFunc(TIMER0_INT_HANDLER); 
				TIMER0->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER0->TAILR = 16000 * time - 1;
				TIMER0->ICR = 0x1;						// clear the flag 
				TIMER0->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[0] = (1U<<19); 
			}
		#elif Timer_NUMBER == TIMER_1
			void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<<1) ; // provide a clock for timer 0
				TIMER1->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER1->CFG = 0x00	;					// select 32 bit configuration
				TIMER1->TAMR |= (2U<<0);			// for Periodic
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER1->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER1->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER1->TAILR = 16000 * ms - 1;
				TIMER1->ICR = 0x1;						// clear the flag 
				TIMER1->CTL |= (1U<<0) ;
				while ((TIMER1->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER1_SetCallbackFunc(TIMER1_INT_HANDLER); 
				TIMER1->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER1->TAILR = 16000 * time - 1;
				TIMER1->ICR = 0x1;						// clear the flag 
				TIMER1->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[0] |= (1U<<21); 
			}
		#elif Timer_NUMBER == TIMER_2
			void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<<2) ; // provide a clock for timer 0
				TIMER2->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER2->CFG = 0x00	;					// select 32 bit configuration
				TIMER2->TAMR |= (2U<<0);			// for Periodic
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER2->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER2->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER2->TAILR = 16000 * ms - 1;
				TIMER2->ICR = 0x1;						// clear the flag 
				TIMER2->CTL |= (1U<<0) ;
				while ((TIMER2->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER2_SetCallbackFunc(TIMER2_INT_HANDLER); 
				TIMER2->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER2->TAILR = 16000 * time - 1;
				TIMER2->ICR = 0x1;						// clear the flag 
				TIME2->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[0] |= (1U<<23); 
			}
		#elif Timer_NUMBER == TIMER_3
		void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<<3) ; // provide a clock for timer 0
				TIMER3->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER3->CFG = 0x00	;					// select 32 bit configuration
				TIMER3->TAMR |= (2U<<0);			// for Periodic
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER3->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER3->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER3->TAILR = 16000 * ms - 1;
				TIMER3->ICR = 0x1;						// clear the flag 
				TIMER3->CTL |= (1U<<0) ;
				while ((TIMER3->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER3_SetCallbackFunc(TIMER3_INT_HANDLER); 
				TIMER3->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER3->TAILR = 16000 * time - 1;
				TIMER3->ICR = 0x1;						// clear the flag 
				TIMER3->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[1] |= (1U<<4);
			}
		#elif Timer_NUMBER == TIMER_4
		void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<<4) ; // provide a clock for timer 0
				TIMER4->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER4->CFG = 0x00	;					// select 32 bit configuration
				TIMER4->TAMR |= (2U<<0);			// for Periodic
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER4->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER4->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER4->TAILR = 16000 * ms - 1;
				TIMER4->ICR = 0x1;						// clear the flag 
				TIMER4->CTL |= (1U<<0) ;
				while ((TIMER4->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER4_SetCallbackFunc(TIMER4_INT_HANDLER); 
				TIMER4->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER4->TAILR = 16000 * time - 1;
				TIMER4->ICR = 0x1;						// clear the flag 
				TIMER4->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[2] |= (1U<<7);
			}
		#elif Timer_NUMBER == TIMER_5
			void TIMER_init(void)
			{
				SYSCTL->RCGCTIMER |= (1U<<5) ; // provide a clock for timer 0
				TIMER5->CTL &= ~(1U<<0) ; 		// disable the timer while config
				TIMER5->CFG = 0x00	;					// select 32 bit configuration
				TIMER5->TAMR |= (2U<<0);			// for Periodic
				#if INTERRUPT_POLLING_MODE == POLLING_ENABLED
					TIMER5->TAMR &= ~(1U<<5);
				#elif INTERRUPT_POLLING_MODE == INTERRUPT_ENABLED
					TIMER5->TAMR |= (1U<<5);
				#endif
			}
			void delay_ms(uint32_t ms)
			{
				TIMER5->TAILR = 16000 * ms - 1;
				TIMER5->ICR = 0x1;						// clear the flag 
				TIMER5->CTL |= (1U<<0) ;
				while ((TIMER5->RIS & 0x1) == 0);
			}
			void TIMER_INT_init(uint32_t time)
			{
				TIMER5_SetCallbackFunc(TIMER5_INT_HANDLER); 
				TIMER5->IMR |= (1U<<0) ;		// enable time out interrupt 
				TIMER5->TAILR = 16000 * time - 1;
				TIMER5->ICR = 0x1;						// clear the flag 
				TIMER5->CTL |= (1U<<0) ;			// enable timer 
				NVIC->ISER[2] |= (1U<<23);
			}
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


