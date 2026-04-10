/*
 * svc_motion.c
 *
 *  Created on: Mar 1, 2026
 *      Author: dtnb25
 */


#include "svc_motion.h"
#include "drv_motor.h"
#include "ramp.h"

typedef struct
{
    int16_t target_l;
    int16_t target_r;

    int16_t applied_l;
    int16_t applied_r;

    bool enabled;
} motion_ctx_t;

static motion_ctx_t m = {0};

#define RAMP_STEP  20   // 10 ms başına değişim

#define MOTION_SPEED_MAX   1000
#define MOTION_SPEED_MIN  -1000


void Motion_Init(void)
{
    m.target_l = 0;
    m.target_r = 0;
    m.applied_l = 0;
    m.applied_r = 0;
    m.enabled = true;

    Motor_Init();
    Motor_Enable(true);
    Motor_StopAll(MOTOR_MODE_COAST);
}

void Motion_Enable(bool en)
{
    m.enabled = en;
    Motor_Enable(en);

    if (!en)
    {
        m.target_l = 0;
        m.target_r = 0;
        m.applied_l = 0;
        m.applied_r = 0;

        Motor_StopAll(MOTOR_MODE_COAST);
    }
}

void Motion_SetTarget(int16_t left, int16_t right)
{
    m.target_l = ramp_clamp_i16(left,  MOTION_SPEED_MIN, MOTION_SPEED_MAX);
    m.target_r = ramp_clamp_i16(right, MOTION_SPEED_MIN, MOTION_SPEED_MAX);
}


void Motion_Tick_10ms(void)
{
    if (!m.enabled)
        return;

    // ramp uygula
    m.applied_l = ramp_step_i16(m.applied_l,
                                m.target_l,
                                RAMP_STEP);

    m.applied_r = ramp_step_i16(m.applied_r,
                                m.target_r,
                                RAMP_STEP);

    // motora gönder
    Motor_SetSpeed(MOTOR_LEFT,  m.applied_l);
    Motor_SetSpeed(MOTOR_RIGHT, m.applied_r);
}
