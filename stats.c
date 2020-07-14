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
 * @file stats.c
 * @brief analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set
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



#include <stdio.h>
//#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int median,mean,max,min;
  /* Statistics and Printing Functions Go Here */
    void swap(unsigned char *xp, unsigned char *yp) { 
         
    }

    void print_statistics(unsigned char arr[]){
		
    
    void print_array(unsigned char arr[], unsigned int n){
        
    }
    
    unsigned char find_median(unsigned char arr[], unsigned int n){
       
    }
    
    unsigned char find_mean(unsigned char arr[], unsigned int n){
        
    }
    
    unsigned char find_maximum (unsigned char arr[], unsigned int n){
        
    }
    
    unsigned char find_minimum (unsigned char arr[], unsigned int n){
        
    }
    
    void sort_array(unsigned char arr[], unsigned int n){
       
    }
    
    //Testing of the functions
    
    //print_statistics(test);
    //print_array(test,SIZE);
    //median=find_median(test,SIZE);
    //printf("Median:%d\n", median);
    //mean=find_mean(test,SIZE);
    //printf("Mean:%d\n", mean);
    //max=find_maximum(test,SIZE);
    //printf("Maximum:%d\n", max);
    //min=find_minimum(test,SIZE);
    //printf("Minimum:%d\n", min);
    //sort_array(test,SIZE);
    //print_array(test,SIZE);
}

/* Add other Implementation File Code Here */
