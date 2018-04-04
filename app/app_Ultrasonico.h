/*
 * app_Ultrasonico.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Adan S
 */

#ifndef APP_ULTRASONICO_H_
#define APP_ULTRASONICO_H_

#define APP_TRG 0u

#define APP_ECHO_PIN_NUMBER   12u

#define APP_TRG_PIN_NUMBER   13u

#define APP_TRG_ON		    GPIO_WritePinOutput(GPIOB, APP_TRG_PIN_NUMBER, 0u)
#define APP_TRG_OFF		    GPIO_WritePinOutput(GPIOB, APP_TRG_PIN_NUMBER, 1u)

extern void APP_TRG_ON_OFF (void);
extern void APP_TRG_OFF_ON (void);

#endif /* APP_ULTRASONICO_H_ */
