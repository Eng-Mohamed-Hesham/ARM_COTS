/*LIB Inclusions*/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
/*Lower Layer Include*/


/*Self Layer Inclusions*/


/*Self Files*/
#include "../include/MSYSTICK_interface.h"
#include "../include/MSYSTICK_private.h"
#include "../include/MSYSTICK_config.h"

void MSTK_voidInit(){
	/*Enable STK Clock Source*/
	#if     STK_CLKSRC == AHB_DIV8
			CLR_BIT(STK_CTRLR, 2);
	#elif 	STK_CLKSRC == AHB
			SET_BIT(STK_CTRLR, 2);
	#else
		#error "ERROR IN STK CLK CONFIG"
	#endif

	/*Set Or Res Interrupt STATE (PIE) Peripheral interrupt status*/
	#if 	STK_PIE == PIE_SET
			SET_BIT(STK_CTRLR, 1);
	#elif 	STK_PIE == PIE_RESET
			CLR_BIT(STK_CTRLR, 1);
	#else
		#error "ERROR IN PIE CONFIG"
	#endif

	CLR_BIT(STK_CTRLR,0);
}

void MSTK_voidSetBusyWait(u32 Copy_u32TimeInMicroSeconds){
	STK_LOADR = Copy_u32TimeInMicroSeconds;
	SET_BIT(STK_CTRLR, 0);
	while (GET_BIT(STK_CTRLR,16)==0);
	CLR_BIT(STK_CTRLR, 0);
	STK_VALR = 0;
}


void MSTCK_voidSetInternalSingle(u32 Copy_u32TimeInMicroSeconds){
	STK_LOADR = Copy_u32TimeInMicroSeconds;
	STK_VALR = 0;
	SET_BIT(STK_CTRLR,1);
	SET_BIT(STK_CTRLR,0);
}

void MSTCK_voidSetInternalPeriodic(u32 Copy_u32TimeInMicroSeconds){
	STK_LOADR = Copy_u32TimeInMicroSeconds;
	STK_VALR = 0;
	SET_BIT(STK_CTRLR,1);
	SET_BIT(STK_CTRLR,0);
}


u32 MSTK_u32GetElapsedTime ()
{
	u32 local_u32ElapsedTime = STK_LOADR- STK_VALR;
	return local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime ()
{
	return STK_VALR;
}



