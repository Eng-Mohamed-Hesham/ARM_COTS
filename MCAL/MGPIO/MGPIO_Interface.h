/*
 * GPIO_interface.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Muhammed Hesham
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

/*Set Half Port*/
#define RIGHT_HALF 				0
#define LEFT_HALF 				1

#define MGPIO_PORTA 		0
#define MGPIO_PORTB 		1
#define MGPIO_PORTC 		2


#define MGPIO_PIN0 			0 
#define MGPIO_PIN1 			1 
#define MGPIO_PIN2 			2 
#define MGPIO_PIN3 			3 
#define MGPIO_PIN4 			4 
#define MGPIO_PIN5 			5 
#define MGPIO_PIN6 			6 
#define MGPIO_PIN7 			7 
#define MGPIO_PIN8 			8 
#define MGPIO_PIN9 			9 
#define MGPIO_PIN10 		10
#define MGPIO_PIN11 		11
#define MGPIO_PIN12 		12
#define MGPIO_PIN13 		13
#define MGPIO_PIN14 		14
#define MGPIO_PIN15 		15

#define MGPIO_INPUT			0b0
#define MGPIO_OUTPUT		0b01
#define MGPIO_AF			0b10
#define MGPIO_ANALOG		0b11


#define MGPIO_PP			0
#define MGPIO_OD			1

#define MGPIO_OUTPUT_LOW_SPEED				0b00
#define MGPIO_OUTPUT_MEDEIUM_SPEED			0b01
#define MGPIO_OUTPUT_HIGH_SPEED				0b10
#define MGPIO_OUTPUT_VERY_HIGH_SPEED		0b11

#define GPIO_RESET							0
#define GPIO_SET							1




void MGPIO_PinMode(u8 Copy_PortNamePortName,
				   u8 Copy_PinNumberPinNum,
				   u8 Copy_PinModeMode);

void MGPIO_voidSetPinOutputType(u8 Copy_PortNamePortName,
								u8 Copy_PinNumberPinNum,
								u8 Copy_OuTputTypeOPTYPE);

void MGPIO_voidSetPinOutputSpeed(u8 Copy_PortNamePortName,
					 			u8 Copy_PinNumberPinNum,
					 			u8 Copy_OutputSpeed);

void MGPIO_voidSetPinValue(u8 Copy_PortNamePortName,
					 			u8 Copy_PinNumberPinNum,
					 			u8 Copy_PINValue);

void MGPIO_voidReSetHalfPortValue(u8 Copy_u8PortName,
								u8 Copy_u8RightOrLeftHalf,
								u16 Copy_u16HalfPortValue);

#endif /* GPIO_INTERFACE_H_ */
