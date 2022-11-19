#ifndef __GPIO_PRIVATE_H__
#define __GPIO_PRIVATE_H__
#include "../../LIBRARIES/DIO.h"
#include "../Interrupt_Module/INT_interface.h"
#define LOCK_VAL 0x4C4F434B
#define APB 1 
#define AHB 2 


typedef struct {                                    
  volatile uint32_t  DATA_BITS[255];
  volatile uint32_t  DATA;                                                                            
  volatile uint32_t  DIR;                                                                                  
  volatile uint32_t  IS;                                                                           
  volatile uint32_t  IBE;                                                                    
  volatile uint32_t  IEV;                              
  volatile uint32_t  IM;                                
  volatile uint32_t  RIS;                               
  volatile uint32_t  MIS;                               
  volatile  uint32_t  ICR;                              
  volatile uint32_t  AFSEL;                             
  volatile const  uint32_t  RESERVED1[55];
  volatile uint32_t  DR2R;                             
  volatile uint32_t  DR4R;                              
  volatile uint32_t  DR8R;                              
  volatile uint32_t  ODR;                               
  volatile uint32_t  PUR;                               
  volatile uint32_t  PDR;                               
  volatile uint32_t  SLR;                              
  volatile uint32_t  DEN;                              
  volatile uint32_t  LOCK;                              
  volatile uint32_t  CR;                               
  volatile uint32_t  AMSEL;                             
  volatile uint32_t  PCTL;                            
  volatile uint32_t  ADCCTL;                         
  volatile uint32_t  DMACTL;                           
} GPIO_t;

#define GPIOA_APB_BaseAdd	  0x40004000
#define GPIOA_AHB_BaseAdd	  0x40058000
#define GPIOB_APB_BaseAdd	  0x40005000
#define GPIOB_AHB_BaseAdd	  0x40059000
#define GPIOC_APB_BaseAdd	  0x40006000
#define GPIOC_AHB_BaseAdd	  0x4005A000
#define GPIOD_APB_BaseAdd	  0x40007000
#define GPIOD_AHB_BaseAdd	  0x4005B000
#define GPIOE_APB_BaseAdd	  0x40024000
#define GPIOE_AHB_BaseAdd	  0x4005C000
#define GPIOF_APB_BaseAdd	  0x40025000
#define GPIOF_AHB_BaseAdd	  0x4005D000


#define GPIOA						((GPIO_t*) GPIOA_APB_BaseAdd)
#define GPIOA_AHB				((GPIO_t*) GPIOA_AHB_BaseAdd)
#define GPIOB						((GPIO_t*) GPIOB_APB_BaseAdd)
#define GPIOB_AHB				((GPIO_t*) GPIOB_AHB_BaseAdd)
#define GPIOC						((GPIO_t*) GPIOC_APB_BaseAdd)
#define GPIOC_AHB				((GPIO_t*) GPIOC_AHB_BaseAdd)
#define GPIOD						((GPIO_t*) GPIOD_APB_BaseAdd)
#define GPIOD_AHB				((GPIO_t*) GPIOD_AHB_BaseAdd)
#define GPIOE						((GPIO_t*) GPIOE_APB_BaseAdd)
#define GPIOE_AHB				((GPIO_t*) GPIOE_AHB_BaseAdd)
#define GPIOF						((GPIO_t*) GPIOF_APB_BaseAdd)
#define GPIOF_AHB				((GPIO_t*) GPIOF_AHB_BaseAdd)


