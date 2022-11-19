#include "SYSTICK_interface.h"
#include <assert.h>
void SYSTICK_init(uint32_t ms)
{
	#if CLOCK_SRC == INTERNAL_OSC
	
	assert(ms*4000 <= 16777216);
	SysTick->LOAD = (ms*4000) -1;
	
	#elif CLOCK_SRC == INTERNAL_OSC
	
	assert(ms*16000 <= 16777216);
	SysTick->LOAD = (ms*16000) -1;
	
	#endif
	SysTick->VAL = 1 ; 
	#if	INTERRUPT_STATUS == INT_ENABLED
		SET_BIT(SysTick->CTRL ,1) ; 
		
	#elif INTERRUPT_STATUS == INT_DISABLED
		CLEAR_BIT(SysTick->CTRL ,1) ; 
	#endif
	
	#if	CLOCK_SRC == SYSTEM_CLK
		SET_BIT(SysTick->CTRL ,2) ; 
	#elif CLOCK_SRC == INTERNAL_OSC
		CLEAR_BIT(SysTick->CTRL ,2) ; 
	#endif
	SET_BIT(SysTick->CTRL,0); 
}


