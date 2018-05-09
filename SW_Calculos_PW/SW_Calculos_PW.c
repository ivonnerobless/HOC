/*
 * SW_Calculos_Pw.c
 *
 *  Created on: 02/05/2018
 *      Author: Ivonne Robles
 */

#include "MKL25Z4.h"
#include "fsl_common.h"
#include "board.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_clock.h"
#include "fsl_pit.h"

#include "stdtypedef.h"
#include "SW_Calculos_Pw.h"
#include "SW_Calculos_Direction/SW_Calculos_Direction.h"
#include "SW_Calculos_Weight/app_Calculos_Weight.h"

T_UWORD rub_Delay;
T_UBYTE rub_PulseWidth;
T_UBYTE rub_servo_Isr_Flag;
T_UBYTE rub_Servo_Times;




void app_config_clock (void)
{
	CLOCK_EnableClock(kCLOCK_PortB);

	port_pin_config_t ls_port_config;

	ls_port_config.mux = kPORT_MuxAsGpio;

	PORT_SetPinConfig(PORTB, APP_SERVO_PIN1, &ls_port_config);
	PORT_SetPinConfig(PORTB, APP_SERVO_PIN2, &ls_port_config);



	/*GPIO AS OUTPUT*/

	gpio_pin_config_t ls_PinConfig;

	ls_PinConfig.pinDirection = kGPIO_DigitalOutput;
	ls_PinConfig.outputLogic = 1u;


	GPIO_PinInit(GPIOB, APP_SERVO_PIN1, &ls_PinConfig);
	GPIO_PinInit(GPIOB, APP_SERVO_PIN2, &ls_PinConfig);

	rub_Delay = 0;
	rub_PulseWidth = 0;
	rub_servo_Isr_Flag = 0;
	rub_Servo_Times = 0;


}

void app_Delay_Period (void)
{
	if(IS_APP_SERVO1_OFF)
	{
		if(rub_Delay >= MACRO_DELAY_LOW)
		{
			rub_Delay = 0;
			APP_SERVO1_ON;
			APP_SERVO2_ON;
		}

		else
		{

			rub_Delay++;

		}

	}
	else
	{
		if(rub_Delay >= MACRO_DELAY_HIGH)
		{
			rub_Delay = 0;
			APP_SERVO1_OFF;
			APP_SERVO2_OFF;
			rub_Servo_Times++;
			if(rub_Servo_Times < MACRO_SERVO_TIMES ){


			}
			else{
				rub_servo_Isr_Flag = FALSE;
				rub_Servo_Times = 0;


			}
		}

		else
		{
			rub_Delay++;
		}

	}
}


void app_Pw_Servo_Task (T_EDIRECTION le_Direction)
{
	if(le_Direction == DIR_FRONT || le_Direction == DIR_REAR)
	{
		rub_PulseWidth = MACRO_FRONT_SIDE;
	}
	else if(le_Direction == DIR_LEFT || le_Direction == DIR_RIGHT){

		rub_PulseWidth = MACRO_SIDE_WAYS;
	}
	else
	{
		rub_PulseWidth = MACRO_FRONT_SIDE;
	}
		rub_servo_Isr_Flag = TRUE;
}

















