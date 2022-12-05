/*****************************************************************
//
//  NAME:        Kalama Abad
//
//  HOMEWORK:    Homework 9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 3, 2022
//
//  FILE:        homework9.c
//
//  DESCRIPTION: This file contains a single c function for seeing if a number is a multiple
//				 of four.
//
****************************************************************/

#include "homework9.h"

/*****************************************************************
//
//  Function name: isMultiple4
//
//  DESCRIPTION:   Checks if a number is a multiple of four.
//
//  Parameters:    num (int) : The number to check.
//                
//  Return values: 1 if num is a multiple of four, zero if not.
//
****************************************************************/

JNIEXPORT jint JNICALL Java_homework9_isMultiple4 (JNIEnv *env, jclass homework9, jint num)
{
    return (num % 4 == 0) ? 1 : 0;
}