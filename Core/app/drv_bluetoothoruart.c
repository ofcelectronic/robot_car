/*
 * drv_bluetoothoruart.c
 *
 *  Created on: Mar 18, 2026
 *      Author: dtnb25
 */


#include "drv_bluetoothoruart.h"
#include <string.h>

static UART_HandleTypeDef *bt_huart = NULL;
static uint8_t bt_rx_byte = 0;

static char bt_line_buffer[BT_RX_LINE_LEN];
static char bt_ready_line[BT_RX_LINE_LEN];

static volatile uint16_t bt_index = 0;
static volatile bool bt_line_ready = false;

void Bluetooth_Init(UART_HandleTypeDef *huart)
{
    bt_huart = huart;
    bt_rx_byte = 0;
    bt_index = 0;
    bt_line_ready = false;

    memset(bt_line_buffer, 0, sizeof(bt_line_buffer));
    memset(bt_ready_line, 0, sizeof(bt_ready_line));
}

void Bluetooth_StartReceiveIT(void)
{
    if (bt_huart != NULL)
    {
        HAL_UART_Receive_IT(bt_huart, &bt_rx_byte, 1);
    }
}

void Bluetooth_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart != bt_huart)
        return;

    char c = (char)bt_rx_byte;

    if (!bt_line_ready)
    {
        if (c == '\r')
        {
            // ignore
        }
        else if (c == '\n')
        {
            bt_line_buffer[bt_index] = '\0';

            strncpy(bt_ready_line, bt_line_buffer, BT_RX_LINE_LEN - 1);
            bt_ready_line[BT_RX_LINE_LEN - 1] = '\0';

            bt_line_ready = true;
            bt_index = 0;
            memset(bt_line_buffer, 0, sizeof(bt_line_buffer));
        }
        else
        {
            if (bt_index < (BT_RX_LINE_LEN - 1))
            {
                bt_line_buffer[bt_index++] = c;
            }
            else
            {
                bt_index = 0;
                memset(bt_line_buffer, 0, sizeof(bt_line_buffer));
            }
        }
    }

    HAL_UART_Receive_IT(bt_huart, &bt_rx_byte, 1);
}

bool Bluetooth_IsLineReady(void)
{
    return bt_line_ready;
}

void Bluetooth_GetLine(char *dest, uint16_t max_len)
{
    if (dest == NULL || max_len == 0)
        return;

    strncpy(dest, bt_ready_line, max_len - 1);
    dest[max_len - 1] = '\0';

    bt_line_ready = false;
}
