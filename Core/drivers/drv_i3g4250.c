/*
 * drv_i3g4250.c
 *
 *  Created on: Mar 4, 2026
 *      Author: dtnb25
 */

#include <drv_i3g4250.h>
#include "main.h"
#include <stdint.h>

extern SPI_HandleTypeDef hspi5;

#define GYRO_CS_PORT GPIOC
#define GYRO_CS_PIN  GPIO_PIN_1


#define CTRL_REG1 0x20

#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D


static void cs_low(void)
{
    HAL_GPIO_WritePin(GYRO_CS_PORT, GYRO_CS_PIN, GPIO_PIN_RESET);
}

static void cs_high(void)
{
    HAL_GPIO_WritePin(GYRO_CS_PORT, GYRO_CS_PIN, GPIO_PIN_SET);
}

uint8_t gyro_read(uint8_t reg)
{
    uint8_t tx[2];
    uint8_t rx[2];

    tx[0] = reg | 0x80; //1000 0000
    tx[1] = 0;

    cs_low();

    HAL_SPI_TransmitReceive(&hspi5, tx, rx, 2, HAL_MAX_DELAY);

    cs_high();

    return rx[1];
}

void gyro_write(uint8_t reg, uint8_t value)
{
    uint8_t tx[2];

    tx[0] = reg & 0x7F;
    tx[1] = value;

    cs_low();

    HAL_SPI_Transmit(&hspi5, tx, 2, HAL_MAX_DELAY);

    cs_high();
}

uint8_t I3G4250_ReadWhoAmI(void)
{
    return gyro_read(I3G4250_WHO_AM_I); //D3

}

void I3G4250_Init(void)
{
    gyro_write(CTRL_REG1, 0x0F);
}

int16_t I3G4250_ReadZ(void)
{
    uint8_t zl = gyro_read(OUT_Z_L);
    uint8_t zh = gyro_read(OUT_Z_H);

    return (int16_t)((zh << 8) | zl);
}

void I3G4250_ReadXYZ(int16_t *x, int16_t *y, int16_t *z)
{
    uint8_t xl = gyro_read(0x28);
    uint8_t xh = gyro_read(0x29);

    uint8_t yl = gyro_read(0x2A);
    uint8_t yh = gyro_read(0x2B);

    uint8_t zl = gyro_read(0x2C);
    uint8_t zh = gyro_read(0x2D);

    *x = (int16_t)((xh << 8) | xl);
    *y = (int16_t)((yh << 8) | yl);
    *z = (int16_t)((zh << 8) | zl);
}

#define GYRO_SENS 0.00875f

void I3G4250_ReadXYZ_dps(float *x, float *y, float *z)
{
    int16_t rx, ry, rz;

    I3G4250_ReadXYZ(&rx, &ry, &rz);

    *x = rx * GYRO_SENS;
    *y = ry * GYRO_SENS;
    *z = rz * GYRO_SENS;
}

int8_t I3G4250_ReadTempRaw(void)
{
    uint8_t temp;

    temp = gyro_read(0x26);

    return (int8_t)temp;
}

float I3G4250_ReadTempC(void)
{
    int8_t raw = I3G4250_ReadTempRaw();

    return 25.0f + raw;
}

