#ifndef __INT_PRIVATE_H__
#define __INT_PRIVATE_H__

#include "../../LIBRARIES/DIO.h"


typedef struct
{
  volatile uint32_t ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RESERVED1[24U];
  volatile uint32_t ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_t;

#define NVIC_BASE           (0xE000E000UL +  0x0100UL)  
#define NVIC                ((NVIC_t      *)     NVIC_BASE)   /*!< NVIC configuration struct */

/********************************************************************************************
													GPIO INTERRUPT
*********************************************************************************************/
#define APB 			1 
#define AHB 			2 
#define MASKED		3
#define UNMASKED 	4

/********************************************************************************************
													TIMER INTERRUPT
*********************************************************************************************/

#define INTERRUPT_ENABLED				15
#endif