typedef struct {                                    
  volatile uint32_t  DID0;                              
  volatile uint32_t  DID1;                              
  volatile uint32_t  DC0;                               
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  DC1;                               
  volatile uint32_t  DC2;                              
  volatile uint32_t  DC3;                               
  volatile uint32_t  DC4;                               
  volatile uint32_t  DC5;                              
  volatile uint32_t  DC6;                               
  volatile uint32_t  DC7;                               
  volatile uint32_t  DC8;                              
  volatile uint32_t  PBORCTL;                        
  volatile const  uint32_t  RESERVED1[3];
  volatile uint32_t  SRCR0;                             
  volatile uint32_t  SRCR1;                           
  volatile uint32_t  SRCR2;                            
  volatile const  uint32_t  RESERVED2;
  volatile uint32_t  RIS;                             
  volatile uint32_t  IMC;                              
  volatile uint32_t  MISC;                             
  volatile uint32_t  RESC;                              
  volatile uint32_t  RCC;                               
  volatile const  uint32_t  RESERVED3[2];
  volatile uint32_t  GPIOHBCTL;                        
  volatile uint32_t  RCC2;                              
  volatile const  uint32_t  RESERVED4[2];
  volatile uint32_t  MOSCCTL;                           
  volatile const  uint32_t  RESERVED5[32];
  volatile uint32_t  RCGC0;                             
  volatile uint32_t  RCGC1;                             
  volatile uint32_t  RCGC2;                             
  volatile const  uint32_t  RESERVED6;
  volatile uint32_t  SCGC0;                             
  volatile uint32_t  SCGC1;                             
  volatile uint32_t  SCGC2;                             
  volatile const  uint32_t  RESERVED7;
  volatile uint32_t  DCGC0;                             
  volatile uint32_t  DCGC1;                            
  volatile uint32_t  DCGC2;                            
  volatile const  uint32_t  RESERVED8[6];
  volatile uint32_t  DSLPCLKCFG;                        
  volatile const  uint32_t  RESERVED9;
  volatile uint32_t  SYSPROP;                           
  volatile uint32_t  PIOSCCAL;                          
  volatile uint32_t  PIOSCSTAT;                         
  volatile const  uint32_t  RESERVED10[2];
  volatile uint32_t  PLLFREQ0;                          
  volatile uint32_t  PLLFREQ1;                          /*!< PLL Frequency 1                                                       */
  volatile uint32_t  PLLSTAT;                           /*!< PLL Status                                                            */
  volatile const  uint32_t  RESERVED11[7];
  volatile uint32_t  SLPPWRCFG;                         /*!< Sleep Power Configuration                                             */
  volatile uint32_t  DSLPPWRCFG;                        /*!< Deep-Sleep Power Configuration                                        */
  volatile uint32_t  DC9;                               /*!< Device Capabilities 9                                                 */
  volatile const  uint32_t  RESERVED12[3];
  volatile uint32_t  NVMSTAT;                           /*!< Non-Volatile Memory Information                                       */
  volatile const  uint32_t  RESERVED13[4];
  volatile uint32_t  LDOSPCTL;                          /*!< LDO Sleep Power Control                                               */
  volatile const  uint32_t  RESERVED14;
  volatile uint32_t  LDODPCTL;                          /*!< LDO Deep-Sleep Power Control                                          */
  volatile const  uint32_t  RESERVED15[80];
  volatile uint32_t  PPWD;                              /*!< Watchdog Timer Peripheral Present                                     */
  volatile uint32_t  PPTIMER;                           /*!< 16/32-Bit General-Purpose Timer Peripheral Present                    */
  volatile uint32_t  PPGPIO;                            /*!< General-Purpose Input/Output Peripheral Present                       */
  volatile uint32_t  PPDMA;                             /*!< Micro Direct Memory Access Peripheral Present                         */
  volatile const  uint32_t  RESERVED16;
  volatile uint32_t  PPHIB;                             /*!< Hibernation Peripheral Present                                        */
  volatile uint32_t  PPUART;                            /*!< Universal Asynchronous Receiver/Transmitter Peripheral Present        */
  volatile uint32_t  PPSSI;                             /*!< Synchronous Serial Interface Peripheral Present                       */
  volatile uint32_t  PPI2C;                             /*!< Inter-Integrated Circuit Peripheral Present                           */
  volatile const  uint32_t  RESERVED17;
  volatile uint32_t  PPUSB;                             /*!< Universal Serial Bus Peripheral Present                               */
  volatile const  uint32_t  RESERVED18[2];
  volatile uint32_t  PPCAN;                             /*!< Controller Area Network Peripheral Present                            */
  volatile uint32_t  PPADC;                             /*!< Analog-to-Digital Converter Peripheral Present                        */
  volatile uint32_t  PPACMP;                            /*!< Analog Comparator Peripheral Present                                  */
  volatile uint32_t  PPPWM;                             /*!< Pulse Width Modulator Peripheral Present                              */
  volatile uint32_t  PPQEI;                             /*!< Quadrature Encoder Interface Peripheral Present                       */
  volatile const  uint32_t  RESERVED19[4];
  volatile uint32_t  PPEEPROM;                          /*!< EEPROM Peripheral Present                                             */
  volatile uint32_t  PPWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Present               */
  volatile const  uint32_t  RESERVED20[104];
  volatile uint32_t  SRWD;                              /*!< Watchdog Timer Software Reset                                         */
  volatile uint32_t  SRTIMER;                           /*!< 16/32-Bit General-Purpose Timer Software Reset                        */
  volatile uint32_t  SRGPIO;                            /*!< General-Purpose Input/Output Software Reset                           */
  volatile uint32_t  SRDMA;                             /*!< Micro Direct Memory Access Software Reset                             */
  volatile const  uint32_t  RESERVED21;
  volatile uint32_t  SRHIB;                             /*!< Hibernation Software Reset                                            */
  volatile uint32_t  SRUART;                            /*!< Universal Asynchronous Receiver/Transmitter Software Reset            */
  volatile uint32_t  SRSSI;                             /*!< Synchronous Serial Interface Software Reset                           */
  volatile uint32_t  SRI2C;                             /*!< Inter-Integrated Circuit Software Reset                               */
  volatile const  uint32_t  RESERVED22;
  volatile uint32_t  SRUSB;                             /*!< Universal Serial Bus Software Reset                                   */
  volatile const  uint32_t  RESERVED23[2];
  volatile uint32_t  SRCAN;                             /*!< Controller Area Network Software Reset                                */
  volatile uint32_t  SRADC;                             /*!< Analog-to-Digital Converter Software Reset                            */
  volatile uint32_t  SRACMP;                            /*!< Analog Comparator Software Reset                                      */
  volatile uint32_t  SRPWM;                             /*!< Pulse Width Modulator Software Reset                                  */
  volatile uint32_t  SRQEI;                             /*!< Quadrature Encoder Interface Software Reset                           */
  volatile const  uint32_t  RESERVED24[4];
  volatile uint32_t  SREEPROM;                          /*!< EEPROM Software Reset                                                 */
  volatile uint32_t  SRWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Software Reset                   */
  volatile const  uint32_t  RESERVED25[40];
  volatile uint32_t  RCGCWD;                            /*!< Watchdog Timer Run Mode Clock Gating Control                          */
  volatile uint32_t  RCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control         */
  volatile uint32_t  RCGCGPIO;                          /*!< General-Purpose Input/Output Run Mode Clock Gating Control            */
  volatile uint32_t  RCGCDMA;                           /*!< Micro Direct Memory Access Run Mode Clock Gating Control              */
  volatile const  uint32_t  RESERVED26;
  volatile uint32_t  RCGCHIB;                           /*!< Hibernation Run Mode Clock Gating Control                             */
  volatile uint32_t  RCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating
                                                         Control                                                               */
  volatile uint32_t  RCGCSSI;                           /*!< Synchronous Serial Interface Run Mode Clock Gating Control            */
  volatile uint32_t  RCGCI2C;                           /*!< Inter-Integrated Circuit Run Mode Clock Gating Control                */
  volatile const  uint32_t  RESERVED27;
  volatile uint32_t  RCGCUSB;                           /*!< Universal Serial Bus Run Mode Clock Gating Control                    */
  volatile const  uint32_t  RESERVED28[2];
  volatile uint32_t  RCGCCAN;                           /*!< Controller Area Network Run Mode Clock Gating Control                 */
  volatile uint32_t  RCGCADC;                           /*!< Analog-to-Digital Converter Run Mode Clock Gating Control             */
  volatile uint32_t  RCGCACMP;                          /*!< Analog Comparator Run Mode Clock Gating Control                       */
  volatile uint32_t  RCGCPWM;                           /*!< Pulse Width Modulator Run Mode Clock Gating Control                   */
  volatile uint32_t  RCGCQEI;                           /*!< Quadrature Encoder Interface Run Mode Clock Gating Control            */
  volatile const  uint32_t  RESERVED29[4];
  volatile uint32_t  RCGCEEPROM;                        /*!< EEPROM Run Mode Clock Gating Control                                  */
  volatile uint32_t  RCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control    */
  volatile const  uint32_t  RESERVED30[40];
  volatile uint32_t  SCGCWD;                            /*!< Watchdog Timer Sleep Mode Clock Gating Control                        */
  volatile uint32_t  SCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control       */
  volatile uint32_t  SCGCGPIO;                          /*!< General-Purpose Input/Output Sleep Mode Clock Gating Control          */
  volatile uint32_t  SCGCDMA;                           /*!< Micro Direct Memory Access Sleep Mode Clock Gating Control            */
  volatile const  uint32_t  RESERVED31;
  volatile uint32_t  SCGCHIB;                           /*!< Hibernation Sleep Mode Clock Gating Control                           */
  volatile uint32_t  SCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Sleep Mode Clock
                                                         Gating Control                                                        */
  volatile uint32_t  SCGCSSI;                           /*!< Synchronous Serial Interface Sleep Mode Clock Gating Control          */
  volatile uint32_t  SCGCI2C;                           /*!< Inter-Integrated Circuit Sleep Mode Clock Gating Control              */
  volatile const  uint32_t  RESERVED32;
  volatile uint32_t  SCGCUSB;                           /*!< Universal Serial Bus Sleep Mode Clock Gating Control                  */
  volatile const  uint32_t  RESERVED33[2];
  volatile uint32_t  SCGCCAN;                           /*!< Controller Area Network Sleep Mode Clock Gating Control               */
  volatile uint32_t  SCGCADC;                           /*!< Analog-to-Digital Converter Sleep Mode Clock Gating Control           */
  volatile uint32_t  SCGCACMP;                          /*!< Analog Comparator Sleep Mode Clock Gating Control                     */
  volatile uint32_t  SCGCPWM;                           /*!< Pulse Width Modulator Sleep Mode Clock Gating Control                 */
  volatile uint32_t  SCGCQEI;                           /*!< Quadrature Encoder Interface Sleep Mode Clock Gating Control          */
  volatile const  uint32_t  RESERVED34[4];
  volatile uint32_t  SCGCEEPROM;                        /*!< EEPROM Sleep Mode Clock Gating Control                                */
  volatile uint32_t  SCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating
                                                         Control                                                               */
  volatile const  uint32_t  RESERVED35[40];
  volatile uint32_t  DCGCWD;                            /*!< Watchdog Timer Deep-Sleep Mode Clock Gating Control                   */
  volatile uint32_t  DCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                         Control                                                               */
  volatile uint32_t  DCGCGPIO;                          /*!< General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control     */
  volatile uint32_t  DCGCDMA;                           /*!< Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control       */
  volatile const  uint32_t  RESERVED36;
  volatile uint32_t  DCGCHIB;                           /*!< Hibernation Deep-Sleep Mode Clock Gating Control                      */
  volatile uint32_t  DCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode
                                                         Clock Gating Control                                                  */
  volatile uint32_t  DCGCSSI;                           /*!< Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control     */
  volatile uint32_t  DCGCI2C;                           /*!< Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control         */
  volatile const  uint32_t  RESERVED37;
  volatile uint32_t  DCGCUSB;                           /*!< Universal Serial Bus Deep-Sleep Mode Clock Gating Control             */
  volatile const  uint32_t  RESERVED38[2];
  volatile uint32_t  DCGCCAN;                           /*!< Controller Area Network Deep-Sleep Mode Clock Gating Control          */
  volatile uint32_t  DCGCADC;                           /*!< Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control      */
  volatile uint32_t  DCGCACMP;                          /*!< Analog Comparator Deep-Sleep Mode Clock Gating Control                */
  volatile uint32_t  DCGCPWM;                           /*!< Pulse Width Modulator Deep-Sleep Mode Clock Gating Control            */
  volatile uint32_t  DCGCQEI;                           /*!< Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control     */
  volatile const  uint32_t  RESERVED39[4];
  volatile uint32_t  DCGCEEPROM;                        /*!< EEPROM Deep-Sleep Mode Clock Gating Control                           */
  volatile uint32_t  DCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                         Control                                                               */
  volatile const  uint32_t  RESERVED40[104];
  volatile uint32_t  PRWD;                              /*!< Watchdog Timer Peripheral Ready                                       */
  volatile uint32_t  PRTIMER;                           /*!< 16/32-Bit General-Purpose Timer Peripheral Ready                      */
  volatile uint32_t  PRGPIO;                            /*!< General-Purpose Input/Output Peripheral Ready                         */
  volatile uint32_t  PRDMA;                             /*!< Micro Direct Memory Access Peripheral Ready                           */
  volatile const  uint32_t  RESERVED41;
  volatile uint32_t  PRHIB;                             /*!< Hibernation Peripheral Ready                                          */
  volatile uint32_t  PRUART;                            /*!< Universal Asynchronous Receiver/Transmitter Peripheral Ready          */
  volatile uint32_t  PRSSI;                             /*!< Synchronous Serial Interface Peripheral Ready                         */
  volatile uint32_t  PRI2C;                             /*!< Inter-Integrated Circuit Peripheral Ready                             */
  volatile const  uint32_t  RESERVED42;
  volatile uint32_t  PRUSB;                             /*!< Universal Serial Bus Peripheral Ready                                 */
  volatile const  uint32_t  RESERVED43[2];
  volatile uint32_t  PRCAN;                             /*!< Controller Area Network Peripheral Ready                              */
  volatile uint32_t  PRADC;                             /*!< Analog-to-Digital Converter Peripheral Ready                          */
  volatile uint32_t  PRACMP;                            /*!< Analog Comparator Peripheral Ready                                    */
  volatile uint32_t  PRPWM;                             /*!< Pulse Width Modulator Peripheral Ready                                */
  volatile uint32_t  PRQEI;                             /*!< Quadrature Encoder Interface Peripheral Ready                         */
  volatile const  uint32_t  RESERVED44[4];
  volatile uint32_t  PREEPROM;                          /*!< EEPROM Peripheral Ready                                               */
  volatile uint32_t  PRWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Ready                 */
} SYSCTL_t;


#define SYSCTL_BASE	 			0x400FE000UL
#define SYSCTL						((SYSCTL_t*) SYSCTL_BASE)

#endif
