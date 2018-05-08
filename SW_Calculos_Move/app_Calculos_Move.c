/*
 * app_Calculos_Move.c
 *
 *  Created on: 04/05/2018
 *      Author: luisi_000
 */

#include "stdtypedef.h"
#include "app_Calculos_Move.h"
#include "SW_Calculos_Weight/app_Calculos_Weight.h"

 /******************************************
 * Private Prototypes
 ******************************************/
static T_UWORD app_Calculos_Weight2MoveY (T_UWORD * G);
static T_UWORD app_Calculos_Weight2MoveX(T_UWORD * G);


T_UWORD ruw_ForceApplied0;
T_UWORD ruw_ForceApplied1;
T_UWORD rub_Force;


T_UWORD app_Calculos_Weight2MoveY(T_UWORD * G)
{

	T_UWORD OP1,OP2;

	OP1 = G[2] + G[3];
	OP2 = G[1] + G[0];

	if(OP1>OP2)
	{
		return(OP1-OP2);
	}

	else
	{
		return(OP2-OP1);
	}




}

T_UWORD app_Calculos_Weight2MoveX(T_UWORD * G)
{
	T_UWORD OP1,OP2;

	OP1 = G[0] + G[3];
	OP2 = G[1] + G[2];

	if(OP1>OP2)
	{
		return(OP1-OP2);
	}
	else
	{
		return(OP2-OP1);
	}


}


void app_Raw_Task(void)
{
	//Caculo de fuerza final
	ruw_ForceApplied0 = app_Calculos_Weight2MoveY(ruw_WeightValue);
	ruw_ForceApplied1 = app_Calculos_Weight2MoveX(ruw_WeightValue);


	if(ruw_ForceApplied0 > ruw_ForceApplied1 )
	{
		rub_Force = (ruw_ForceApplied0 - MACRO_TOLERANCE);
	}

	else
	{
		rub_Force = (ruw_ForceApplied1 - MACRO_TOLERANCE);
	}


}

