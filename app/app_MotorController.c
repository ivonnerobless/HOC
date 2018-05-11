/*
 * app_MotorController.c
 *
 *  Created on: 11/05/2018
 *      Author: uidj2522
 */

#include "app_MotorController.h"

static void app_MotorController_DataTransfer(T_UBYTE lub_Data);

void app_MotorController_Init(void)
{
	//Enable clock for port e
	CLOCK_EnableClock(kCLOCK_PortE);
	CLOCK_EnableClock(kCLOCK_PortD);

	//Port Config
	port_pin_config_t ls_PortConfig;

	ls_PortConfig.mux = kPORT_MuxAsGpio;

	PORT_SetPinConfig(MACRO_APP_MOTOR_CONTROLLER_SCLK_PORT, MACRO_APP_MOTOR_CONTROLLER_SCLK_PIN, &ls_PortConfig);
	PORT_SetPinConfig(MACRO_APP_MOTOR_CONTROLLER_SDA_PORT, MACRO_APP_MOTOR_CONTROLLER_SDA_PIN, &ls_PortConfig);
	PORT_SetPinConfig(MACRO_APP_MOTOR_CONTROLLER_EN_PORT, MACRO_APP_MOTOR_CONTROLLER_EN_PIN, &ls_PortConfig);

	gpio_pin_config_t ls_GpioConfig;

	ls_GpioConfig.pinDirection = kGPIO_DigitalOutput;
	ls_GpioConfig.outputLogic = MACRO_APP_MOTOR_CONTROLLER_SCLK_INIT_OUT_VALUE;

	GPIO_PinInit(MACRO_APP_MOTOR_CONTROLLER_SCLK_GPIO, MACRO_APP_MOTOR_CONTROLLER_SCLK_PIN, &ls_GpioConfig);

	ls_GpioConfig.outputLogic = MACRO_APP_MOTOR_CONTROLLER_SDA_PIN;

	GPIO_PinInit(MACRO_APP_MOTOR_CONTROLLER_SDA_GPIO, MACRO_APP_MOTOR_CONTROLLER_SDA_PIN, &ls_GpioConfig);

	ls_GpioConfig.outputLogic = MACRO_APP_MOTOR_CONTROLLER_EN_PIN;

	GPIO_PinInit(MACRO_APP_MOTOR_CONTROLLER_EN_GPIO, MACRO_APP_MOTOR_CONTROLLER_EN_PIN, &ls_GpioConfig);

}

void app_MotorController_Task(void)
{
	app_MotorController_DataTransfer(0x55);
}

static void app_MotorController_DataTransfer(T_UBYTE lub_Data)
{
	MACRO_APP_MOTOR_CONTROLLER_EN_CLEAR();
	for(T_UBYTE lub_i = 0u; lub_i < MACRO_APP_MOTOR_CONTROLLER_BITS_TO_BE_SENT;lub_i++)
	{
		MACRO_APP_MOTOR_CONTROLLER_SCLK_CLEAR();
		if(TRUE != ((lub_Data >> lub_i) & 0x01))
		{
			MACRO_APP_MOTOR_CONTROLLER_SDA_CLEAR();
		}
		else
		{
			MACRO_APP_MOTOR_CONTROLLER_SDA_SET();
		}
		MACRO_APP_MOTOR_CONTROLLER_SCLK_SET();
	}
	MACRO_APP_MOTOR_CONTROLLER_EN_SET();
}
