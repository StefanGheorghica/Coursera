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
 * @file data.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "data.h"
#include "memory.h"
#include <stdint.h>

uint8_t* my_itoa(int32_t data, uint8_t* ptr, uint32_t base){ 
	int32_t i = 0;
	int32_t rem; 
	uint8_t sign = 0; 

	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (data == 0){ 
		*(ptr+i) = '0';
		i++; 
		*(ptr+i) = '\0'; 
		return ptr; 
	} 

	// In standard itoa(), negative numbers are handled only with 
	// base 10. Otherwise numbers are considered unsigned. 
	//if (data < 0 && base == 10)
	if (data < 0) { 
		sign = 1; 
		data = -data; 
	} 

	// Process individual digits 
	while (data != 0){ 
		rem = data % base;
		if(rem>9)
			*(ptr+i)=(rem-10)+'a';
		else
			*(ptr+i)=rem+'0'; 
		i++;		
		data = data/base;
		 
	} 

	// If number is negative, append '-' 
	if (sign){ 
		*(ptr+i) = '-';
	 	i++;
	}
	*(ptr+i) = '\0'; // Append string terminator 

	// Reverse the string 
	my_reverse(ptr, i); 

	return ptr; 
} 

int32_t my_atoi(uint8_t * ptr, uint32_t digits, uint32_t base){
	// Initialize result 
	digits = 0; 
	// Initialize sign as positive 
	int sign = 1; 
	// Initialize index of first digit 
	int i = 0; 
	// If number is negative, 
	// then update sign 
	if (*ptr == '-') { 
		sign = -1; 
		i++; 
	}
	// Iterate through all digits and update the result 
	for (; *(ptr+i) != '\0'; ++i){ 
		digits = (digits * base) + val(*(ptr+i));  
	}
	// Return result with sign 
	return sign * digits; 
}

uint32_t val(uint8_t c) 
{ 
	if (c >= '0' && c <= '9') 
		return (int)c - '0'; 
	else
		return (int)c - 'A' + 10; 
}
