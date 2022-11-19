#include "GPIO_interface.h" 



void GPIO_pinInit(PORT_t port,PIN_t pin,PIN_DIR_t dir,Internal_Resistor_t intResistor, ANALOG_CTL_t analogStatus,ALTER_FUNC_t altfunc)
{
	GPIO_t * CurrPort ; 
	
	switch(port)
	{
		case PORT_A:	
				#if BUS_TYPE == APB
						CurrPort = GPIOA; 
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOA_AHB; 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
				#endif 
		break;
		case PORT_B:
				#if BUS_TYPE == APB
						CurrPort = GPIOB;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOB_AHB;
				#endif 
		break;
		case PORT_C:
				#if BUS_TYPE == APB
						CurrPort = GPIOC;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOC_AHB;
				#endif 
		break;
		case PORT_D:
				#if BUS_TYPE == APB
						CurrPort = GPIOD;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOD_AHB;
				#endif 
		break;
		case PORT_E:
				#if BUS_TYPE == APB
						CurrPort = GPIOE;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOE_AHB;
				#endif 
		break;
		case PORT_F:
				#if BUS_TYPE == APB
						CurrPort = GPIOF;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOF_AHB;
				#endif 
		break;
	}
	SYSCTL->RCGCGPIO |= (1U<<port) ;	// enable clock to port
	int i = 0 ; 
	while(i++ < 16000); 
	CurrPort->LOCK |= LOCK_VAL ; 
	CurrPort->CR = 0x01 ;  
	if(dir == INPUT)
	{
		CLEAR_BIT(CurrPort->DIR,pin);  	// set direction as input 
	}
	else if(dir == OUTPUT)
	{
		SET_BIT(CurrPort->DIR,pin); 			// set direction as output 
	}
	if(altfunc != ALT_DIS)
	{
		CurrPort->AFSEL |= (1U<<pin); 
		CurrPort->ADCCTL |=(altfunc<< (4*pin)); 
	}
	switch(intResistor)
	{
		case PULL_DOWN: SET_BIT(CurrPort->PDR,pin); 
			break; 
		case PULL_UP : SET_BIT(CurrPort->PUR,pin); 
			break; 
		case OPEN_DRAIN:SET_BIT(CurrPort->ODR,pin); 
			break; 
		default:
			break; 
	}
	if(analogStatus == ANALOG_EN)
	{
		SET_BIT(CurrPort->AMSEL,pin); 
		CLEAR_BIT(CurrPort->DEN,pin); 
	}
	else if(analogStatus ==ANALOG_DIS)
	{
		CLEAR_BIT(CurrPort->AMSEL,pin);
		SET_BIT(CurrPort->DEN,pin); 
	}
	
}


void GPIO_portInit(PORT_t port,PIN_t pin,PIN_DIR_t dir,Internal_Resistor_t intResistor, ANALOG_CTL_t analogStatus)
{
	GPIO_t * CurrPort ; 
	SYSCTL->RCGCGPIO |= (1U<<port) ;	// enable clock to port
	switch(port)
	{
		case PORT_A:	
				#if BUS_TYPE == APB
						CurrPort = GPIOA; 
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOA_AHB; 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
				#endif 
		break;
		case PORT_B:
				#if BUS_TYPE == APB
						CurrPort = GPIOB;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOB_AHB;
				#endif 
		break;
		case PORT_C:
				#if BUS_TYPE == APB
						CurrPort = GPIOC;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOC_AHB;
				#endif 
		break;
		case PORT_D:
				#if BUS_TYPE == APB
						CurrPort = GPIOD;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOD_AHB;
				#endif 
		break;
		case PORT_E:
				#if BUS_TYPE == APB
						CurrPort = GPIOE;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOE_AHB;
				#endif 
		break;
		case PORT_F:
				#if BUS_TYPE == APB
						CurrPort = GPIOF;
				#elif BUS_TYPE == AHB 
						SET_BIT(SYSCTL->GPIOHBCTL , port) ; // enable AHP 
						CurrPort = GPIOF_AHB;
				#endif 
		break;
	}
	PORT_WRITE(CurrPort->CR,0xFF) ; 
	if(dir == INPUT)
	{
		PORT_WRITE(CurrPort->DIR,0x00); 	// set direction as input 
	}
	else if(dir == OUTPUT)
	{
		PORT_WRITE(CurrPort->DIR,0xFF); 			// set direction as output 
	}
	switch(intResistor)
	{
		case PULL_DOWN: PORT_WRITE(CurrPort->PDR,0xFF); 
			break; 
		case PULL_UP : PORT_WRITE(CurrPort->PUR,0xFF); 
			break; 
		case OPEN_DRAIN:PORT_WRITE(CurrPort->ODR,0xFF); 
			break; 
		default:
			break; 
	}
	if(analogStatus == ANALOG_EN)
	{
		PORT_WRITE(CurrPort->AMSEL,0xFF);  
		PORT_WRITE(CurrPort->DEN,0x00); 
	}
	else if(analogStatus ==ANALOG_DIS)
	{
		PORT_WRITE(CurrPort->AMSEL,0x00);  
		PORT_WRITE(CurrPort->DEN,0xFF); 
	}
	
}









