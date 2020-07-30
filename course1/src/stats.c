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
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

int main1() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int median,mean,max,min;
  /* Statistics and Printing Functions Go Here */
    
    
    //Testing of the functions
    
    print_statistics(test);
    print_array(test,SIZE);
    median=find_median(test,SIZE);
    printf("Median:%d\n", median);
    mean=find_mean(test,SIZE);
    printf("Mean:%d\n", mean);
    max=find_maximum(test,SIZE);
    printf("Maximum:%d\n", max);
    min=find_minimum(test,SIZE);
    printf("Minimum:%d\n", min);
    sort_array(test,SIZE);
    print_array(test,SIZE);
   
    return 0;
}

void swap(unsigned char *xp, unsigned char *yp) { 
        int temp = *xp; 
        *xp = *yp; 
        *yp = temp; 
    }

	void print_statistics(unsigned char arr[]){
		int max=0,i,j,min=arr[0],sum=0;
		for (i=0;i<SIZE;i++){
            sum=sum+arr[i];
			if(max<arr[i])
				max=arr[i];
            if(arr[i]<min)
                min=arr[i];
		}
        
        for (i = 0; i < SIZE-1; i++)          
            for (j = 0; j < SIZE-i-1; j++)  
                if (arr[j] > arr[j+1]) 
                    swap(&arr[j], &arr[j+1]);
        printf("Minimum is:%d \n", min);
        printf("Maximum is:%d \n", max);
        printf("Mean is:%d \n", (sum/SIZE));
        printf("Median is:%d \n", arr[SIZE/2]);
	}
    
    void print_array(unsigned char arr[], unsigned int n){
	#ifdef VERBOSE        
	int i;
        for (i=0;i<n;i++)
            PRINTF("%d ", arr[i]);
        PRINTF("\n");
	#endif
    }
    
    unsigned char find_median(unsigned char arr[], unsigned int n){
        int i,j;
        for (i = 0; i < n-1; i++)          
            for (j = 0; j < n-i-1; j++)  
                if (arr[j] > arr[j+1]) 
                    swap(&arr[j], &arr[j+1]);
        return arr[n/2];
    }
    
    unsigned char find_mean(unsigned char arr[], unsigned int n){
        int i,sum=0;
        for(i=0;i<n;i++)
            sum=sum+arr[i];
        return (sum/n);
    }
    
    unsigned char find_maximum (unsigned char arr[], unsigned int n){
        int i,max=0;
        for (i=0;i<n;i++)
			if(max<arr[i])
				max=arr[i];
        return max;
    }
    
    unsigned char find_minimum (unsigned char arr[], unsigned int n){
        int i,min=arr[0];
        for (i=1;i<n;i++)
            if(arr[i]<min)
                min=arr[i];
        return min;
    }
    
    void sort_array(unsigned char arr[], unsigned int n){
        int i,j;
        for (i = 0; i < n-1; i++)          
            for (j = 0; j < n-i-1; j++)  
                if (arr[j] < arr[j+1]) 
                    swap(&arr[j], &arr[j+1]);
    }

/* Add other Implementation File Code Here */
