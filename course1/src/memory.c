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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Diogo Matos
 * @date April 9 2018
 *
 */
#include "../include/common/memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  //Check of null pointers
  if (src==NULL || dst==NULL || length==0){ 
    return NULL;
  }

  //Overlap checking
  if (src<dst && dst<(src+length)){
    //There is overlap -> dst is an addr inside "src begin" and "src end"
  
    //Move data end to begin (workaround...)
    for(int i=length-1; i>=0; i--){
      *(dst+i)=*(src+i);    
    }

  }else{
    //Move data begin to end   
    for(unsigned int i=0; i<length; i++){
      *(dst+i) = *(src+i);
    }
  }

  //Return dst pointer
  return dst;
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  //Check of null pointers
  if (src==NULL || dst==NULL || length==0){
    return NULL;
  }

  //Move data
  for(unsigned int i=0; i<length; i++){
    *dst = *src;
    dst++;
    src++;
  }

  //Return dst pointer
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  //Check of null pointers
  if (src==NULL || length==0){
    return NULL;
  }

  //Sets memory location
  for(unsigned int i=0; i<length; i++){
    *src = value;
    src++;
  }

  //Return dst pointer
  return src;  
}

uint8_t * my_memzero(uint8_t * src, size_t length){
  //Check of null pointers
  if (src==NULL || length==0){
    return NULL;
  }

  //Sets memory location
  for(unsigned int i=0; i<length; i++){
    *src = 0u;
    src++;
  }

  //Return dst pointer
  return src;  
}

uint8_t * my_reverse(uint8_t * src, size_t length){
  //uint8_t tmp;
  uint8_t *opposite_byte=src+length-1; 

  //Check of null pointers
  if (src==NULL || length==0){
    return NULL;
  }

  //swap the content on memory data
  while(opposite_byte>src){
    //swap the values
    swap(src,opposite_byte);
    //update the pointers
    src++;
    opposite_byte--;
  }

  //Return dst pointer
  return src;  
}

int32_t * reserve_words(size_t length){

  return malloc (length*sizeof(int32_t));

}

void free_words(int32_t * src){
  free(src);
  src=NULL;
}


