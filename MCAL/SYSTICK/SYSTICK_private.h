#ifndef __SYSTICK_PRIVATE_H__
#define __SYSTICK_PRIVATE_H__
#include "../../LIBRARIES/bit_math.h"
#include "../../LIBRARIES/STD_types.h"
#include "../Interrupt_Module/INT_interface.h"

#define INT_DISABLED	0
#define INT_ENABLED	1

#define INTERNAL_OSC	0
#define SYSTEM_CLK	1


typedef struct
{
  volatile 				uint32_t CTRL;                  
  volatile 				uint32_t LOAD;                   
  volatile 				uint32_t VAL;                   
} SysTick_t;

#define SysTick_BASE        (0xE000E000UL +  0x0010UL)
#define SysTick             ((SysTick_t   *)     SysTick_BASE  )

#endif 
