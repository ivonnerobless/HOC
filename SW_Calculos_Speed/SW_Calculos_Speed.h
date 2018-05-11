/*
 * SW_Calculos_Speed.h
 *
 *  Created on: Apr 25, 2018
 *      Author: Omar Sevilla
 */

#ifndef SW_CALCULOS_SPEED_H_
#define SW_CALCULOS_SPEED_H_

#define MACRO_SPEED_ISANOBSTACLE			rub_DetectaObstaculo
#define MACRO_SPEED_IS_DIRECTION_VALID		rub_IsDirectionValid
#define MACRO_SPEED_MULTIPLIER				10u
#define MACRO_SPEED_STOP_VALUE				0u

#define MACRO_FORCE_MIN			0u
#define MACRO_FORCE_MAX			5u
#define MACRO_SPEED_MIN			0u
#define MACRO_SPEED_MAX			200u // 200rpm
#define MACRO_CONSTANT_SPEED	40u

extern void app_Speed_Init(void);
extern void app_Speed_MngTask(void);

//#define rub_Force 30U//

#endif /* SW_CALCULOS_SPEED_H_ */
