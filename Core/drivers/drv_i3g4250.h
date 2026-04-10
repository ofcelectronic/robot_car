/*
 * drv_i3g4250d.h
 *
 *  Created on: Mar 4, 2026
 *      Author: dtnb25
 */

#ifndef DRIVERS_DRV_I3G4250_H_
#define DRIVERS_DRV_I3G4250_H_

#define I3G4250_WHO_AM_I  0x0F

#include <stdint.h>

uint8_t gyro_read(uint8_t reg);

void gyro_write(uint8_t reg, uint8_t value);

void I3G4250_Init(void);

uint8_t I3G4250_ReadWhoAmI(void);

int16_t I3G4250_ReadZ(void);

void I3G4250_ReadXYZ(int16_t *x, int16_t *y, int16_t *z);

void I3G4250_ReadXYZ_dps(float *x, float *y, float *z);

int8_t I3G4250_ReadTempRaw(void);
float I3G4250_ReadTempC(void);

#endif /* DRIVERS_DRV_I3G4250_H_ */
