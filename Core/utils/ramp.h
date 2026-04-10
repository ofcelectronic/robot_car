/*
 * ramp.h
 *
 *  Created on: Mar 1, 2026
 *      Author: dtnb25
 */

#ifndef UTILS_RAMP_H_
#define UTILS_RAMP_H_

#include <stdint.h>

int16_t ramp_step_i16(int16_t current,
                      int16_t target,
                      int16_t step);

int16_t ramp_clamp_i16(int16_t current,
                      int16_t target,
                      int16_t step);
#endif /* UTILS_RAMP_H_ */
