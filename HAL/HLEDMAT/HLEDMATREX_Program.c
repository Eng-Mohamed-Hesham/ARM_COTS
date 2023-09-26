/*
 * HLEDMATREX_Program.c
 *
 *  Created on: Sep 20, 2023
 *      Author: Muhammed-PC
 */

/*Library Inclusions*/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

/*Lower Layers Inclusions*/
#include "../include/MGPIO_Interface.h"
#include "../include/MSYSTICK_Interface.h"
/*Self Inclusions*/

/*Self Files Inclusions*/
#include "../include/HLEDMATREX_Interface.h"
#include "../include/HLEDMATREX_Private.h"
#include "../include/HLEDMATREX_Config.h"

u8 Local_u8ColumnArray [8] ={
	HLEDMAT_COL0_PIN,
	HLEDMAT_COL1_PIN,
	HLEDMAT_COL2_PIN,
	HLEDMAT_COL3_PIN,
	HLEDMAT_COL4_PIN,
	HLEDMAT_COL5_PIN,
	HLEDMAT_COL6_PIN,
	HLEDMAT_COL7_PIN,
};

u8 Local_u8RowsArray [4] ={
	HLEDMAT_ROW0_PIN,
	HLEDMAT_ROW1_PIN,
	HLEDMAT_ROW2_PIN,
	HLEDMAT_ROW3_PIN,
};

void HLEDMX_voidInit(){
	u8 Local_u8LoopCounter = 0;
	/*set columns pins to be output pins*/
	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++){
		MGPIO_PinMode(HLEDMAT_COLUMNS_PORT, Local_u8ColumnArray[Local_u8LoopCounter], MGPIO_OUTPUT);
		MGPIO_PinMode(HLEDMAT_ROWS_PORT, Local_u8RowsArray[Local_u8LoopCounter], MGPIO_OUTPUT);
	}
	voidDisableAllCol();
}

void HLEDMX_voidDisplay(u8 *Copy_pu8Data){
	u8 Local_u8ColumnIndex =0;
	u8 Local_RowIndex = 0;
	u8 Local_RowValue = 0;
	for (Local_u8ColumnIndex = 0; Local_u8ColumnIndex < 8; Local_u8ColumnIndex++){
		/*Disable all Columns*/
		voidDisableAllCol();
		/*Set Rows Value*/
		for(Local_RowIndex = 0; Local_RowIndex < 4; Local_RowIndex++){
			Local_RowValue = GET_BIT(Copy_pu8Data[Local_u8ColumnIndex], Local_RowIndex);
			MGPIO_voidSetPinValue(HLEDMAT_ROWS_PORT, Local_u8RowsArray[Local_RowIndex], MGPIO_RESET);
		}
		/*Active One Column @ A Time*/
		MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, Local_u8ColumnArray[Local_u8ColumnIndex], MGPIO_RESET);
		/*Wait for 2500 us*/
		MSTK_voidSetBusyWait(25000);
	}
}

static void voidDisableAllCol (void)  //Make it not call able for user
{
	u8 Local_u8LoopCounter = 0;
	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++){
		MGPIO_voidSetPinValue(HLEDMAT_COLUMNS_PORT, Local_u8ColumnArray[Local_u8LoopCounter], MGPIO_SET);
	}
}
