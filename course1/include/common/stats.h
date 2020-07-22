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
 * @brief analyze an array of unsigned char data items and report analytics on the maximum,       minimum, mean, and median of the data set
 *
 * print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
 * print_array() - Given an array of data and a length, prints the array to the screen
 * find_median() - Given an array of data and a length, returns the median value
 * find_mean() - Given an array of data and a length, returns the mean
 * find_maximum() - Given an array of data and a length, returns the maximum
 * find_minimum() - Given an array of data and a length, returns the minimum
 * sort_array() - Given an array of data and a length, sorts the array from largest to smallest. 
 *
 * @author Stefan Gheorghica
 * @date 07/13/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void swap(unsigned char *xp, unsigned char *yp);
/**
 * @brief Swaps 2 numbers
 *
 * This function takes as input 2 unsigned char pointers and it will swap the values they point to
 *
 * @param pointer *xp ; x position
 * @param pointer *yp ; y position
 * @return NONE
 */

void print_statistics(unsigned char arr[]);
/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function takes as input an array and it will process the information so that it will display minimum, maximum, mean, and median values.
 *
 * @param array
 * @return NONE
 */

void print_array(unsigned char arr[], unsigned int n);
/**
 * @brief prints an array to the screen
 *
 * This function takes as input an array and it will print it to the screen
 *
 * @param un unsigned char array
 * @param an unsigned int lenght of array
 * @return NONE
 */

unsigned char find_median(unsigned char arr[], unsigned int n);
/**
 * @brief returns the median value of an array
 *
 * This function takes as input an array and the lenght of that array and it will process that array, returns the median value 
 *
 * @param un unsigned char array
 * @param an unsigned int lenght of array
 * @return an unsigned char value
 */

unsigned char find_mean(unsigned char arr[], unsigned int n);
/**
 * @brief returns the mean value of an array
 *
 * This function takes as input an array and the lenght of that array and it will process that array, returns the mean value 
 *
 * @param un unsigned char array
 * @param an unsigned int lenght of array
 * @return an unsigned char value
 */

unsigned char find_maximum(unsigned char arr[], unsigned int n);
/**
 * @brief returns the maximum value of an array
 *
 * This function takes as input an array and the lenght of that array and it will process that array, returns the maximum value 
 *
 * @param un unsigned char array
 * @param an unsigned int lenght of array
 * @return an unsigned char value
 */

unsigned char find_minimum(unsigned char arr[], unsigned int n);
/**
 * @brief returns the minimum value of an array
 *
 * This function takes as input an array and the lenght of that array and it will process that array, returns the minimum value 
 *
 * @param un unsigned char array
 * @param an unsigned int lenght of array
 * @return an unsigned char value
 */

void sort_array(unsigned char arr[], unsigned int n);
/**
 * @brief sorts an array from largest to smallest
 *
 * This function takes as input an array and the lenght of that array and it will process that array and sorts it from largest to smallest 
 *
 * @param un unsigned char array
 * @param an unsigned int lenght of array
 * @return NONE
 */

#endif /* __STATS_H__ */
