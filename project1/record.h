/*****************************************************************
//
//  NAME:        Kalama Abad
//
//  HOMEWORK:    3
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        September 12, 2022
//
//  FILE:        record.h
//
//  DESCRIPTION:
//   This file contains a structure for a record.
//
****************************************************************/

struct record
{
    int accountno;
    char name[30];
    char address[50];
    struct record* next;
};
