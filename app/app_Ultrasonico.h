/*
 * app_Ultrasonico.h
 *
 *  Created on: Mar 26, 2018
 *      Author: Adan S
 */

#ifndef APP_ULTRASONICO_H_
#define APP_ULTRASONICO_H_

#define app_Ultrasonicos_ISR_Task	PIT_IRQHandler

#define APP_ULTRASONICO_MACRO_ENABLE_PIN_INTERRUPT	\
		/* Set timer period for channel 0 */\
		PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, USEC_TO_COUNT(100U, CLOCK_GetFreq(kCLOCK_BusClk)));\
		/* Enable timer interrupts for channel 0 */\
		PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);\
		PIT_StartTimer(PIT, kPIT_Chnl_0)

#define APP_ULTRASONICO_MACRO_DISABLE_PIN_INTERRUPT \
		PIT_DisableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);\
		PIT_StopTimer(PIT, kPIT_Chnl_0)
#define APP_ULTRASONICO_MACRO_TIME_MAX 90U
#define APP_ULTRASONICO_MACRO_NUM_INTENTOS 5U
#define APP_ULTRASONICO_MACRO_NUM_SENSORES N_SENSORS

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

enum
{
	READ_SENSOR1,
	READ_SENSOR2,
	READ_SENSOR3,
	READ_SENSOR4,
	N_SENSORS
};

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
extern void app_Ultrasonicos_Task(void);
extern void app_Ultrasonicos_ISR_Task(void);

#endif /* APP_ULTRASONICO_H_ */
