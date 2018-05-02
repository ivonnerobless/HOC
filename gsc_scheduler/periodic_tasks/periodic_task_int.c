/*
 * periodic_task_int.c
 *
 *  Created on: 02/05/2018
 *      Author: uidj2522
 */

#include "periodic_task_int.h"
#include "app_Ultrasonico.h"

/*
 * TODO: TBD
 */
void periodic_task_int_100us(void)
{
	app_Ultrasonicos_ISR_Task();
}
