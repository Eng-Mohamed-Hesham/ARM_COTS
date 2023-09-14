/*
 * SSD_Interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_HAL_SSD_SSD_INTERFACE_H_
#define INCLUDE_HAL_SSD_SSD_INTERFACE_H_

#define zero	0
#define one		1
#define two		2
#define three	3
#define four	4
#define five	5
#define six		6
#define seven	7
#define eight	8
#define nine	9


void HSSD_voidDisplayNumber(u8 A_u8GPIOPort,
							u8 Copy_u8RightOrLeftHalfPort ,
							u8 A_u8Number);

//void HSSD_voidDisplayAscending(u8 A_GPIOPort,u16 A_u16DelayinMs);

//void HSSD_voidDisplayDescending(u8 A_GPIOPort,u16 A_u16DelayinMs);

#endif /* INCLUDE_HAL_SSD_SSD_INTERFACE_H_ */
