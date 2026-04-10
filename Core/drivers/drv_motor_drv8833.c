/*
 * drv_motor_drv8833.c
 *
 *  Created on: Feb 27, 2026
 *      Author: dtnb25
 */

#include "drv_motor.h"
#include "pinmap.h"
#include <stdlib.h>

#define PWM_MAX 499   // TIM3 ARR=499 ise böyle. İleride otomatik okuturuz.

static inline uint16_t clamp_u16(int32_t v, uint16_t lo, uint16_t hi)
{
    if (v < (int32_t)lo) return lo;
    if (v > (int32_t)hi) return hi;
    return (uint16_t)v;
}

static inline int16_t clamp_i16(int16_t v, int16_t lo, int16_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static void pwm_start_all(void)
{
    HAL_TIM_PWM_Start(M_L_IN1_TIM, M_L_IN1_CH);
    HAL_TIM_PWM_Start(M_L_IN2_TIM, M_L_IN2_CH);
    HAL_TIM_PWM_Start(M_R_IN1_TIM, M_R_IN1_CH);
    HAL_TIM_PWM_Start(M_R_IN2_TIM, M_R_IN2_CH);
}

static void pwm_write(TIM_HandleTypeDef *htim, uint32_t ch, uint16_t duty)
{
    __HAL_TIM_SET_COMPARE(htim, ch, duty);
}

static void motor_apply_left(uint16_t in1, uint16_t in2)
{
    pwm_write(M_L_IN1_TIM, M_L_IN1_CH, in1);
    pwm_write(M_L_IN2_TIM, M_L_IN2_CH, in2);
}

static void motor_apply_right(uint16_t in1, uint16_t in2)
{
    pwm_write(M_R_IN1_TIM, M_R_IN1_CH, in1);
    pwm_write(M_R_IN2_TIM, M_R_IN2_CH, in2);
}

void Motor_Drv8833_Enable(bool en)
{
    // nSLEEP: 1 = aktif, 0 = sleep
    HAL_GPIO_WritePin(DRV_SLEEP_PORT, DRV_SLEEP_PIN, en ? GPIO_PIN_SET : GPIO_PIN_RESET);

    // Datasheet’te uyanma süresi tipik çok kısa; güvenli tarafta kalalım
    if (en) HAL_Delay(2);
}

bool Motor_Drv8833_IsFaultActive(void)
{
    // nFAULT aktif-low (open drain)
    return (HAL_GPIO_ReadPin(DRV_FAULT_PORT, DRV_FAULT_PIN) == GPIO_PIN_RESET);
}

void Motor_Drv8833_StopAll(motor_stop_mode_t mode)
{
    if (mode == MOTOR_MODE_COAST)
    {
        // 0/0 -> coast
        motor_apply_left(0, 0);
        motor_apply_right(0, 0);
    }
    else
    {
        // 100%/100% -> brake (aktif fren)
        motor_apply_left(PWM_MAX, PWM_MAX);
        motor_apply_right(PWM_MAX, PWM_MAX);
    }
}

void Motor_Drv8833_Init(void)
{
    pwm_start_all();
    Motor_Enable(true);
    Motor_StopAll(MOTOR_MODE_COAST);
}

void Motor_Drv8833_SetSpeed(motor_id_t id, int16_t speed)
{
    speed = clamp_i16(speed, -1000, 1000);

    uint16_t duty = clamp_u16(((int32_t)abs(speed) * PWM_MAX) / 1000, 0, PWM_MAX);

    // DRV8833 “tek pin PWM” mantığı:
    // ileri: IN1=duty, IN2=0
    // geri : IN1=0,   IN2=duty
    // stop : 0/0
    uint16_t in1 = 0, in2 = 0;
    if (speed > 0) { in1 = duty; in2 = 0; }
    else if (speed < 0) { in1 = 0; in2 = duty; }
    else { in1 = 0; in2 = 0; }

    if (id == MOTOR_LEFT) motor_apply_left(in1, in2);
    else motor_apply_right(in1, in2);
}
