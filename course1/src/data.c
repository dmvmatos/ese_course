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
 * @brief Coursera - Course 1
 *
 * Functions implementation, to do some very basic data manipulation.
 *
 * @author Diogo Matos
 * @date 09 April 2018
 *
 */

#include "../include/common/data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  int i = 0;
  bool negativeValue = false;

  if(ptr==NULL || base<2 || base>16 || data>4294967295){
    /*Pointer to array in NULL*/
    /*or*/
    /*Base value provided is invalid*/
    /*or*/
    /*Data is overflowed*/
    i=0;   
  }else{     
    /*All provided values seems to be valid*/
    if (data==0){
      /*Integer value is zero*/
      *ptr = '0';
      i++;
      *(++ptr) = '\0';
      i++;
    }else{
      /*Integer value is different than zero*/
      /*Checking is value provided is negative and decimal base*/
      if (data<0){
        negativeValue = true;
        /*remove negative sign*/
        data=-data;
      }
      
      /*Convert the integer value in provided base*/
      while (data!=0){
        int remainderValue = data % base;
        if(remainderValue>9){
          /*special handling for hex values bigger than 9*/
          *(++ptr)=(remainderValue-10)+'a';
        }else{
          *(++ptr)=remainderValue+'0';
        }

        /*incerment iterator*/
        i++;

        /*calculate next 'bit'*/
        data = data/base;
      }

      /*If number is negative, append '-'*/
      if (negativeValue){
        *(++ptr) = '-';
        i++;
      }

      /*Append string terminator*/
      *(++ptr) = '\0';
      i++;

      /* Reverse the string*/
      my_reverse(ptr-i,i);
    }
  }
  
  return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  int32_t integerValue=0;
  uint32_t value=0;
  double power=1;
  bool negativeValue=false;

  if (ptr==NULL || digits<1 || digits>33 || base<2 || base>16){
    /*Pointer to array in NULL*/
    /*or*/
    /*Digits value is invalid */
    /*or*/
    /*Base value provided is invalid*/
    integerValue=0;
  }else{
    if(*ptr=='-'){
      /*String is a ASCII representation of a negative value*/
      negativeValue=true;
      ptr++;
      digits--;
    }

    /*Discounts string null termination*/
    digits--;

    /*Calculate the power valuer for the base conversion, starting from the highest weight*/
    power=pow(base,digits-1);

    /*Check each element of array and converts the same to integer, based on provided base*/
    while(digits>0){ 
      if(*ptr>='0' && *ptr<='9'){
        value=*ptr-'0';
      }else{
        value=*ptr-'a'+10;
      }

      integerValue=integerValue+value*power;
      power=power/base;

      digits--;
      ptr++;
    }

    /*Apply the signal in case of negative value*/
    if(negativeValue==true){
      integerValue=-1*integerValue;
    }
  }
  return integerValue;
}
