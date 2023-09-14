/*
 * SSD_Program.c
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
/* Lower Layers Inclusions		     				*/
/****************************************************/
#include "../include/MGPIO_Interface.h"
#include "../include/MRCC_Interface.h"
/****************************************************/
/*Self Layer Inclusions								*/
/****************************************************/
#include "../include/LED_Interface.h"
/****************************************************/
/* Self Files Inclusions		     				*/
/****************************************************/
#include "../include/SSD_Interface.h"
#include "../include/SSD_Private.h"
#include "../include/SSD_Cfg.h"


void HSSD_voidDisplayNumber(u8 A_u8GPIOPort,u8 Copy_u8RightOrLeftHalfPort ,u8 A_u8Number)
{
	switch (A_u8Number)
	{
	case zero:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, ZERO);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
	break;
	case one:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, ONE);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
	break;
	case two:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, TWO);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
		break;
	case three:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, THREE);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
		break;
	case four:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0; u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, FOUR);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
		break;
	case five:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, FIVE);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
		break;
	case six:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=6; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, SIX);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
		break;
	case seven:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, SEVEN);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
		break;
	case eight:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, EIGHT);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
		break;
	case nine:
		switch(A_u8GPIOPort){
		case MGPIO_PORTA:
			MRCC_voidEnablePeripheralClock(MRCC_AHB_BUS, MRCC_AHB1_GPIOA);
			for(u8 u8LoopIterator = 0;u8LoopIterator <=7; u8LoopIterator++){
				MGPIO_PinMode(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT);
				MGPIO_voidSetPinOutputType(MGPIO_PORTA, u8LoopIterator, MGPIO_PP);
				MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA, u8LoopIterator, MGPIO_OUTPUT_LOW_SPEED);
			}
			MGPIO_voidReSetHalfPortValue(A_u8GPIOPort, Copy_u8RightOrLeftHalfPort, NINE);
			break;
		case MGPIO_PORTB:
			break;
		case MGPIO_PORTC:
			break;
		default: break;
		}
		break;

	default: break;
	}
}

/*should edited*/
//void HSSD_voidDisplayAscending(u8 A_u8GPIOPort, u16 A_u16DelayinMs)
//{
//	for (u8 i=0; i<10; i++)
//	{
//		HSSD_voidDisplayNumber(A_u8GPIOPort, i);
//	}
//}
/*should edited*/
//void HSSD_voidDisplayDescending(u8 A_u8GPIOPort,u16 A_u16DelayinMs)
//{
//	for (s8 i=9; i>=0; i--)
//	{
//		HSSD_voidDisplayNumber(A_u8GPIOPort, i);
//	}
//}
