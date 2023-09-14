/*
 * LED_Program.c
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"



/****************************************************/
/* Self Layer Inclusions		     				*/
/****************************************************/
#include "../include/MGPIO_Interface.h"
#include "../include/MRCC_Interface.h"

/****************************************************/
/*Self Files Inclusions								*/
/****************************************************/
#include "../include/LED_Interface.h"
#include "../include/LED_Private.h"
#include "../include/LED_Cfg.h"

/*Enable GPIOA Clock*/



void HLED_voidSetLedStatus(u8 A_GPIOPort, u8 A_MGPIOPin,LED_STATUS A_LedStatus)
{
	switch (A_GPIOPort){
	case MGPIO_PORTA:
		switch (A_LedStatus){
		case ON:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			MGPIO_PinMode(MGPIO_PORTA, A_MGPIOPin, MGPIO_OUTPUT);
			MGPIO_voidSetPinOutputType(MGPIO_PORTA, A_MGPIOPin, MGPIO_PP);
			MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, A_MGPIOPin, MGPIO_OUTPUT_LOW_SPEED);
			MGPIO_voidSetPinValue(MGPIO_PORTA, A_MGPIOPin, GPIO_SET);
			break;
		case OFF:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			MGPIO_PinMode(MGPIO_PORTA, A_MGPIOPin, MGPIO_OUTPUT);
			MGPIO_voidSetPinOutputType(MGPIO_PORTA, A_MGPIOPin, MGPIO_PP);
			MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, A_MGPIOPin, MGPIO_OUTPUT_LOW_SPEED);
			MGPIO_voidSetPinValue(MGPIO_PORTA, A_MGPIOPin, GPIO_RESET);
			break;
		default:
			break;
		}
	break;
	case MGPIO_PORTB:
		switch (A_LedStatus){
		case ON:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOB);
			MGPIO_PinMode(MGPIO_PORTB, A_MGPIOPin, MGPIO_OUTPUT);
			MGPIO_voidSetPinOutputType(MGPIO_PORTB, A_MGPIOPin, MGPIO_PP);
			MGPIO_voidSetPinOutputSpeed(MGPIO_PORTB, A_MGPIOPin, MGPIO_OUTPUT_LOW_SPEED);
			MGPIO_voidSetPinValue(MGPIO_PORTB, A_MGPIOPin, GPIO_SET);
			break;
		case OFF:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOB);
			MGPIO_PinMode(MGPIO_PORTB, A_MGPIOPin, MGPIO_OUTPUT);
			MGPIO_voidSetPinOutputType(MGPIO_PORTB, A_MGPIOPin, MGPIO_PP);
			MGPIO_voidSetPinOutputSpeed(MGPIO_PORTB, A_MGPIOPin, MGPIO_OUTPUT_LOW_SPEED);
			MGPIO_voidSetPinValue(MGPIO_PORTB, A_MGPIOPin, GPIO_RESET);
			break;
		default:
			break;
		}
	break;
	case MGPIO_PORTC:
		switch (A_LedStatus){
		case ON:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOC);
			MGPIO_PinMode(MGPIO_PORTC, A_MGPIOPin, MGPIO_OUTPUT);
			MGPIO_voidSetPinOutputType(MGPIO_PORTC, A_MGPIOPin, MGPIO_PP);
			MGPIO_voidSetPinOutputSpeed(MGPIO_PORTC, A_MGPIOPin, MGPIO_OUTPUT_LOW_SPEED);
			MGPIO_voidSetPinValue(MGPIO_PORTC, A_MGPIOPin, GPIO_SET);
			break;
		case OFF:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOC);
			MGPIO_PinMode(MGPIO_PORTC, A_MGPIOPin, MGPIO_OUTPUT);
			MGPIO_voidSetPinOutputType(MGPIO_PORTC, A_MGPIOPin, MGPIO_PP);
			MGPIO_voidSetPinOutputSpeed(MGPIO_PORTC, A_MGPIOPin, MGPIO_OUTPUT_LOW_SPEED);
			MGPIO_voidSetPinValue(MGPIO_PORTC, A_MGPIOPin, GPIO_RESET);
			break;
		default:
			break;
		}
	break;
	default:
		break;
	}
}



