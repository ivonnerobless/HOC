/*
 * SW_Calculos_Direction.c
 *
 *  Created on: 30/04/2018
 *      Author: Ivonne Robles
 */


#include "SW_Calculos_Direction.h"
#include "MKL25Z4.h"
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_clock.h"
#include "fsl_pit.h"
#include "SW_Calculos_Direction.h"
#include "stdtypedef.h"

T_UBYTE rub_IsDirectionValid;
T_UBYTE rub_DetectaObstaculo;

T_EDIRECTION app_force2direction(T_UWORD laub_WeightData[]){
	T_UBYTE lub_IsDataAligned;
	T_UBYTE laub_data[APP_DIRECTION_MACRO];
	T_UBYTE laub_Dir[APP_DIRECTION_MACRO];
	T_UBYTE lub_dataindex;
	T_UBYTE i;
	T_UBYTE lub_SensorIndex;
	T_EDIRECTION lub_return;
	lub_SensorIndex = READ_front_left;
	lub_IsDataAligned = FALSE;
	lub_dataindex=0;
	lub_return = 0;
	i=0;

	for(i = 0;i< APP_DIRECTION_MACRO;i++)
	{
		laub_data[i] = 0u;
		laub_Dir[i] = 0u;
	}


	do{
		if(lub_SensorIndex >= APP_DIRECTION_MACRO )
		{
			lub_IsDataAligned = TRUE;
		}
		else
		{
			if( laub_WeightData[lub_SensorIndex] > laub_data[lub_dataindex]){

				for(i = 0; i <= (APP_DIRECTION_MACRO - 2u - lub_dataindex); i++){

					laub_data[APP_DIRECTION_MACRO - 1u - i] = laub_data[APP_DIRECTION_MACRO - 2u - i];
					laub_Dir[APP_DIRECTION_MACRO - 1u - i] = laub_Dir[APP_DIRECTION_MACRO - 2u - i];
				}

				laub_data[lub_dataindex] = laub_WeightData[lub_SensorIndex];
				laub_Dir[lub_dataindex] = lub_SensorIndex;

				lub_dataindex = 0u;
				lub_SensorIndex++;
			}

			else{

				if(lub_dataindex >= (APP_DIRECTION_MACRO-2)){


					lub_dataindex = 0;
					laub_data[(APP_DIRECTION_MACRO -1)] = laub_WeightData[lub_SensorIndex];

					lub_SensorIndex++;
				}


				else {


					lub_dataindex++;

				}
			}
		}



	}while(lub_IsDataAligned == FALSE);

	/* Pre validation */
	rub_IsDirectionValid = TRUE;

	if((READ_front_left == laub_Dir[0] && READ_front_right == laub_Dir[1]) ||
			(READ_front_left == laub_Dir[1] && READ_front_right == laub_Dir[0]))
	{//Return the FRONT Direction
		lub_return = DIR_FRONT;

		if(/* Preguntar si al frente hay un obstaculo */
				raub_Time[READ_SENSOR1] <= MACRO_APP_ULTRASONICO_TIME_FOR_OBSTACLE)
		{
			rub_DetectaObstaculo = TRUE;
		}
		else
		{
			rub_DetectaObstaculo = FALSE;
		}

	}
	else if((READ_rear_left == laub_Dir[0] && READ_rear_right == laub_Dir[1]) ||
			(READ_rear_left == laub_Dir[1] && READ_rear_right == laub_Dir[0]))
	{
		lub_return = DIR_REAR;

		if(/* Preguntar si atras hay un obstaculo */
				raub_Time[READ_SENSOR2] <= MACRO_APP_ULTRASONICO_TIME_FOR_OBSTACLE)
		{
			rub_DetectaObstaculo = TRUE;
		}
		else
		{
			rub_DetectaObstaculo = FALSE;
		}
	}
	else if((READ_front_left == laub_Dir[0] && READ_rear_left == laub_Dir[1]) ||
			(READ_rear_left == laub_Dir[1] && READ_front_left == laub_Dir[0]))
	{
		lub_return = DIR_LEFT;

		if(/* Preguntar si a la izquierda hay un obstaculo */
				raub_Time[READ_SENSOR3] <= MACRO_APP_ULTRASONICO_TIME_FOR_OBSTACLE)
		{
			rub_DetectaObstaculo = TRUE;
		}
		else
		{
			rub_DetectaObstaculo = FALSE;
		}
	}
	else if((READ_front_right == laub_Dir[0] && READ_rear_right == laub_Dir[1]) ||
				(READ_rear_right == laub_Dir[1] && READ_front_right == laub_Dir[0]))
		{
			lub_return = DIR_RIGHT;

			if(/* Preguntar si a la derecha hay un obstaculo */
					raub_Time[READ_SENSOR4] <= MACRO_APP_ULTRASONICO_TIME_FOR_OBSTACLE)
			{
				rub_DetectaObstaculo = TRUE;
			}
			else
			{
				rub_DetectaObstaculo = FALSE;
			}
		}
	else
	{
		lub_return = DIR_INVALID;

		/* Invalidation */
		rub_IsDirectionValid = FALSE;

		//Limp mode - Safe Mode
		rub_DetectaObstaculo = FALSE;
	}

	return lub_return;
}
