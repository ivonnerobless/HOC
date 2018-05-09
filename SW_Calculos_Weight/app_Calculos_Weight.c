/*
 * app_Calculos_Wight.c
 *
 *  Created on: 30/04/2018
 *      Author: luisi_000
 */


#include "stdtypedef.h"
#include "app_Calculos_Weight.h"
#include "Galgas/app_Gal.h"


 /******************************************
 * Private Prototypes
 ******************************************/
static T_UWORD app_Calculos_Raw2Weight (T_UWORD luw_RawDate);

T_UWORD ruw_WeightValue[4];



T_UWORD app_Calculos_Raw2Weight (T_UWORD luw_RawDate)
{

	return (luw_RawDate/MACRO_CONSTANT);

}

void app_RawDate_Task(void)
{

	ruw_WeightValue[0] = app_Calculos_Raw2Weight(ruw_ADCValue[0]);
	ruw_WeightValue[1] = app_Calculos_Raw2Weight(ruw_ADCValue[1]);
	ruw_WeightValue[2] = app_Calculos_Raw2Weight(ruw_ADCValue[2]);
	ruw_WeightValue[3] = app_Calculos_Raw2Weight(ruw_ADCValue[3]);

}
