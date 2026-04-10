/*
 * ramp.c
 *
 *  Created on: Mar 1, 2026
 *      Author: dtnb25
 */


#include "ramp.h"

int16_t ramp_clamp_i16(int16_t v,
                       int16_t lo,
                       int16_t hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

int16_t ramp_step_i16(int16_t current,
                      int16_t target,
                      int16_t step)
{
    int32_t diff = (int32_t)target - (int32_t)current;

    if (diff > step)
        return current + step;

    if (diff < -step)
        return current - step;

    return target;
}
