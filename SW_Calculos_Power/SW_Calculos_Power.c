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


T_UBYTE rub_Power;


/***********************************************
 * Initialization of the Speed module
 * Function Name: app_Power_Init
 ***********************************************/


void app_Power_Init(void)
{


	rub_Power = MACRO_POWER_STOP_VALUE;

}
