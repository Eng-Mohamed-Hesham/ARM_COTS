/*
 * LED_Interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_LED_LED_INTERFACE_H_
#define INCLUDE_HAL_LED_LED_INTERFACE_H_

typedef enum
{
	OFF=0,
	ON
}LED_STATUS;

void HLED_voidSetLedStatus(u8 A_GPIOPort, u8 A_MGPIOPin,LED_STATUS A_LedStatus);

#endif /* INCLUDE_HAL_LED_LED_INTERFACE_H_ */
