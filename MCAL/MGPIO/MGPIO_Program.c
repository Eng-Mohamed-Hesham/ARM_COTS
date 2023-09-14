/*Library Inclusions*/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

/*Lower Layers Inclusions*/

/*Self Inclusions*/

/*Self Files Inclusions*/
#include "../include/MGPIO_Interface.h"
#include "../include/MGPIO_Private.h"
#include "../include/MGPIO_Config.h"



void MGPIO_PinMode(u8 Copy_PortNamePortName,
				   u8 Copy_PinNumberPinNum,
				   u8 Copy_PinModeMode) {
	switch (Copy_PortNamePortName)
	{
	case MGPIO_PORTA:
		switch (Copy_PinModeMode)
		{
		case MGPIO_INPUT:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOA_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOA_MODER |= (MGPIO_INPUT<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_OUTPUT:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOA_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOA_MODER |= (MGPIO_OUTPUT<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_AF:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOA_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOA_MODER |= (MGPIO_AF<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_ANALOG:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOA_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOA_MODER |= (MGPIO_ANALOG<< (Copy_PinNumberPinNum * 2));
			break;
		default:
			break;
		}
		break;
	case MGPIO_PORTB:
		switch (Copy_PinModeMode)
		{
		case MGPIO_INPUT:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOB_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOB_MODER |= (MGPIO_INPUT<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_OUTPUT:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOB_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOB_MODER |= (MGPIO_OUTPUT<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_AF:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOB_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOB_MODER |= (MGPIO_AF<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_ANALOG:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOB_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOB_MODER |= (MGPIO_ANALOG<< (Copy_PinNumberPinNum * 2));
			break;
		default:
			break;
		}
		break;	
	case MGPIO_PORTC:
		switch (Copy_PinModeMode)
		{
		case MGPIO_INPUT:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOC_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOC_MODER |= (MGPIO_INPUT<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_OUTPUT:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOC_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOC_MODER |= (MGPIO_OUTPUT<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_AF:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOC_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOC_MODER |= (MGPIO_AF<< (Copy_PinNumberPinNum * 2));
			break;
		case MGPIO_ANALOG:
			/*BitMasking "Clear the 2 Bits Associated to the pin"*/
			MGPIOC_MODER &= ~(MODER_BIT_MASK<< (Copy_PinNumberPinNum*2));
			/*Set The Mode of the Pin*/
			MGPIOC_MODER |= (MGPIO_ANALOG<< (Copy_PinNumberPinNum * 2));
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void MGPIO_voidSetPinOutputType(u8 Copy_PortNamePortName,
								u8 Copy_PinNumberPinNum,
								u8 Copy_OuTputTypeOPTYPE) {
	if(Copy_PinNumberPinNum <=15 ){
		switch (Copy_PortNamePortName)
		{
		case MGPIO_PORTA:
			switch (Copy_OuTputTypeOPTYPE)
			{
			case MGPIO_PP:
				/*Clear the corresponding bit to make pin output push pull*/
				CLR_BIT(MGPIOA_OTYPER,Copy_PinNumberPinNum);
				break;
			case MGPIO_OD:
				/*Clear the corresponding bit to make pin output Open Drain*/
				SET_BIT(MGPIOA_OTYPER,Copy_PinNumberPinNum);
				break;
			default:
				break;
			}
			break;
		case MGPIO_PORTB:
			switch (Copy_OuTputTypeOPTYPE)
			{
			case MGPIO_PP:
				/*Clear the corresponding bit to make pin output push pull*/
				CLR_BIT(MGPIOB_OTYPER,Copy_PinNumberPinNum);
				break;
			case MGPIO_OD:
				/*Clear the corresponding bit to make pin output Open Drain*/
				SET_BIT(MGPIOB_OTYPER,Copy_PinNumberPinNum);
				break;
			default:
				break;
			}
			break;
		case MGPIO_PORTC:
			switch (Copy_OuTputTypeOPTYPE)
			{
			case MGPIO_PP:
				/*Clear the corresponding bit to make pin output push pull*/
				CLR_BIT(MGPIOC_OTYPER,Copy_PinNumberPinNum);
				break;
			case MGPIO_OD:
				/*Clear the corresponding bit to make pin output Open Drain*/
				SET_BIT(MGPIOC_OTYPER,Copy_PinNumberPinNum);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	else {
		//error pin number
	}
}


void MGPIO_voidSetPinOutputSpeed(u8 Copy_PortNamePortName,
					 			 u8 Copy_PinNumberPinNum,
					 			 u8 Copy_OutputSpeed) {
	if(Copy_OutputSpeed <=  MGPIO_OUTPUT_VERY_HIGH_SPEED){
	switch (Copy_PortNamePortName)
	{
	case MGPIO_PORTA:
		MGPIOA_OSPEEDR &= ~(OUTPUT_SPEED_BIT_MASK <<  (Copy_PinNumberPinNum *2));
		MGPIOA_OSPEEDR |= (Copy_OutputSpeed <<  (Copy_PinNumberPinNum *2));
		break;
	case MGPIO_PORTB:
		MGPIOB_OSPEEDR &= ~(OUTPUT_SPEED_BIT_MASK <<  (Copy_PinNumberPinNum *2));
		MGPIOB_OSPEEDR |= (Copy_OutputSpeed <<  (Copy_PinNumberPinNum *2));
		break;	
	case MGPIO_PORTC:
		MGPIOC_OSPEEDR &= ~(OUTPUT_SPEED_BIT_MASK <<  (Copy_PinNumberPinNum *2));
		MGPIOC_OSPEEDR |= (Copy_OutputSpeed <<  (Copy_PinNumberPinNum *2));
		break;
	default:
		break;
	}
	}else {
		//error SPEED
	}

}


void MGPIO_voidSetPinValue(u8 Copy_PortNamePortName,
					 	   u8 Copy_PinNumberPinNum,
					 	   u8 Copy_PINValue){

	switch (Copy_PortNamePortName)
	{
	case MGPIO_PORTA:
		switch (Copy_PINValue)
		{
		case GPIO_SET:
			MGPIOA_BSRR = (BSRR_SHIFTED_BIT << (Copy_PinNumberPinNum));
			break;
		case GPIO_RESET:
			MGPIOA_BSRR = (BSRR_SHIFTED_BIT << (Copy_PinNumberPinNum + 16));
			break;
		default:
			break;
		}
		break;
	case MGPIO_PORTB:
		switch (Copy_PINValue)
		{
		case GPIO_SET:
			MGPIOB_BSRR = (BSRR_SHIFTED_BIT << (Copy_PinNumberPinNum));
			break;
		case GPIO_RESET:
			MGPIOB_BSRR = (BSRR_SHIFTED_BIT << (Copy_PinNumberPinNum + 16));
			break;
		default:
			break;
		}
		break;	
	case MGPIO_PORTC:
		switch (Copy_PINValue)
		{
		case GPIO_SET:
			MGPIOC_BSRR = (BSRR_SHIFTED_BIT << (Copy_PinNumberPinNum));
			break;
		case GPIO_RESET:
			MGPIOC_BSRR = (BSRR_SHIFTED_BIT << (Copy_PinNumberPinNum + BSRR_HALF));
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}	
}

void MGPIO_voidReSetHalfPortValue(u8 Copy_u8PortName,
								  u8 Copy_u8RightOrLeftHalf,
								  u16 Copy_u16HalfPortValue){
	switch(Copy_u8PortName){
	case MGPIO_PORTA:
		switch(Copy_u8RightOrLeftHalf){
		case RIGHT_HALF:
			MGPIOA_ODR &= 0x00;
			MGPIOA_ODR |= (~Copy_u16HalfPortValue);
			//0000000000111111
			break;
		case LEFT_HALF:
			MGPIOA_ODR &= (0x00) << 8 ;
			MGPIOA_ODR |= (~Copy_u16HalfPortValue) << 8;
			//0011111100000000
			break;
		default:
			break;
		}
		break;
	case MGPIO_PORTB:
		break;
	case MGPIO_PORTC:
		break;
	default:
		break;
	}

}