void GPIO_digitalPin_write(PORT_t port,PIN_t pin,PIN_LEVEL_t level)
{
	GPIO_t * CurrPort ; 

	switch(port)
	{
		case PORT_A:	
				#if BUS_TYPE == APB
						CurrPort = GPIOA; 

				#elif BUS_TYPE == AHB 
						CurrPort = GPIOA_AHB; 

				#endif 
		break;
		case PORT_B:
				#if BUS_TYPE == APB
						CurrPort = GPIOB;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOB_AHB;
				#endif 
		break;
		case PORT_C:
				#if BUS_TYPE == APB
						CurrPort = GPIOC;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOC_AHB;
				#endif 
		break;
		case PORT_D:
				#if BUS_TYPE == APB
						CurrPort = GPIOD;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOD_AHB;
				#endif 
		break;
		case PORT_E:
				#if BUS_TYPE == APB
						CurrPort = GPIOE;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOE_AHB;
				#endif 
		break;
		case PORT_F:
				#if BUS_TYPE == APB
						CurrPort = GPIOF;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOF_AHB;
				#endif 
		break;
	}
	

	switch(level)
	{
		case HIGH : 	
								SET_BIT(CurrPort->DATA , pin);  
		break; 
		case LOW:		
							CLEAR_BIT(CurrPort->DATA , pin);  
		break ; 
	}
	
	
}


void GPIO_digitalPin_toggle(PORT_t port,PIN_t pin)
{
		GPIO_t * CurrPort ; 

	switch(port)
	{
		case PORT_A:	
				#if BUS_TYPE == APB
						CurrPort = GPIOA; 

				#elif BUS_TYPE == AHB 
						CurrPort = GPIOA_AHB; 

				#endif 
		break;
		case PORT_B:
				#if BUS_TYPE == APB
						CurrPort = GPIOB;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOB_AHB;
				#endif 
		break;
		case PORT_C:
				#if BUS_TYPE == APB
						CurrPort = GPIOC;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOC_AHB;
				#endif 
		break;
		case PORT_D:
				#if BUS_TYPE == APB
						CurrPort = GPIOD;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOD_AHB;
				#endif 
		break;
		case PORT_E:
				#if BUS_TYPE == APB
						CurrPort = GPIOE;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOE_AHB;
				#endif 
		break;
		case PORT_F:
				#if BUS_TYPE == APB
						CurrPort = GPIOF;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOF_AHB;
				#endif 
		break;
	}
	TOGGLE_BIT(CurrPort->DATA,pin); 
}



bool GPIO_digitalPin_read(PORT_t port,PIN_t pin)
{
		GPIO_t * CurrPort ; 

	switch(port)
	{
		case PORT_A:	
				#if BUS_TYPE == APB
						CurrPort = GPIOA; 

				#elif BUS_TYPE == AHB 
						CurrPort = GPIOA_AHB; 

				#endif 
		break;
		case PORT_B:
				#if BUS_TYPE == APB
						CurrPort = GPIOB;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOB_AHB;
				#endif 
		break;
		case PORT_C:
				#if BUS_TYPE == APB
						CurrPort = GPIOC;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOC_AHB;
				#endif 
		break;
		case PORT_D:
				#if BUS_TYPE == APB
						CurrPort = GPIOD;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOD_AHB;
				#endif 
		break;
		case PORT_E:
				#if BUS_TYPE == APB
						CurrPort = GPIOE;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOE_AHB;
				#endif 
		break;
		case PORT_F:
				#if BUS_TYPE == APB
						CurrPort = GPIOF;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOF_AHB;
				#endif 
		break;
	}
	
		return READ_BIT(CurrPort->DATA , pin);  

}

void GPIO_digitalPort_write(PORT_t port,uint8_t  data)
{
	GPIO_t * CurrPort ; 
	switch(port)
	{
		case PORT_A:	
				#if BUS_TYPE == APB
						CurrPort = GPIOA; 

				#elif BUS_TYPE == AHB 
						CurrPort = GPIOA_AHB; 

				#endif 
		break;
		case PORT_B:
				#if BUS_TYPE == APB
						CurrPort = GPIOB;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOB_AHB;
				#endif 
		break;
		case PORT_C:
				#if BUS_TYPE == APB
						CurrPort = GPIOC;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOC_AHB;
				#endif 
		break;
		case PORT_D:
				#if BUS_TYPE == APB
						CurrPort = GPIOD;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOD_AHB;
				#endif 
		break;
		case PORT_E:
				#if BUS_TYPE == APB
						CurrPort = GPIOE;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOE_AHB;
				#endif 
		break;
		case PORT_F:
				#if BUS_TYPE == APB
						CurrPort = GPIOF;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOF_AHB;
				#endif 
		break;
	}
	CurrPort->DATA = data ; 
}

