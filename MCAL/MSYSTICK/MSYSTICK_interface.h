#ifndef MSYSTICK_INTERFACE_H
#define MSYSTICK_INTERFACE_H

void MSTK_voidInit();
void MSTK_voidSetBusyWait(u32 Copy_u32TimeInMicroSeconds);
void MSTCK_voidSetInternalSingle(u32 Copy_u32TimeInMicroSeconds);
void MSTCK_voidSetInternalPeriodic(u32 Copy_u32TimeInMicroSeconds);
u32 MSTCK_u32GetElapsedTime();
u32 MSTCK_u32GetRemainingTime();

#endif
