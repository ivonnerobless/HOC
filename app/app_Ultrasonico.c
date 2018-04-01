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
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"

void APP_TRG_ON_OFF (void)
{
	unsigned char lub_estadoTRG;

	lub_estadoTRG = GPIO_ReadPinInput(GPIOB, APP_TRG_PIN_NUMBER);

	if (lub_estadoTRG == 0u)
	{
		/* CADA RECEPCION DE SEÑAL PONER EN 1*/
		GPIO_WritePinOutput(GPIOB, APP_TRG_PIN_NUMBER, 1u);
	}

	else
	{
		/*REINICIAR CONTADOR*/

		COUNTER_TRG == 0U;

	}
}

void APP_TRG_ON_OFF (void)
{
	unsigned char lub_estadoTRG;

	lub_estadoTRG = GPIO_ReadPinInput(GPIOB, APP_TRG_PIN_NUMBER);

	if (lub_estadoTRG == 1u)
	{
		/* CADA RECEPCION DE SEÑAL PONER EN 0*/
		GPIO_WritePinOutput(GPIOB, APP_TRG_PIN_NUMBER, 0u);
	}

	else
	{
		/*REINICIAR CONTADOR*/

		COUNTER_TRG == 0U;

	}
}

void app_config_init_counter (void)
{

/*GPIO AS OUTPUT*/

	gpio_pin_config_t ls_PinConfig;

		ls_PinConfig.pinDirection = kGPIO_DigitalOutput;
		ls_PinConfig.outputLogic = 1u;


		GPIO_PinInit(GPIOB, APP_TRG_PIN_NUMBER, &ls_PinConfig);

}

void APP_COUNTER_TIME (void)
	{
	unsigned char lul_TIME;

	lul_TIME == 0u;

	do
	{
		lul_TIME++;
	}
	while (lul_TIME = lub_estadoTRG);
	}


void COUNTER_TRG (void)
	{
	unsigned char lul_counter_TRG;

	lul_counter_TRG == 256u;

	do
	{
		lul_counter_TRG--;
	}
	while (lul_counter_TRG = lub_estadoTRG);
	}

