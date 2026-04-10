/*
 * svc_heading.c
 *
 *  Created on: Mar 4, 2026
 *      Author: dtnb25
 */

#include "stm32f4xx_hal.h"
#include "svc_heading.h"
#include "drv_i3g4250.h"
#include <stdio.h>



#define DT 0.01f

static float yaw = 0;
static float pitch = 0;
static float roll = 0;
static float temp = 0;

static float gyro_offset_x = 0;
static float gyro_offset_y = 0;
static float gyro_offset_z = 0;


void Heading_Init(void)
{
    roll = 0;
    pitch = 0;
    yaw = 0;

    gyro_offset_x = 0;
    gyro_offset_y = 0;
    gyro_offset_z = 0;

    I3G4250_Init();
}

void Heading_Calibrate(void)
{
    float gx, gy, gz;

    float sum_x = 0;
    float sum_y = 0;
    float sum_z = 0;

    for(int i = 0; i < 500; i++)
    {
        I3G4250_ReadXYZ_dps(&gx, &gy, &gz);

        sum_x += gx;
        sum_y += gy;
        sum_z += gz;

        HAL_Delay(5);
    }

    gyro_offset_x = sum_x / 500.0f;
    gyro_offset_y = sum_y / 500.0f;
    gyro_offset_z = sum_z / 500.0f;
}

void Heading_Update(void)
{
    float gx, gy, gz;

    I3G4250_ReadXYZ_dps(&gx, &gy, &gz);

    gx -= gyro_offset_x;
    gy -= gyro_offset_y;
    gz -= gyro_offset_z;

    roll  += gx * DT;
    pitch += gy * DT;
    yaw   += gz * DT;
}

float Heading_GetYaw(void)
{
    return yaw;
}

float Heading_GetPitch(void)
{
    return pitch;
}

float Heading_GetRoll(void)
{
    return roll;
}

float Heading_GetTemp(void)
{
	temp = I3G4250_ReadTempC();
	return temp;
}


void Heading_Print(void)
{
    printf("R=%.2f P=%.2f Y=%.2f\r\n", roll, pitch, yaw);
    temp = I3G4250_ReadTempC();
    printf("Temp= %.2f C\r\n", temp);
}

void TestWhoAmI(uint8_t who)
{
	uint8_t id = gyro_read(who);
	printf("WHOAMI = %02X\r\n", id);  //d3
}

