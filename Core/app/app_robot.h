/*
 * app_robot.h
 *
 *  Created on: Mar 4, 2026
 *      Author: dtnb25
 */

#ifndef APP_APP_ROBOT_H_
#define APP_APP_ROBOT_H_

#include "stm32f4xx_hal.h"

void App_Init(void);
void App_Tick_10ms(void);
void Robot_ForwardGyro(int16_t speed);
void Robot_Forward(int16_t speed);
void Robot_TurnLeft(int16_t speed);
void Robot_TurnRight(int16_t speed);
void Robot_Stop(void);
void Robot_TurnAngle(float angle);



#endif /* APP_APP_ROBOT_H_ */
