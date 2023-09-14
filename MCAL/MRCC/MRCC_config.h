#ifndef MRCC_CONFIG_H
#define MRCC_CONFIG_H

/*Options:
 	 MRCC_HSI
 	 MRCC_HSE
 	 MRCC_PLL
 */
#define MRCC_SYSTEM_CLK_SRC 			MRCC_HSI

/*Options:
 	 PLL_HSI_SRC
 	 PLL_HSE_SRC
 */
#define MRCCPLL_CLK_SRC					PLL_HSI_SRC

/*Options:
	AHB_CLK_DIV_1	0000
	AHB_CLK_DIV_2	1000
	AHB_CLK_DIV_4	1001
	AHB_CLK_DIV_8	1010
	AHB_CLK_DIV_16	1011
	AHB_CLK_DIV_64	1100
	AHB_CLK_DIV_128	1101
	AHB_CLK_DIV_256	1110
	AHB_CLK_DIV_512	1111
*/
#define MRCC_AHB_CLK_PRES				AHB_CLK_DIV_2

/*Options:
	APB1_CLK_DIV_1	0000
	APB1_CLK_DIV_2	1000
	APB1_CLK_DIV_4	1001
	APB1_CLK_DIV_8	1010
	APB1_CLK_DIV_16	1011
*/
#define MRCC_APB1_CLK_PRES				APB1_CLK_DIV_2

/*Options:
	APB2_CLK_DIV_1	0000
	APB2_CLK_DIV_2	1000
	APB2_CLK_DIV_4	1001
	APB2_CLK_DIV_8	1010
	APB2_CLK_DIV_16	1011
*/
#define MRCC_APB2_CLK_PRES				APB2_CLK_DIV_2

/*Options:
 * 		PLLM with in between (2<=PLLM<=63)
 * 		OTHER is Wrong Configuration
 */
#define  PLLM_FACTOR_VAL				2

/*Options:
 * 		PLLN with in between (192<=PLLN<=432)
 * 		OTHER is Wrong Configuration
 */
#define  PLLN_FACTOR_VAL				192

/*Options:
 * 		PLLP with in between (2<=PLLP<=8) EVEN ONLY
 * 		OTHER is Wrong Configuration
 */
#define  PLLP_FACTOR_VAL				2

#endif
