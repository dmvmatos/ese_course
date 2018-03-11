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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

typedef enum Return{
    Ok = 0,
    NotOk = 1
}ReturnValue_e;


/**
 * @brief A function that prints the statistics of an array
 *
 * Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param dataset Input data vector
 * @param len Nr of element of data vector
 *
 * @return General return information (Ok, Not Ok)
 */
ReturnValue_e print_statistics(unsigned char *dataset, unsigned char len);

/**
 * @brief Prints the array to the screen
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param dataset Input data vector
 * @param len Nr of element of data vector
 *
 * @return General return information (Ok, Not Ok)
 */
ReturnValue_e print_array(unsigned char *dataset, unsigned char len);

/**
 * @brief Calculates the median value
 *
 * Given an array of data and a length, returns the median value
 *
 * @param dataset Input data vector
 * @param len Nr of element of data vector
 *
 * @return The median value
 */
unsigned char find_median(unsigned char *dataset, unsigned char len);

/**
 * @brief Calculates the mean value
 *
 * Given an array of data and a length, returns the mean
 *
 * @param dataset Input data vector
 * @param len Nr of element of data vector
 *
 * @return The mean value
 */
unsigned char find_mean(unsigned char *dataset, unsigned char len);

/**
 * @brief Calculates the maximum value
 *
 * Given an array of data and a length, returns the maximum
 *
 * @param dataset Input data vector
 * @param len Nr of element of data vector
 *
 * @return The maximum value
 */
unsigned char find_maximum(unsigned char *dataset, unsigned char len);

/**
 * @brief Calculates the minimum value
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param dataset Input data vector
 * @param len Nr of element of data vector
 *
 * @return The minimum value
 */
unsigned char find_minimum(unsigned char *dataset, unsigned char len);

/**
 * @brief Sorts the array from largest to smallest
 *
 * Given an array of data and a length, , sorts the array from largest to smallest. 
 * (The zeroth Element will be the largest value, and the last element (n-1) will be the smallest value. )
 *
 * @param dataset Input data vector
 * @param len Nr of element of data vector
 *
 * @return The minimum value
 */
ReturnValue_e sort_array(unsigned char *dataset, unsigned char len);

#endif /* __STATS_H__ */
