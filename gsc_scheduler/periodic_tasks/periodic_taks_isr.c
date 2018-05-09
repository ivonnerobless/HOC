/*
 * periodic_taks_isr.c
 *
 *  Created on: 09/05/2018
 *      Author: Ivonne Robles
 */
#include "fsl_clock.h"
#include "fsl_pit.h"

#include "app_Ultrasonico.h"
#include "SW_Calculos_PW/SW_Calculos_PW.h"
#include "periodic_task_isr.h"

void periodic_tasks_isr_100us(void)
{ 	/* Clear interrupt flag.*/
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);


	if(TRUE == Ultrasonic_Isr_Flag){

		app_Ultrasonicos_ISR_Task();


	}

	else{


	}
	if(TRUE == rub_servo_Isr_Flag )
	{


		app_Delay_Period();



	}

	else
	{


	}

}

void periodic_tasks_isr_init (void)
{
	pit_config_t ls_PitConfig;

	PIT_GetDefaultConfig(&ls_PitConfig);

	/* Enable at the NVIC */
	EnableIRQ(PIT_IRQn);

	/* Init pit module */
	PIT_Init(PIT, &ls_PitConfig);

	/* Set timer period for channel 0 */
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, CLOCK_GetFreq(kCLOCK_BusClk)));
	/* Enable timer interrupts for channel 0 */
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	PIT_StartTimer(PIT, kPIT_Chnl_0);



}

