/*
 * drv_bluetoothoruart.h
 *
 *  Created on: Mar 18, 2026
 *      Author: dtnb25
 */

#ifndef APP_DRV_BLUETOOTHORUART_H_
#define APP_DRV_BLUETOOTHORUART_H_



#include "main.h"
#include <stdint.h>
#include <stdbool.h>

#define BT_RX_LINE_LEN   32

void Bluetooth_Init(UART_HandleTypeDef *huart);
void Bluetooth_StartReceiveIT(void);
void Bluetooth_RxCpltCallback(UART_HandleTypeDef *huart);

bool Bluetooth_IsLineReady(void);
void Bluetooth_GetLine(char *dest, uint16_t max_len);

#endif /* APP_DRV_BLUETOOTHORUART_H_ */
