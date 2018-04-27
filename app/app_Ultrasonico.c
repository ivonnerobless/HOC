/*
 * Copyright (c) 2017, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    app_Ultrasonico.c
 * @brief   Application entry point.
 */

#include "MKL25Z4.h"
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_clock.h"
#include "fsl_pit.h"
#include "app_Ultrasonico.h"
#include "stdtypedef.h"

unsigned char lub_estadoTRG;

T_UBYTE rub_IsTriggered;
T_UBYTE rub_IsMeasureInProgress;
T_UBYTE rub_SensorIndex;
T_UBYTE rub_NumIntentos;

static T_UBYTE rub_TimeTemp;
T_UBYTE raub_Time[4];

T_UBYTE ultrasonic_ready;

void APP_TRG_ON_OFF_0 (void)
{
	/* CADA RECEPCION DE SEÑAL PONER EN 0*/
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_0, 0u);
}

void APP_TRG_OFF_ON_0 (void)
{
	/* CADA RECEPCION DE SEÑAL PONER EN 1*/
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_0, 1u);
}

void APP_TRG_ON_OFF_1 (void)
{
	/* CADA RECEPCION DE SEÑAL PONER EN 0*/
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_1, 0u);
}

void APP_TRG_OFF_ON_1 (void)
{
	/* CADA RECEPCION DE SEÑAL PONER EN 1*/
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_1, 1u);
}

void APP_TRG_ON_OFF_2 (void)
{
	/* CADA RECEPCION DE SEÑAL PONER EN 0*/
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_2, 0u);
}

void APP_TRG_OFF_ON_2 (void)
{
	/* CADA RECEPCION DE SEÑAL PONER EN 1*/
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_2, 1u);
}

void APP_TRG_ON_OFF_3 (void)
{
	/* CADA RECEPCION DE SEÑAL PONER EN 0*/
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_3, 0u);
}

void APP_TRG_OFF_ON_3 (void)
{
	/* CADA RECEPCION DE SEÑAL PONER EN 1*/
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_3, 1u);
}


void app_config_init_counter (void)
{
	CLOCK_EnableClock(kCLOCK_PortC);

	port_pin_config_t ls_port_config;

	ls_port_config.mux = kPORT_MuxAsGpio;

	PORT_SetPinConfig(PORTC, APP_ECHO_PIN_NUMBER_0, &ls_port_config);
	PORT_SetPinConfig(PORTC, APP_ECHO_PIN_NUMBER_1, &ls_port_config);
	PORT_SetPinConfig(PORTC, APP_ECHO_PIN_NUMBER_2, &ls_port_config);
	PORT_SetPinConfig(PORTC, APP_ECHO_PIN_NUMBER_3, &ls_port_config);
	PORT_SetPinConfig(PORTC, APP_TRG_PIN_NUMBER_0, &ls_port_config);
	PORT_SetPinConfig(PORTC, APP_TRG_PIN_NUMBER_1, &ls_port_config);
	PORT_SetPinConfig(PORTC, APP_TRG_PIN_NUMBER_2, &ls_port_config);
	PORT_SetPinConfig(PORTC, APP_TRG_PIN_NUMBER_3, &ls_port_config);


	/*GPIO AS OUTPUT*/

	gpio_pin_config_t ls_PinConfig;

	ls_PinConfig.pinDirection = kGPIO_DigitalOutput;
	ls_PinConfig.outputLogic = 1u;


	GPIO_PinInit(GPIOC, APP_TRG_PIN_NUMBER_0, &ls_PinConfig);
	GPIO_PinInit(GPIOC, APP_TRG_PIN_NUMBER_1, &ls_PinConfig);
	GPIO_PinInit(GPIOC, APP_TRG_PIN_NUMBER_2, &ls_PinConfig);
	GPIO_PinInit(GPIOC, APP_TRG_PIN_NUMBER_3, &ls_PinConfig);



	/*Input config*/
	ls_PinConfig.pinDirection = kGPIO_DigitalInput;

	GPIO_PinInit(GPIOC, APP_ECHO_PIN_NUMBER_0, &ls_PinConfig);
	GPIO_PinInit(GPIOC, APP_ECHO_PIN_NUMBER_1, &ls_PinConfig);
	GPIO_PinInit(GPIOC, APP_ECHO_PIN_NUMBER_2, &ls_PinConfig);
	GPIO_PinInit(GPIOC, APP_ECHO_PIN_NUMBER_3, &ls_PinConfig);

	pit_config_t ls_PitConfig;

	PIT_GetDefaultConfig(&ls_PitConfig);

	/* Enable at the NVIC */
	EnableIRQ(PIT_IRQn);

	/* Init pit module */
	PIT_Init(PIT, &ls_PitConfig);

	//Clear triggered flag
	rub_IsTriggered = FALSE;
	//Clear Time Temp Variable
	rub_TimeTemp = 0u;
	//Clear In progress flag
	rub_IsMeasureInProgress = 0u;
	//Initialize Sensor Index
	rub_SensorIndex = 0u;
	//ultrasonic ready
	ultrasonic_ready = 0u;
	//intentos
	rub_NumIntentos=0u;


}


