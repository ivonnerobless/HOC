/*
 * SW_Calculos_Pw.h
 *
 *  Created on: 02/05/2018
 *      Author: Ivonne Robles
 */


#ifndef SW_CALCULOS_PW_H_
#define SW_CALCULOS_PW_H_

#include "stdtypedef.h"
#include "SW_Calculos_Direction/SW_Calculos_Direction.h"

#define APP_SERVO_PIN1   2u
#define APP_SERVO_PIN2   3u

#define APP_SERVO1_ON 		GPIO_WritePinOutput(GPIOB,APP_SERVO_PIN1, 1u)
#define APP_SERVO1_OFF 		GPIO_WritePinOutput(GPIOB,APP_SERVO_PIN1, 0u)
#define IS_APP_SERVO1_OFF	(FALSE == GPIO_ReadPinInput(GPIOB, APP_SERVO_PIN1))

#define APP_SERVO2_ON GPIO_WritePinOutput(GPIOB,APP_SERVO_PIN2, 1u)
#define APP_SERVO2_OFF GPIO_WritePinOutput(GPIOB,APP_SERVO_PIN2, 0u)

#define MACRO_DELAY_LOW 200
#define MACRO_DELAY_HIGH rub_PulseWidth
#define MACRO_SERVO_TIMES 10
#define MACRO_MAX_MOVES 20
#define MACRO_FRONT_SIDE 4
#define MACRO_SIDE_WAYS 12







enum
{
	READ_SERVO1,
	READ_SERVO2,
	N_SERVO
};

extern T_UBYTE rub_PulseWidth;

extern void app_Pw_Servo_Task (T_EDIRECTION le_Direction);
extern void app_Delay_Period (void);
extern void app_config_clock (void);
extern T_UBYTE rub_servo_Isr_Flag;
extern T_UBYTE rub_Servo_Times;


#endif /* SW_CALCULOS_PW_H_ */
