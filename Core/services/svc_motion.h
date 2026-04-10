/*
 * svc_motion.h
 *
 *  Created on: Mar 1, 2026
 *      Author: dtnb25
 */

#ifndef SERVICES_SVC_MOTION_H_
#define SERVICES_SVC_MOTION_H_

#include <stdint.h>
#include <stdbool.h>

void Motion_Init(void);
void Motion_Enable(bool en);

void Motion_SetTarget(int16_t left, int16_t right);

void Motion_Tick_10ms(void);

#endif /* SERVICES_SVC_MOTION_H_ */
