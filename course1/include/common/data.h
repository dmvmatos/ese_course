/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Header file of Stats.c
 *
 *
 * @author Diogo Matos
 * @date 11/03/2018
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "memory.h"

/**
 * @brief Convert data from a standard integer type into an ASCII string
 *
 * @param data Integer value
 * @param ptr Converted character string
 * @param base Base to convert to (support bases 2 to 16)
 *
 * @return Length of the converted data (including a negative sign)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert data back from an ASCII represented string into an integer type
 *
 * @param ptr Converted character string
 * @param digits Length of the converted data (including a negative sign)
 * @param base Base of converted data (support bases 2 to 16)
 *
 * @return Integer value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */

