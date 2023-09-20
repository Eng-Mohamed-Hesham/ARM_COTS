/*LIB Inclusions*/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
/*Lower Layer Include*/


/*Self Layer Inclusions*/


/*Self Files*/
#include "../include/MSYSTICK_interface.h"
#include "../include/MSYSTICK_private.h"
#include "../include/MSYSTICK_config.h"

void MSTK_voidInit(void)
{
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

void MSTK_voidInterruptControl(u8 Copy_u81InterruptState)
{
	switch(Copy_u81InterruptState)
	{
		case PIE_SET:
			SET_BIT(STK_CTRLR, 1);
			break;
		case PIE_RESET:
			CLR_BIT(STK_CTRLR, 1);
			break;
		default :
			// Raise An Error
			break;
	}
}

void MSTK_voidSetBusyWait(u32 Copy_u32TimeInMicroSeconds)
{
	STK_LOADR = Copy_u32TimeInMicroSeconds;
	SET_BIT(STK_CTRLR, 0);
	while (GET_BIT(STK_CTRLR,16)==0);
	STK_VALR = 0;
	CLR_BIT(STK_CTRLR, 0);
}
u32 IntervalStatus = SINGLE_INTERVALE;
void (*pvoidNotificationFunction)(void) = NULL;


void MSTCK_voidSetIntervalSingle(void (*Copy_pvoidCallBack)(void), u32 Copy_u32TimeInMicroSeconds)
{
	STK_LOADR = Copy_u32TimeInMicroSeconds;
	SET_BIT(STK_CTRLR,1);
	SET_BIT(STK_CTRLR,0);
	IntervalStatus = SINGLE_INTERVALE;
	pvoidNotificationFunction = Copy_pvoidCallBack;
}

void MSTCK_voidSetIntervalPeriodic(void (*Copy_pvoidCallBack)(void), u32 Copy_u32TimeInMicroSeconds)
{
	STK_LOADR = Copy_u32TimeInMicroSeconds;
	SET_BIT(STK_CTRLR,1);
	SET_BIT(STK_CTRLR,0);
	IntervalStatus = PERIODIC_INTERVALE;
	pvoidNotificationFunction = Copy_pvoidCallBack;
}

void SysTick_Handler(void){
	if (IntervalStatus == SINGLE_INTERVALE){
		CLR_BIT(STK_CTRLR,1);
	}
	/*Invoke The Callback function*/
	if (pvoidNotificationFunction != NULL){
		pvoidNotificationFunction();
	}
}

u32 MSTK_u32GetElapsedTime ()
{
	u32 local_u32ElapsedTime;
	local_u32ElapsedTime = STK_LOADR- STK_VALR;
	return local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime ()
{
	return STK_VALR;
}



