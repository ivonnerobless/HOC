/*
 * periodic_task_isr.h
 *
 *  Created on: 09/05/2018
 *      Author: Ivonne Robles
 */

#ifndef PERIODIC_TASKS_PERIODIC_TASK_ISR_H_
#define PERIODIC_TASKS_PERIODIC_TASK_ISR_H_

#define periodic_tasks_isr_100us	PIT_IRQHandler





extern void periodic_tasks_isr_100us(void);

extern void periodic_tasks_isr_init (void);



#endif /* PERIODIC_TASKS_PERIODIC_TASK_ISR_H_ */
