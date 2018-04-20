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
#include "app_Ultrasonico.h"
#include "MKL25Z4.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_clock.h"

	unsigned char loop_estadoTRG;

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

}

unsigned long APP_COUNTER_TIME (unsigned char lub_pin_number)
{
	unsigned long lul_TIME;

	lul_TIME = 0u;

	do
	{
		lul_TIME++;
	}
	while (0u == GPIO_ReadPinInput(GPIOC, lub_pin_number));
	GPIO_WritePinOutput(GPIOC, APP_TRG_PIN_NUMBER_0, 0u);

	return lul_TIME;
}


void COUNTER_TRG (void)
	{
	unsigned char lul_counter_TRG;

	lul_counter_TRG = 255u;

	do
	{
		lul_counter_TRG--;
	}
	while (1u == loop_estadoTRG);
	}

