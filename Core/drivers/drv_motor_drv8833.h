/*
 * drv_motor_drv8833.h
 *
 *  Created on: Feb 27, 2026
 *      Author: dtnb25
 */

#ifndef DRIVERS_DRV_MOTOR_DRV8833_H_
#define DRIVERS_DRV_MOTOR_DRV8833_H_

#include <stdint.h>
#include <stdbool.h>
#include "drv_motor.h"

void Motor_Drv8833_Init(void);
void Motor_Drv8833_Enable(bool en);
bool Motor_Drv8833_IsFaultActive(void);
void Motor_Drv8833_StopAll(motor_stop_mode_t mode);
void Motor_Drv8833_SetSpeed(motor_id_t id, int16_t speed);


#endif /* DRIVERS_DRV_MOTOR_DRV8833_H_ */
