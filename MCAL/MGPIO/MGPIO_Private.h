/*
 * GPIO_private.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Muhammed Hesham
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#define MODER_BIT_MASK			            0b11
#define OUTPUT_SPEED_BIT_MASK				0b11
#define BSRR_SHIFTED_BIT					0b1

#define BSRR_HALF 							16
#define BSRR_HALF_QUARTER	 				24

#define MGPIOA_Base_Addr					0x40020000
#define MGPIOB_Base_Addr					0x40020400
#define MGPIOC_Base_Addr					0x40020800

#define MGPIOx_MODER_OFFSET					0x00
#define MGPIOx_OTYPER_OFFSET				0x04
#define MGPIOx_OSPEEDR_OFFSET				0x08
#define MGPIOx_PUPDR_OFFSET					0x0C
#define MGPIOx_IDR_OFFSET					0x10
#define MGPIOx_ODR_OFFSET					0x14
#define MGPIOx_BSRR_OFFSET					0x18

#define MGPIOB_MODER  						*((u32 volatile *) (MGPIOB_Base_Addr +  MGPIOx_MODER_OFFSET))
#define MGPIOC_MODER  						*((u32 volatile *) (MGPIOC_Base_Addr +  MGPIOx_MODER_OFFSET))
#define MGPIOA_MODER  						*((u32 volatile *) (MGPIOA_Base_Addr +  MGPIOx_MODER_OFFSET))

#define MGPIOA_OTYPER  						*((u32 volatile *) (MGPIOA_Base_Addr +  MGPIOx_OTYPER_OFFSET))
#define MGPIOB_OTYPER  						*((u32 volatile *) (MGPIOB_Base_Addr +  MGPIOx_OTYPER_OFFSET))
#define MGPIOC_OTYPER  						*((u32 volatile *) (MGPIOC_Base_Addr +  MGPIOx_OTYPER_OFFSET))

#define MGPIOA_OSPEEDR  					*((u32 volatile *) (MGPIOA_Base_Addr +  MGPIOx_OSPEEDR_OFFSET))
#define MGPIOB_OSPEEDR  					*((u32 volatile *) (MGPIOB_Base_Addr +  MGPIOx_OSPEEDR_OFFSET))
#define MGPIOC_OSPEEDR  					*((u32 volatile *) (MGPIOC_Base_Addr +  MGPIOx_OSPEEDR_OFFSET))

#define MGPIOA_PUPDR  						*((u32 volatile *) (MGPIOA_Base_Addr +  MGPIOx_PUPDR_OFFSET))
#define MGPIOB_PUPDR  						*((u32 volatile *) (MGPIOB_Base_Addr +  MGPIOx_PUPDR_OFFSET))
#define MGPIOC_PUPDR  						*((u32 volatile *) (MGPIOC_Base_Addr +  MGPIOx_PUPDR_OFFSET))

#define MGPIOA_IDR  						*((u32 volatile *) (MGPIOA_Base_Addr +  MGPIOx_IDR_OFFSET))
#define MGPIOB_IDR  						*((u32 volatile *) (MGPIOB_Base_Addr +  MGPIOx_IDR_OFFSET))
#define MGPIOC_IDR  						*((u32 volatile *) (MGPIOC_Base_Addr +  MGPIOx_IDR_OFFSET))

#define MGPIOA_ODR  						*((u32 volatile *) (MGPIOA_Base_Addr +  MGPIOx_ODR_OFFSET))
#define MGPIOB_ODR  						*((u32 volatile *) (MGPIOB_Base_Addr +  MGPIOx_ODR_OFFSET))
#define MGPIOC_ODR  						*((u32 volatile *) (MGPIOC_Base_Addr +  MGPIOx_ODR_OFFSET))

#define MGPIOA_BSRR  						*((u32 volatile *) (MGPIOA_Base_Addr +  MGPIOx_BSRR_OFFSET))
#define MGPIOB_BSRR  						*((u32 volatile *) (MGPIOB_Base_Addr +  MGPIOx_BSRR_OFFSET))
#define MGPIOC_BSRR  						*((u32 volatile *) (MGPIOC_Base_Addr +  MGPIOx_BSRR_OFFSET))


#endif /* GPIO_PRIVATE_H_ */
