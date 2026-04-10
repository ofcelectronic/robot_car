/*
 * drv_motor.h
 *
 *  Created on: Feb 27, 2026
 *      Author: dtnb25
 */

#ifndef DRIVERS_DRV_MOTOR_H_
#define DRIVERS_DRV_MOTOR_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    MOTOR_LEFT = 0,
    MOTOR_RIGHT
} motor_id_t;

typedef enum
{
    MOTOR_MODE_COAST = 0,
    MOTOR_MODE_BRAKE
} motor_stop_mode_t;

void Motor_Init(void);
void Motor_Enable(bool en);
bool Motor_IsFaultActive(void);
void Motor_StopAll(motor_stop_mode_t mode);
void Motor_SetSpeed(motor_id_t id, int16_t speed);


#endif /* DRIVERS_DRV_MOTOR_H_ */
