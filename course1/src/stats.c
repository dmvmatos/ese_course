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
 * @brief Coursera - Assessment 1
 *
 * Functions implementation, which sort and print statistics of a provided dataset
 * (Implemented sort algorithm inspired in Buble sort)
 *
 * @author Diogo Matos
 * @date 11 March 2018
 *
 */



#include <stdio.h>
#include "../include/common/stats.h"

/* Size of the Data Set */
#define SIZE (40)

#ifdef C1M1
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  
  printf("\n");
  printf("######## Coursera - Assessment 1 ########");
  printf("\n");
  printf("\n");

  printf("Unsorted Data set: \n");
  print_array(test, SIZE);

  printf("\n");
  
  printf("Data set statistics: \n");
  print_statistics(test, SIZE);
  
  printf("\n");
  printf("\n");
  
  sort_array(test, SIZE);~
  printf("Sorted data set  : \n");
  print_array(test, SIZE);
  
  printf("\n");
  
  printf("Data set statistics: \n");
  print_statistics(test, SIZE);

}
#endif

ReturnValue_e print_statistics(unsigned char *dataset, unsigned char len){
  ReturnValue_e ReturnValue = Ok;
  unsigned char maximum = 0;
  unsigned char minimum = 0;
  unsigned char mean = 0;
  unsigned char median = 0;

  maximum = find_maximum(dataset, SIZE);
  printf("Maximum value: %d \n",  maximum);

  minimum = find_minimum(dataset, SIZE);
  printf("Minimum value: %d \n",  minimum);

  mean = find_mean(dataset, SIZE);
  printf("Mean value   : %d \n",  mean);

  median = find_median(dataset, SIZE);
  printf("Median value : %d \n",  median);

  return ReturnValue;
}

ReturnValue_e print_array(unsigned char *dataset, unsigned char len){
  ReturnValue_e ReturnValue = NotOk;
  int i;

  //printf("-> print_array \n");

  if(dataset!=NULL && len!=0){
    for (i=0; i < len; i++){
#ifdef VERBOSE
      PRINTF("%d ", *dataset);
#endif
      dataset++;
      }
      ReturnValue = Ok;
  }
#ifdef VERBOSE
  PRINTF("\n");
#endif
  return ReturnValue;
}

unsigned char find_median(unsigned char *dataset, unsigned char len){
  unsigned char median = 0;
  unsigned char median_pos = len/2;

  median = *(dataset+median_pos-1);

  return median;
}

unsigned char find_mean(unsigned char *dataset, unsigned char len){
  float mean = 0.0;
  float sum = 0.0;
  int i;

  //printf("-> find_mean \n");

  if(dataset!=NULL && len!=0){
    for (i=0; i < len; i++){
      sum = sum + *dataset;
      dataset++;
    }
    mean = sum/len;
  }

  return (unsigned char)mean;
}

unsigned char find_maximum(unsigned char *dataset, unsigned char len){
  int i;
  unsigned char tmp=*dataset;

  //printf("-> find_maximum \n");

  if(dataset!=NULL && len!=0){
    for (i=0; i < len; i++){
      if(tmp<*dataset){
        tmp=*dataset;
      }
      dataset++;
      }
  }

  return tmp;
}

unsigned char find_minimum(unsigned char *dataset, unsigned char len){
  int i;
  unsigned char tmp=*dataset;

  //printf("-> find_minimum \n");

  if(dataset!=NULL && len!=0){
    for (i=0; i < len; i++){
      if(tmp>*dataset){
        tmp=*dataset;
      }
      dataset++;
      }
  }

  return tmp;
}

ReturnValue_e sort_array(unsigned char *dataset, unsigned char len){
  ReturnValue_e ReturnValue = NotOk;
  int i,j;
  unsigned char *tmp=dataset+len-1;

  //printf("-> sort_array \n");

  if(dataset!=NULL && len!=0){
    for (i=(len-1); i >= 0; i--){
      for (j=(len-2); j >= (len-i-1); j--){
        if (*tmp > *(tmp-1)){
          swap(tmp, tmp-1);
        }
        tmp--;
      }
      tmp=dataset+len-1;
    }
    ReturnValue = Ok;
  }

  return ReturnValue;
}

void swap(unsigned char *xp, unsigned char *yp)
{
    unsigned char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

