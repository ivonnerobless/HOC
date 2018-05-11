/*
 * app_MotorController.c
 *
 *  Created on: 11/05/2018
 *      Author: uidj2522
 */

#ifndef APP_MOTORCONTROLLER_C_
#define APP_MOTORCONTROLLER_C_
#include "stdtypedef.h"
#include "fsl_port.h"
#include "fsl_clock.h"
#include "fsl_gpio.h"

#define MACRO_APP_MOTOR_CONTROLLER_SCLK_PORT	PORTE
#define MACRO_APP_MOTOR_CONTROLLER_SDA_PORT		PORTE
#define MACRO_APP_MOTOR_CONTROLLER_EN_PORT		PORTD

#define MACRO_APP_MOTOR_CONTROLLER_SCLK_GPIO	GPIOE
#define MACRO_APP_MOTOR_CONTROLLER_SDA_GPIO		GPIOE
#define MACRO_APP_MOTOR_CONTROLLER_EN_GPIO		GPIOD

#define MACRO_APP_MOTOR_CONTROLLER_SCLK_PIN 	0u
#define MACRO_APP_MOTOR_CONTROLLER_SDA_PIN		1u
#define MACRO_APP_MOTOR_CONTROLLER_EN_PIN		1u

#define MACRO_APP_MOTOR_CONTROLLER_SCLK_INIT_OUT_VALUE	FALSE
#define MACRO_APP_MOTOR_CONTROLLER_SDA_INIT_OUT_VALUE	FALSE
#define MACRO_APP_MOTOR_CONTROLLER_EN_INIT_OUT_VALUE	TRUE

#define MACRO_APP_MOTOR_CONTROLLER_SCLK_SET()		GPIO_WritePinOutput(MACRO_APP_MOTOR_CONTROLLER_SCLK_GPIO,MACRO_APP_MOTOR_CONTROLLER_SCLK_PIN,TRUE)
#define MACRO_APP_MOTOR_CONTROLLER_SDA_SET()		GPIO_WritePinOutput(MACRO_APP_MOTOR_CONTROLLER_SDA_GPIO,MACRO_APP_MOTOR_CONTROLLER_SDA_PIN,TRUE)
#define MACRO_APP_MOTOR_CONTROLLER_EN_SET()			GPIO_WritePinOutput(MACRO_APP_MOTOR_CONTROLLER_EN_GPIO,MACRO_APP_MOTOR_CONTROLLER_EN_PIN,TRUE)

#define MACRO_APP_MOTOR_CONTROLLER_SCLK_CLEAR()   	GPIO_WritePinOutput(MACRO_APP_MOTOR_CONTROLLER_SCLK_GPIO,MACRO_APP_MOTOR_CONTROLLER_SCLK_PIN,FALSE)
#define MACRO_APP_MOTOR_CONTROLLER_SDA_CLEAR()		GPIO_WritePinOutput(MACRO_APP_MOTOR_CONTROLLER_SDA_GPIO,MACRO_APP_MOTOR_CONTROLLER_SDA_PIN,FALSE)
#define MACRO_APP_MOTOR_CONTROLLER_EN_CLEAR()		GPIO_WritePinOutput(MACRO_APP_MOTOR_CONTROLLER_EN_GPIO,MACRO_APP_MOTOR_CONTROLLER_EN_PIN,FALSE)

#define MACRO_APP_MOTOR_CONTROLLER_BITS_TO_BE_SENT	8u

extern void app_MotorController_Init(void);
extern void app_MotorController_Task(void);

#endif /* APP_MOTORCONTROLLER_C_ */
