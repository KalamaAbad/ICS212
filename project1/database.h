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
//  FILE:        database.h
//
//  DESCRIPTION:
//   This file Contains a structure for a database.
//
****************************************************************/
#include "record.h"
    void add(struct record **, int, char [], char []);
    void printAllRecords(struct record *);
    int findRecord (struct record *, int);
    int deleteRecord(struct record **, int);
    int writefile(struct record *, char []);
    int readfile(struct record **, char []);
    void cleanup(struct record **);

