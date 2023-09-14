/*LIB Inclusions*/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
/*Lower Layer Include*/


/*Self Layer Inclusions*/


/*Self Files*/
#include "../include/MRCC_interface.h"
#include "../include/MRCC_private.h"
#include "../include/MRCC_config.h"


void MRCC_voidInit(void)
{
	#if MRCC_SYSTEM_CLK_SRC == MRCC_HSI
		/*Enable HSI */
		SET_BIT(MRCC_CR, 0);
		/*Polling Till HSI Is Ready and Stable*/
		while (GET_BIT(MRCC_CR, 1) == 0);
		/*Select HSI as System Clock*/
		CLR_BIT(MRCC_CFGR, 0);
		CLR_BIT(MRCC_CFGR, 1);
	#elif MRCC_SYSTEM_CLK_SRC == MRCC_HSE
		/*Enable HSE */
		SET_BIT(MRCC_CR, 16);
		/*Polling Till HSE Is Ready and Stable*/
		while (GET_BIT(MRCC_RC, 17) == 0);
		/*Select HSE as System Clock*/
		SET_BIT(MRCC_CFGR, 0);
		CLR_BIT(MRCC_CFGR, 1);
	#elif MRCC_SYSTEM_CLK_SRC == MRCC_PLL
		/*Enable PLL */
		SET_BIT(MRCC_CR, 24);
		/*Polling Till PLL Is Ready and Stable*/
		while (GET_BIT(MRCC_RC, 25) == 0);
		/*Select PLL Source*/
		/*@TODO*/
		/*Parameters of PLL M, N, P to generate specific clock
		 * M: is division factor
		 * N: is Multiplication Factor
		 * P: is Main Division Factor
		 */
		MRCC_PLLCFGR &= PLLM_FACTOR_MASK;
		MRCC_PLLCFGR |=	PLLM_FACTOR_VAL;

		MRCC_PLLCFGR &= PLLN_FACTOR_MASK;
		MRCC_PLLCFGR |=	PLLN_FACTOR_VAL;

		MRCC_PLLCFGR &= PLLP_FACTOR_MASK;
		MRCC_PLLCFGR |=	PLLP_FACTOR_VAL;

		/* 	VCO "IN"= PLL SRC/PLLM
		 * 	VCO "OUT"= VCO"IN"*PLLN
		 * 	PLL OutputCLK = VCO_OUT / PLLP
		 */
		#if MRCC_PLL_CLK_SRC == PLL_HSI_SRC
			/* Set HSI CLK On   */
			SET_BIT(MRCC_CR, MRCC_CR_HSION);
			/* Wait Till HSI become Stable And RDY to be Used */
			while((GET_BIT(MRCC_CR, MRCC_CR_HSIRDY)) == 0);
			/*Set  HSI source clk to be pll source clk */
			CLEAR_BIT(MRCC_PLLCFGR, MRCC_PLLSRC);

        #elif MRCC_PLL_CLK_SRC == PLL_HSE_SRC
			/* Set HSE Clk On*/
			SET_BIT(MRCC_CR,MRCC_CR_HSEON);
			/* Wait Till HSE become Stable And RDY to be Used */
			while((GET_BIT(MRCC_CR,MRCC_CR_HSERDY)) == 0);

			/*Set  HSE source clk to be pll source clk */
			SET_BIT(MRCC_PLLCFGR,MRCC_PLLSRC);
        #else
            #error ("MRCC_PLL_CLK_SRC Wrong Configuration!")
        #endif

		/*Activation of the PLL Source CLOCK Multiplexed*/
		MRCC_PLLCFGR &= PLLSRC_CLK_MASK;
		MRCC_PLLCFGR |= PLLSRC_BIT << 22;

		/*Select PLL as System Clock*/
		CLR_BIT(MRCC_CFGR, 0);
		SET_BIT(MRCC_CFGR, 1);
	#else
		#error ("MRCC_SYSTEM_CLK_SRC Configuration ERROR!")
	#endif
		/*Select The Prescaler for AHB Bus*/
		MRCC_CFGR &= AHB_CLK_PRES_MASK;
		MRCC_CFGR |= MRCC_AHB_CLK_PRES << 4;

		/*Select The Prescaler for APB1 Bus*/
		//@TODO
		MRCC_CFGR &= APB1_CLK_PRES_MASK;
		MRCC_CFGR |= MRCC_APB1_CLK_PRES << 10;

		/*Select The Prescaler for APB2 Bus*/
		MRCC_CFGR &= APB2_CLK_PRES_MASK;
		MRCC_CFGR |= MRCC_APB2_CLK_PRES << 13;
}

void MRCC_voidEnablePeripheralClock(BUS_e Copy_BUS_eBusName, Peripheral_e Copy_Peripheral_ePeripheralName)
{
	switch(Copy_BUS_eBusName)
	{
		case MRCC_AHB_BUS  : SET_BIT(MRCC_AHB1ENR, Copy_Peripheral_ePeripheralName); break;
		case MRCC_APB1_BUS : SET_BIT(MRCC_APB1ENR, Copy_Peripheral_ePeripheralName); break;
		case MRCC_APB2_BUS : SET_BIT(MRCC_APB2ENR, Copy_Peripheral_ePeripheralName); break;
		default :
			// do No thing
		break;
	}
}

void MRCC_voidDisablePeripheralClock(BUS_e Copy_BUS_eBusName, Peripheral_e Copy_Peripheral_ePeripheralName)
{
	switch(Copy_BUS_eBusName)
	{
		case MRCC_AHB_BUS  : CLR_BIT(MRCC_AHB1ENR, Copy_Peripheral_ePeripheralName); break;
		case MRCC_APB1_BUS : CLR_BIT(MRCC_APB1ENR, Copy_Peripheral_ePeripheralName); break;
		case MRCC_APB2_BUS : CLR_BIT(MRCC_APB2ENR, Copy_Peripheral_ePeripheralName); break;
		default :
			// do No thing
		break;
	}
}
