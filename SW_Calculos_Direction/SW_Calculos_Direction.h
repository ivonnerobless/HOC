/*
 * SW_Calculos_Direction.h
 *
 *  Created on: 30/04/2018
 *      Author: Ivonne Robles
 */

#ifndef SW_CALCULOS_DIRECTION_H_
#define SW_CALCULOS_DIRECTION_H_

#include "stdtypedef.h"
#define APP_DIRECTION_MACRO N_DIRECTION


enum
{

	READ_front_left,
    READ_front_right,
    READ_rear_left,
    READ_rear_right,
    READ_center,
	N_DIRECTION
};

typedef enum
{
	DIR_FRONT,
	DIR_REAR,
	DIR_RIGHT,
	DIR_LEFT,
	DIR_INVALID
}T_EDIRECTION;

extern T_EDIRECTION app_force2direction(T_UWORD laub_WeightData[]);
#endif /* SW_CALCULOS_DIRECTION_H_ */
