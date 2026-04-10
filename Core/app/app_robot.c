/*
 * app_robot.c
 *
 *  Created on: Mar 4, 2026
 *      Author: dtnb25
 */
#include "svc_motion.h"
#include "svc_heading.h"
#include <stdio.h>
#include <math.h>

#define FORWARD_KP 5.0f
#define TURN_KP 10.0f
#define TURN_MAX_SPEED 1000
#define TURN_MIN_SPEED 710

//static uint8_t demo_step = 0;  //demo için
//static uint32_t demo_timer = 0; //demo için


typedef enum
{
    ROBOT_IDLE,
    ROBOT_FORWARD,
    ROBOT_TURN_LEFT,
    ROBOT_TURN_RIGHT,
	ROBOT_FORWARD_GYRO,

} robot_state_t;

typedef struct
{
    robot_state_t state;

    int16_t speed_l;
    int16_t speed_r;

    float target_angle;

} robot_ctx_t;

static robot_ctx_t r;


void App_Init(void)
{
    Motion_Init();
    Heading_Init();

    printf("Gyro calibrating...\r\n");

    Heading_Calibrate();

    printf("Calibration done\r\n");

    r.state = ROBOT_IDLE;
}

void Robot_ForwardGyro(int16_t speed)
{
    r.speed_l = -speed;//- yön değişimi için
    r.speed_r = -speed;

    r.target_angle = Heading_GetYaw();

    r.state = ROBOT_FORWARD_GYRO;
}

void Robot_Forward(int16_t speed)
{
    r.speed_l = speed;
    r.speed_r = speed;

    r.state = ROBOT_FORWARD;
}

void Robot_TurnLeft(int16_t speed)
{
    r.speed_l = -speed;
    r.speed_r = speed;

    r.state = ROBOT_TURN_LEFT;
}

void Robot_TurnRight(int16_t speed)
{
    r.speed_l = speed;
    r.speed_r = -speed;

    r.state = ROBOT_TURN_RIGHT;
}

void Robot_Stop(void)
{
    r.speed_l = 0;
    r.speed_r = 0;

    r.state = ROBOT_IDLE;
}

void Robot_TurnAngle(float angle)
{
    Heading_Init();

    r.target_angle = angle;

    if(angle > 0)
        r.state = ROBOT_TURN_LEFT;
    else
        r.state = ROBOT_TURN_RIGHT;
}


void App_Tick_10ms(void)
{
    Motion_Tick_10ms();
    Heading_Update();

    switch(r.state)
    {

    case ROBOT_FORWARD:

        Motion_SetTarget(r.speed_l, r.speed_r);

    break;

    case ROBOT_FORWARD_GYRO:
    {
        float error = r.target_angle - Heading_GetYaw();

        float correction = error * FORWARD_KP;

        int16_t left  = r.speed_l - correction;
        int16_t right = r.speed_r + correction;

        if(left > 1000) left = 1000;
        if(left < -1000) left = -1000;

        if(right > 1000) right = 1000;
        if(right < -1000) right = -1000;

        Motion_SetTarget(left, right);
    }
    break;

    case ROBOT_TURN_LEFT:
    {
        float error = r.target_angle - Heading_GetYaw();

        int16_t speed = (int16_t)(TURN_KP * error);

        if(speed > TURN_MAX_SPEED) speed = TURN_MAX_SPEED;
        if(speed < TURN_MIN_SPEED) speed = TURN_MIN_SPEED;

        Motion_SetTarget(-speed, speed);

        if(fabs(error) < 2.0f)
        {
            Motion_SetTarget(0,0);
            r.state = ROBOT_IDLE;
        }
    }
    break;

    case ROBOT_TURN_RIGHT:
    {
        float error = r.target_angle - Heading_GetYaw();

        int16_t speed = (int16_t)(TURN_KP * error);

        if(speed > TURN_MAX_SPEED) speed = TURN_MAX_SPEED;
        if(speed < TURN_MIN_SPEED) speed = TURN_MIN_SPEED;

        Motion_SetTarget(speed, -speed);

        if(fabs(error) < 2.0f)
        {
            Motion_SetTarget(0,0);
            r.state = ROBOT_IDLE;
        }
    }
    break;


    case ROBOT_IDLE:

        Motion_SetTarget(0,0);

    break;

//    if(r.state == ROBOT_IDLE)       *************************demo*****************************************-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {
//        switch(demo_step)
//        {
//            case 0:
//
//                Robot_Forward(600);
//                demo_timer = HAL_GetTick();
//                demo_step = 1;
//
//            break;
//
//            case 1:
//
//                if(HAL_GetTick() - demo_timer > 5000)
//                {
//                    Robot_TurnAngle(-90);
//                    demo_step = 2;
//                }
//
//            break;
//
//            case 2:
//
//                if(r.state == ROBOT_IDLE)
//                {
//                    Robot_Forward(600);
//                    demo_timer = HAL_GetTick();
//                    demo_step = 3;
//                }
//
//            break;
//
//            case 3:
//
//                if(HAL_GetTick() - demo_timer > 5000)
//                {
//                    Robot_TurnAngle(90);
//                    demo_step = 4;
//                }
//
//            break;
//
//            case 4:
//
//                if(r.state == ROBOT_IDLE)
//                {
//                    Robot_Forward(600);
//                    demo_timer = HAL_GetTick();
//                    demo_step = 5;
//                }
//
//            break;
//
//            case 5:
//
//                if(HAL_GetTick() - demo_timer > 5000)
//                {
//                    Robot_Stop();
//                    demo_step = 6;
//                }
//
//            break;
//        }
//    }

    }
}
