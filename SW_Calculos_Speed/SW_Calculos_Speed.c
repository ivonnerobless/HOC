/*
 * SW_Calculos_Speed.c
 *
 *  Created on: 10/04/2018
 *      Author: Ivonne Robles
 */

#include "stdtypedef.h"

T_UBYTE rub_Speed;

void app_Speed_Init(void)
{
	/* Module Init */

	//Variables
	rub_Speed = MACRO_SPEED_STOP_VALUE;
	//States
	//Flags
	//HW
}

T_UBYTE app_Speed_Force2Speed(T_UBYTE lub_Force)
{
	return (T_UBYTE)(lub_Force * MACRO_SPEED_MULTIPLIER);
}

void app_Speed_MngTask(void)
{
	if(FALSE == MACRO_SPEED_ISANOBSTACLE)
	{
		rub_Speed = app_Speed_Force2Speed(rub_Force);
	}
	else
	{
		rub_Speed = MACRO_SPEED_STOP_VALUE;
	}
}
