/*
 * SW_Calculos_Speed.c
 *
 *  Created on: 10/04/2018
 *      Author: Ivonne Robles
 */

 /******************************************
 * Interfaces
 ******************************************/
#include "stdtypedef.h"
#include "SW_Calculos_Speed.h"
#include "SW_Calculos_Move/app_Calculos_Move.h"


/******************************************
 * Private Macros
 ******************************************/


/******************************************
 * Private Variables
 ******************************************/
//T_UBYTE rub_Force;

/******************************************
 * Private Prototypes
 ******************************************/
static T_UBYTE app_Speed_Force2Speed(T_UBYTE lub_Force);


T_UBYTE rub_DetectaObstaculo;
T_UBYTE rub_IsDirectionValid;
T_UBYTE rub_Speed;



/***********************************************
 * Initialization of the Speed module
 * Function Name: app_Speed_Init
 ***********************************************/


void app_Speed_Init(void)
{

	//Variables
	rub_Speed = MACRO_SPEED_STOP_VALUE;

}

/***********************************************
 * Read conversion value
 * Function Name:app_Speed_Force2Speed
 ***********************************************/


T_UBYTE app_Speed_Force2Speed(T_UBYTE lub_Force)
{


	T_UWORD luw_Returnvalue;

	luw_Returnvalue = ((T_UWORD)lub_Force*MACRO_CONSTANT_SPEED)/10u;


		if(luw_Returnvalue > MACRO_SPEED_MAX)
		{

			luw_Returnvalue = MACRO_SPEED_MAX;

		}
		else
		{
			//nothing

		}

	return (T_UBYTE)(luw_Returnvalue);

}

/***********************************************
 * Function Name: app_Speed_MngTask
 ***********************************************/
void app_Speed_MngTask(void)
{
	if(		(FALSE == MACRO_SPEED_ISANOBSTACLE)	/*Existe un obstaculo en la direccion?*/ &&
			(TRUE == MACRO_SPEED_IS_DIRECTION_VALID)	/* La direccion de movimiento es valida? */
	)
	{
		rub_Speed = app_Speed_Force2Speed(rub_Force);																																																																																																																							rub_Speed = app_Speed_Force2Speed(rub_Force);
	}
	else
	{
		rub_Speed = MACRO_SPEED_STOP_VALUE;
	}
}
