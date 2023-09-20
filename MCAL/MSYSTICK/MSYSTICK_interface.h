#ifndef MSYSTICK_INTERFACE_H
#define MSYSTICK_INTERFACE_H

#define 	PIE_RESET		0
#define 	PIE_SET			1

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32TimeInMicroSeconds);
void MSTCK_voidSetIntervalSingle(void (*Copy_pvoidCallBack)(void), u32 Copy_u32TimeInMicroSeconds);
void MSTCK_voidSetIntervalPeriodic(void (*Copy_pvoidCallBack)(void), u32 Copy_u32TimeInMicroSeconds);
u32 MSTCK_u32GetElapsedTime();
u32 MSTCK_u32GetRemainingTime();

#endif
