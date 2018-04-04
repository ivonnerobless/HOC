/*
 * app_Ultrasonico.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Adan S
 */

#ifndef APP_ULTRASONICO_H_
#define APP_ULTRASONICO_H_

#define APP_TRG 0u
#define COUNTER_TRG
#define app_config_init_counter
#define APP_COUNTER_TIME

#define APP_TRG_PIN_NUMBER 12u
#define APP_TRG_PIN_NUMBER 13u
#define APP_TRG_PIN_NUMBER 16u
#define APP_TRG_PIN_NUMBER 17u

#define APP_TRG_ON		    GPIO_WritePinOutput(GPIOB, APP_TRG_PIN_NUMBER, 0u)
#define APP_TRG_OFF		    GPIO_WritePinOutput(GPIOB, APP_TRG_PIN_NUMBER, 1u)

#endif /* APP_ULTRASONICO_H_ */
