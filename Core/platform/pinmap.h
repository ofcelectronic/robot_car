/*
 * pinmap.h
 *
 *  Created on: Feb 27, 2026
 *      Author: dtnb25
 */

#ifndef PLATFORM_PINMAP_H_
#define PLATFORM_PINMAP_H_

#include "stm32f4xx_hal.h"

// ===== UART =====
extern UART_HandleTypeDef huart1;
#define CLI_UART (&huart1)

// ===== TIMER =====
extern TIM_HandleTypeDef htim3;

// PWM outputs
#define M_L_IN1_TIM   (&htim3)
#define M_L_IN1_CH    TIM_CHANNEL_1

#define M_L_IN2_TIM   (&htim3)
#define M_L_IN2_CH    TIM_CHANNEL_2

#define M_R_IN1_TIM   (&htim3)
#define M_R_IN1_CH    TIM_CHANNEL_3

#define M_R_IN2_TIM   (&htim3)
#define M_R_IN2_CH    TIM_CHANNEL_4

// control pins
#define DRV_SLEEP_PORT GPIOE
#define DRV_SLEEP_PIN  GPIO_PIN_2  // nSLEEP

#define DRV_FAULT_PORT GPIOC
#define DRV_FAULT_PIN  GPIO_PIN_2   // nFAULT

#endif /* PLATFORM_PINMAP_H_ */