/******************************************************/
/* Name: app_Ultrasonicos_Task                        */
/* Description: This function will manage all the
 * 				ultrasonic tasks needed for the correct
 * 				functionality of this module          */
/******************************************************/
void app_Ultrasonicos_Task(void)
{
	/*int selector;
    selector = 0u; */
	//Check if a measure is not in progress
	if(FALSE == rub_IsMeasureInProgress)
	{
		APP_TRG_ON_OFF_0();
			//Trigger
		//Set trigger
			rub_IsTriggered = TRUE;
			//Initialize Temp Variable for counting
			rub_TimeTemp = 0u;

			//Enable measure function every 100us
			APP_ULTRASONICO_MACRO_ENABLE_PIN_INTERRUPT;
			//Set In Progress Flag
			rub_IsMeasureInProgress = TRUE;

		//Wait for Measure
		//Sensor was triggered - Wait for High Echo

	}
	else
	{
		//Do Nothing - Wait for measure task finish
		APP_TRG_OFF_ON_0();
		/*switch(selector)
		{
		case 1:
			APP_TRG_OFF_ON_0();
		break;
		case 2:
			APP_TRG_OFF_ON_1();
		break;
		case 3:
			APP_TRG_OFF_ON_2();
		break;
		case 4:
			APP_TRG_OFF_ON_3();
		break;



		}
		*/
	}
}


/******************************************************/
/* Name: app_Ultrasonicos_ISR_Task                    */
/* Description: This function will manage the ISR for
 * 				Measure the ECHO PIN        	      */
/******************************************************/
void app_Ultrasonicos_ISR_Task(void)
{
	T_UBYTE lub_EchoValue;
	/* Clear interrupt flag.*/
	PIT_ClearStatusFlags(PIT, kPIT_Chnl_0, kPIT_TimerFlag);
	if(TRUE == ultrasonic_ready)

	{
		//Check PIN State

		lub_EchoValue = GPIO_ReadPinInput(GPIOC, APP_ECHO_PIN_NUMBER_0);
		//ECHO Is High - Count
		if(TRUE == lub_EchoValue)
		{
			//Count
			rub_TimeTemp++;
		}
		//ECHO is low - Stop Count, disable Interrupt
		else
		{
			//Stop Count
			rub_IsMeasureInProgress = FALSE;
			//Disable Interrupt
			APP_ULTRASONICO_MACRO_DISABLE_PIN_INTERRUPT;
			//Store measure

			raub_Time[0u] = rub_TimeTemp;

			ultrasonic_ready = FALSE;

			APP_TRG_OFF_ON_0();
		}

	}

	else {

		//Check pin
		lub_EchoValue = GPIO_ReadPinInput(GPIOC, APP_ECHO_PIN_NUMBER_0);
		if(TRUE == lub_EchoValue)
		{
			ultrasonic_ready = TRUE;
		}
		else
		{


			//Do nothing;

			if(rub_NumIntentos==5){

				//Stop Count
			rub_IsMeasureInProgress = FALSE;
				//Disable Interrupt

		       //Store measure
			raub_Time[0u] = rub_TimeTemp;
			ultrasonic_ready = FALSE;

			APP_TRG_OFF_ON_0();


			}
			else{
					rub_NumIntentos++;
			}




		}


	}
}
