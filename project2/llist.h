/*****************************************************************
//
//  NAME:        Kalama Abad
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 26, 2022
//
//  FILE:        llist.h
//
//  DESCRIPTION:
//   This file contains function declarations for a database.
//
****************************************************************/

#ifndef LLISTH
#define LLISTH

#include "record.h"
#include <ostream>

class llist
{

private:
    record *    start;
    char        filename[20];
    int         readfile();
    int         writefile();
    void        cleanup();

public:
    llist();
    llist(char[]);
    llist(const llist &obj) throw();
    ~llist();
    void addRecord(int, char [ ],char [ ]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    llist& operator=(const llist&);
};

#endif