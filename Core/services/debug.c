/*
 * uartdebug.c
 *
 *  Created on: Mar 9, 2026
 *      Author: dtnb25
 */
#include "main.h"
#include <stdio.h>
#include <stdint.h>

extern UART_HandleTypeDef huart1;

int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)ptr, len, HAL_MAX_DELAY);
    return len;
}


void Check_Reset_Source(void)
{
    if (__HAL_RCC_GET_FLAG(RCC_FLAG_PORRST))
    {
        printf("Reset Source: Power-On Reset\r\n");
    }

    if (__HAL_RCC_GET_FLAG(RCC_FLAG_BORRST))
    {
        printf("Reset Source: Brown-Out Reset (Voltage Drop)\r\n");
    }

    if (__HAL_RCC_GET_FLAG(RCC_FLAG_PINRST))
    {
        printf("Reset Source: NRST Pin Reset\r\n");
    }

    if (__HAL_RCC_GET_FLAG(RCC_FLAG_SFTRST))
    {
        printf("Reset Source: Software Reset\r\n");
    }

    if (__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST))
    {
        printf("Reset Source: Independent Watchdog Reset\r\n");
    }

    if (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST))
    {
        printf("Reset Source: Window Watchdog Reset\r\n");
    }

    if (__HAL_RCC_GET_FLAG(RCC_FLAG_LPWRRST))
    {
        printf("Reset Source: Low Power Reset\r\n");
    }

    // Flagleri temizle (bir sonraki reseti doğru görmek için)
    __HAL_RCC_CLEAR_RESET_FLAGS();
}
