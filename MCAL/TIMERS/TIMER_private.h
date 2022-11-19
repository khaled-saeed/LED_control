#ifndef __TIMER_PRIVATE_H__
#define __TIMER_PRIVATE_H__
#include "../../LIBRARIES/DIO.h"
#include "../GPIO_API/GPIO_interface.h"
#include "../Interrupt_Module/INT_interface.h"
/********************************************
								TIMER_TYPE 
*********************************************/
#define TIMER_TYPE_16_32 				1
#define TIMER_TYPE_32_64 				2
/********************************************
								TIMER_MODE 
*********************************************/
#define ONE_SHOT_MODE 					3
#define PERIODIC_MODE 					4
#define RTC_MODE 								5
#define EDGE_TIME_CAPTURE_MODE  6
#define PWM_MODE								7
#define CAPTURE_COMPARE_MODE		8

/********************************************
								TIMER_NUMBER
*********************************************/
#define TIMER_0 								0
#define TIMER_1 								1
#define TIMER_2 								2
#define TIMER_3 								3
#define TIMER_4 								4
#define TIMER_5 								5
/********************************************
								INTERRUPT_POLLING_MODE
*********************************************/
#define INTERRUPT_ENABLED				15
#define POLLING_ENABLED		    	16


typedef struct {                                    
  volatile 						uint32_t  CFG;                               
  volatile 						uint32_t  TAMR;                              
  volatile 						uint32_t  TBMR;                              
  volatile 						uint32_t  CTL;                               
  volatile 						uint32_t  SYNC;                              
  volatile const  		uint32_t  RESERVED;
  volatile 						uint32_t  IMR;                               
  volatile 						uint32_t  RIS;                               
  volatile 						uint32_t  MIS;                              
  volatile 						uint32_t  ICR;                               
  volatile 						uint32_t  TAILR;                            
  volatile 						uint32_t  TBILR;                             
  volatile 						uint32_t  TAMATCHR;                         
  volatile 						uint32_t  TBMATCHR;                          
  volatile 						uint32_t  TAPR;                              
  volatile 						uint32_t  TBPR;                              
  volatile 						uint32_t  TAPMR;                             
  volatile 						uint32_t  TBPMR;                            
  volatile 						uint32_t  TAR;                               
  volatile 						uint32_t  TBR;                               
  volatile 						uint32_t  TAV;                              
  volatile 						uint32_t  TBV;                              
  volatile 						uint32_t  RTCPD;                             
  volatile 						uint32_t  TAPS;                              
  volatile 						uint32_t  TBPS;                              
  volatile 						uint32_t  TAPV;                              
  volatile 						uint32_t  TBPV;                              
  volatile const  		uint32_t  RESERVED1[981];
  volatile 						uint32_t  PP;                                
} GPT_t;
#define TIMER0_BASE                     0x40030000UL
#define TIMER1_BASE                     0x40031000UL
#define TIMER2_BASE                     0x40032000UL
#define TIMER3_BASE                     0x40033000UL
#define TIMER4_BASE                     0x40034000UL
#define TIMER5_BASE                     0x40035000UL

#define TIMER0                          ((GPT_t *) TIMER0_BASE)
#define TIMER1                          ((GPT_t *) TIMER1_BASE)
#define TIMER2                          ((GPT_t *) TIMER2_BASE)
#define TIMER3                          ((GPT_t *) TIMER3_BASE)
#define TIMER4                          ((GPT_t *) TIMER4_BASE)
#define TIMER5                          ((GPT_t *) TIMER5_BASE)

#endif