uint8_t GPIO_digitalPort_read(PORT_t port)
{
	GPIO_t * CurrPort ; 
	switch(port)
	{
		case PORT_A:	
				#if BUS_TYPE == APB
						CurrPort = GPIOA; 

				#elif BUS_TYPE == AHB 
						CurrPort = GPIOA_AHB; 
						  // enable AHP 

				#endif 
		break;
		case PORT_B:
				#if BUS_TYPE == APB
						CurrPort = GPIOB;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOB_AHB;
				#endif 
		break;
		case PORT_C:
				#if BUS_TYPE == APB
						CurrPort = GPIOC;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOC_AHB;
				#endif 
		break;
		case PORT_D:
				#if BUS_TYPE == APB
						CurrPort = GPIOD;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOD_AHB;
				#endif 
		break;
		case PORT_E:
				#if BUS_TYPE == APB
						CurrPort = GPIOE;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOE_AHB;
				#endif 
		break;
		case PORT_F:
				#if BUS_TYPE == APB
						CurrPort = GPIOF;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOF_AHB;
				#endif 
		break;
	}
	return CurrPort->DATA  ; 
}


void EXT_INT_init(PORT_t port,PIN_t pin,Internal_Resistor_t intResistor,INT_Trig_t trig ,callback_fptr_t INT_callback )
{
	GPIO_t * CurrPort ; 
	SYSCTL->RCGCGPIO |= (1U<<port) ;	// enable clock to port
	switch(port)
	{
		case PORT_A:	
				#if BUS_TYPE == APB
						CurrPort = GPIOA; 
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOA_AHB; 
						  // enable AHP 
				#endif 
				GPIOA_setCallBack(INT_callback); 
		break;
		case PORT_B:
				#if BUS_TYPE == APB
						CurrPort = GPIOB;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOB_AHB;
				#endif 
				GPIOB_setCallBack(INT_callback); 
		break;
		case PORT_C:
				#if BUS_TYPE == APB
						CurrPort = GPIOC;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOC_AHB;
				#endif 
				GPIOC_setCallBack(INT_callback); 
		break;
		case PORT_D:
				#if BUS_TYPE == APB
						CurrPort = GPIOD;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOD_AHB;
				#endif 
				GPIOD_setCallBack(INT_callback); 
		break;
		case PORT_E:
				#if BUS_TYPE == APB
						CurrPort = GPIOE;
				#elif BUS_TYPE == AHB 
						  // enable AHP 
						CurrPort = GPIOE_AHB;
				#endif 
				GPIOE_setCallBack(INT_callback); 
		break;
		case PORT_F:
				#if BUS_TYPE == APB
						CurrPort = GPIOF;
				#elif BUS_TYPE == AHB 
						CurrPort = GPIOF_AHB;
				#endif 
				GPIOF_setCallBack(INT_callback); 
		break;
	}
	CLEAR_BIT(CurrPort->DIR,pin); 			// input 
	CurrPort->LOCK |= LOCK_VAL ; 
	CurrPort->CR = 0x01 ;  
		switch(intResistor)
	{
		case PULL_DOWN: SET_BIT(CurrPort->PDR,pin); 
			break; 
		case PULL_UP : SET_BIT(CurrPort->PUR,pin); 
			break; 
		case OPEN_DRAIN:SET_BIT(CurrPort->ODR,pin); 
			break; 
		default:
			break; 
	}
	switch(trig)
	{
		case Rising_Edge: CLEAR_BIT(CurrPort->IS,pin); // detecting edges 
											SET_BIT(CurrPort->IEV,pin) ; // rising edge 
			break; 
		case Falling_Edge:CLEAR_BIT(CurrPort->IS,pin); // detecting edges 
											CLEAR_BIT(CurrPort->IEV,pin) ; // faling edge 
			break; 
		case Rising_Falling_Edge:CLEAR_BIT(CurrPort->IS,pin); // detecting edges 
															SET_BIT(CurrPort->IBE,pin); // bith edges 
			break;
		case High_Level:	SET_BIT(CurrPort->IS,pin);	// detecting Levels 
											SET_BIT(CurrPort->IEV,pin) ; // high level 
			break; 
		case Low_Level:	SET_BIT(CurrPort->IS,pin);	// detecting Levels 
										CLEAR_BIT(CurrPort->IEV,pin) ; // low level 
			break; 
	}
	SET_BIT(CurrPort->DEN,pin); 													// enable digital functionality 
#if IS_INTERRUPT_MASKED == MASKED
	SET_BIT(CurrPort->IM,pin); 														// unmask the interrupt 
#endif
	
	switch(port)
	{																											// Enable interrupt 
		case PORT_A:SET_BIT(NVIC->ISER[0],NVIC_PORTA_INT);
		break;
		case PORT_B:SET_BIT(NVIC->ISER[0],NVIC_PORTB_INT);
		break;
		case PORT_C:SET_BIT(NVIC->ISER[0],NVIC_PORTC_INT);
		break;
		case PORT_D:SET_BIT(NVIC->ISER[0],NVIC_PORTD_INT);
		break;
		case PORT_E:SET_BIT(NVIC->ISER[0],NVIC_PORTE_INT);
		break;
		case PORT_F:SET_BIT(NVIC->ISER[0],NVIC_PORTF_INT);
		break;
	}
}


