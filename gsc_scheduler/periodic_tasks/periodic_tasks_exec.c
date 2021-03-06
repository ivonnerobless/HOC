/*============================================================================*/
/*                     AZOR - EMBEDDED SYSTEMS SOFTWARE                       */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
 * C Source:        periodic_tasks_exec.c
 * version:         1.0
 * created_by:      MDRR
 * date_created:    July 31 2013
 *=============================================================================*/
/* DESCRIPTION :  This file contains the periodic tasks definition.           */
/*============================================================================*/
/* FUNCTION COMMENT : Add here the user functionality, inside a periodic task */
/* according to the desired execution period.                                 */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/jul/2013 |                               | MDRR             */
/* This file is created based on apptask module from the old version of this  */
/* scheduler.                                                                 */
/*============================================================================*/

/* Includes */
/* -------- */
#include "periodic_tasks_exec.h"
#include "periodic_tasks_modules.h"
#include "Galgas/app_Gal.h"
#include "../../SW_Calculos_Weight/app_Calculos_Weight.h"
#include "SW_Acel.h"
#include "SW_Calculos_PW/SW_Calculos_PW.h"






/**************************************************************
 *  Name                 : periodic_tasks_exec_5tks
 *	ID					 : TASK_5TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void periodic_tasks_exec_5tks(void)
{
	app_ADC_Task();
	app_Ultrasonicos_Task();
}

/**************************************************************
 *  Name                 : periodic_tasks_exec_10tks
 *	ID					 : TASK_10TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void periodic_tasks_exec_10tks(void)
{
	app_Speed_MngTask();
}

/**************************************************************
 *  Name                 : periodic_tasks_exec_20tks
 *	ID					 : TASK_20TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void periodic_tasks_exec_20tks(void)
{
	app_MotorController_Task();
}

/**************************************************************
 *  Name                 : periodic_tasks_exec_50tks
 *	ID					 : TASK_50TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void periodic_tasks_exec_50tks(void)
{

}

/**************************************************************
 *  Name                 : periodic_tasks_exec_100tks
 *	ID					 : TASK_100TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void periodic_tasks_exec_100tks(void)
{
	app_RawDate_Task();
	app_Pw_Servo_Task(app_force2direction(ruw_WeightValue));
}

/**************************************************************

 *  Name                 : periodic_tasks_exec_500tks
 *	ID					 : TASK_500TKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void periodic_tasks_exec_500tks(void)
{

}

/**************************************************************
 *  Name                 : periodic_tasks_exec_1Mtks
 *	ID					 : TASK_1MTKS
 *  Description          : Container for functionality that is 
                           executed periodically.
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void periodic_tasks_exec_1Mtks(void)
{
	app_master();
	app_LeerCordenadas();
	app_coordenadas();
	app_rgb_led_fsm();

}

