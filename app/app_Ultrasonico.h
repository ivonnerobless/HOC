/*
 * app_Ultrasonico.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Adan S
 */

#ifndef APP_ULTRASONICO_H_
#define APP_ULTRASONICO_H_

#define APP_TRG 0u

#define APP_ECHO_PIN_NUMBER_0   12u
#define APP_ECHO_PIN_NUMBER_1   13u
#define APP_ECHO_PIN_NUMBER_2   16u
#define APP_ECHO_PIN_NUMBER_3   17u

#define APP_TRG_PIN_NUMBER_0   0u
#define APP_TRG_PIN_NUMBER_1   3u
#define APP_TRG_PIN_NUMBER_2   4u
#define APP_TRG_PIN_NUMBER_3   7u

#define APP_TRG_ON		    GPIO_WritePinOutput(GPIOB, APP_TRG_PIN_NUMBER, 0u)
#define APP_TRG_OFF		    GPIO_WritePinOutput(GPIOB, APP_TRG_PIN_NUMBER, 1u)

extern void APP_TRG_ON_OFF_0 (void);
extern void APP_TRG_OFF_ON_0 (void);
extern void APP_TRG_ON_OFF_1 (void);
extern void APP_TRG_OFF_ON_1 (void);
extern void APP_TRG_ON_OFF_2 (void);
extern void APP_TRG_OFF_ON_2 (void);
extern void APP_TRG_ON_OFF_3 (void);
extern void APP_TRG_OFF_ON_3 (void);
extern void app_config_init_counter (void);
extern void COUNTER_TRG (void);


#endif /* APP_ULTRASONICO_H_ */
