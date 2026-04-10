/*
 * drv_motor.c
 *
 *  Created on: Feb 27, 2026
 *      Author: dtnb25
 */

#include <stdint.h>

#include "drv_motor.h"

// ===== Driver seçimi =====
#define MOTOR_DRIVER_DRV8833   1

#if MOTOR_DRIVER_DRV8833
#include "drv_motor_drv8833.h"
#endif

void Motor_Init(void)
{
#if MOTOR_DRIVER_DRV8833
    Motor_Drv8833_Init();
#endif
}

void Motor_Enable(bool en)
{
#if MOTOR_DRIVER_DRV8833
    Motor_Drv8833_Enable(en);
#endif
}

bool Motor_IsFaultActive(void)
{
#if MOTOR_DRIVER_DRV8833
    return Motor_Drv8833_IsFaultActive();
#else
    return false;
#endif
}

void Motor_StopAll(motor_stop_mode_t mode)
{
#if MOTOR_DRIVER_DRV8833
    Motor_Drv8833_StopAll(mode);
#endif
}

void Motor_SetSpeed(motor_id_t id, int16_t speed)
{
#if MOTOR_DRIVER_DRV8833
    Motor_Drv8833_SetSpeed(id, speed);
#endif
}
