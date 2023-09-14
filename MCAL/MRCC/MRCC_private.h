#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H

/*Base Address*/
#define MRCC_BASE_ADDR 			0x40023800

/*Offsets*/
#define MRCC_CR_OFFSET			0x00
#define MRCC_CFGR_OFFSET		0x08
#define MRCC_PLLCFGR_OFFSET		0x04
#define MRCC_AHB1ENR_OFFSET		0x30
#define MRCC_APB1ENR_OFFSET		0x40
#define MRCC_APB2ENR_OFFSET		0x44

/*Registers*/
#define MRCC_CR  				*((volatile u32 *)(MRCC_BASE_ADDR + MRCC_CR_OFFSET))
#define MRCC_CFGR  				*((volatile u32 *)(MRCC_BASE_ADDR + MRCC_CFGR_OFFSET))
#define MRCC_PLLCFGR  			*((volatile u32 *)(MRCC_BASE_ADDR + MRCC_PLLCFGR_OFFSET))
#define MRCC_AHB1ENR			*((volatile u32 *)(MRCC_BASE_ADDR + MRCC_AHB1ENR_OFFSET))
#define MRCC_APB1ENR			*((volatile u32 *)(MRCC_BASE_ADDR + MRCC_APB1ENR_OFFSET))
#define MRCC_APB2ENR			*((volatile u32 *)(MRCC_BASE_ADDR + MRCC_APB2ENR_OFFSET))

/*Prescalar of AHB*/
#define AHB_CLK_DIV_1			0000
#define	AHB_CLK_DIV_2			1000
#define	AHB_CLK_DIV_4			1001
#define	AHB_CLK_DIV_8			1010
#define	AHB_CLK_DIV_16			1011
#define	AHB_CLK_DIV_64			1100
#define	AHB_CLK_DIV_128			1101
#define	AHB_CLK_DIV_256			1110
#define	AHB_CLK_DIV_512			1111

/*Prescalar of APB1*/
#define APB1_CLK_DIV_1			000
#define	APB1_CLK_DIV_2			100
#define	APB1_CLK_DIV_4			101
#define	APB1_CLK_DIV_8			110
#define	APB1_CLK_DIV_16			111

/*Prescalar of APB2*/
#define APB2_CLK_DIV_1			000
#define	APB2_CLK_DIV_2			100
#define	APB2_CLK_DIV_4			101
#define	APB2_CLK_DIV_8			110
#define	APB2_CLK_DIV_16			111

/*BitMask Purpose*/
/*AHB Bits in CFGR_REG MASK*/
#define AHB_CLK_PRES_MASK 		0xFFFFFF0F
/*APB1 Bits in CFGR_REG MASK*/
#define APB1_CLK_PRES_MASK 		0xFFFFE3FF
/*APB2 Bits in CFGR_REG MASK*/
#define APB2_CLK_PRES_MASK 		0xFFFF1FFF
/*PLLSRC Bits in PLLCFGR_REG MASK*/
#define PLLSRC_CLK_MASK			0xFFBFFFFF
/*PLLM Mask in PLLCNFG_REG*/
#define	PLLM_FACTOR_MASK		0xFFFFFFE0
/*PLLN Mask in PLLCNFG_REG*/
#define	PLLN_FACTOR_MASK		0xFFFF803F
/*PLLP Mask in PLLCNFG_REG*/
#define	PLLP_FACTOR_MASK		0xFFFFFFE0

/*PLL Input CLK*/
#define PLL_HSI					0
#define PLL_HSE					1


#endif
