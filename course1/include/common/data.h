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
#ifndef __DATA_H__
#define __DATA_H__
#include <stdint.h>

uint32_t val(uint8_t c); 

uint8_t* my_itoa(int32_t data, uint8_t* ptr, uint32_t base);

int32_t my_atoi(uint8_t * ptr, uint32_t digits, uint32_t base);

#endif



