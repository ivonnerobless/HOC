/*
 * SW_Calculos_Power.c
 *
 *  Created on: 26/04/2018
 *      Author: luisi_000
 */


/******************************************
 * Interfaces
 ******************************************/
#include "stdtypedef.h"
#include "SW_Calculos_Power.h"
#include "SW_Calculos_Speed/SW_Calculos_Speed.h"

T_UBYTE rub_Power;

static T_UBYTE app_Speed2Power(T_UBYTE lub_Speed);

/***********************************************
 * Initialization of the Speed module
 * Function Name: app_Power_Init
 ***********************************************/


void app_Power_Init(void)
{


	rub_Power = MACRO_POWER_STOP_VALUE;

}

/***********************************************
 * TODO: TBD
 ***********************************************/
T_UBYTE app_Speed2Power(T_UBYTE lub_Speed)
{
#ifndef MACRO_POWER_DIVIDE
	return(lub_Speed * MACRO_POWER_CONSTANT);
#else
	return(lub_Speed / MACRO_POWER_CONSTANT);
#endif
}

/***********************************************
 * Function Name: app_Power_MngTask
 ***********************************************/
void app_Power_MngTask(void)
{

	rub_Power = app_Speed2Power(rub_Speed);


}


