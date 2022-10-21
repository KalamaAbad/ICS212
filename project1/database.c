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
//  FILE:        database.c
//
//  DESCRIPTION:
//   This file contains functions for reading and writing to the database.
//
****************************************************************/

#include "record.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int debug;

/*****************************************************************
//
//  Function name: add
//
//  DESCRIPTION:   Adds a record to the database.
//                 
//                 
//  Parameters:    record (**record) : 
//                 uaccountno (int)  : User account number.
//                 uname (char[])    : Name to be added to record.
//                 uaddress (char[]) : Address to be added to record.
//
//  Return values: None.
//              
//
****************************************************************/

void add(struct record **record, int uaccountno, char uname[], char uaddress[])
{
    

    struct record *temp;
    struct record *newNode;
    temp = *record;
    newNode = (struct record*)malloc(sizeof(struct record));
    newNode->accountno = uaccountno;
    strcpy(newNode->name, uname);
    strcpy(newNode->address, uaddress);
    newNode->next = NULL;

    if (debug == 1)
    {
        printf("%s", "\nDebug mode activated\n");
        printf("%s", "Function name: add\n");
        printf("Account number to add: %d\n", uaccountno);
        printf("Name of user: %s\n", uname);
        printf("Address of user: %s\n", uaddress);
        printf("\n");
    }

    if (temp == NULL || temp->accountno < newNode->accountno)
    {
        newNode->next = temp;
        *record = newNode;
    }

    else
    {
        while (temp->next != NULL && temp->next->accountno > newNode->accountno)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

    }

}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all records in the database.
//                 
//                 
//  Parameters: record (*record) :
//            
//  Return values: None.
//              
//
****************************************************************/
void printAllRecords(struct record *record)
{
    struct record *current;
    current = record;

    if (debug == 1)
    {
        printf("%s", "\nDebug mode activated\n");
        printf("%s", "Function name: printAllRecords\n\n");
        printf("\n");
    }

    if (current == NULL)
    {
        printf("No records in database.\n");
    }

    while (current != NULL)
    {
        printf("\nAccount #: %d\n", current->accountno);
	    printf("Name: %s\n", current->name);
	    printf("Address: %s\n", current->address);
        current = current->next;
    }

}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds a record.
//                 
//                 
//  Parameters: record (*record) :
//              uaccountno (int) : User account number.
//            
//  Return values: None.
//              
//
****************************************************************/

int findRecord (struct record *record, int uaccountno)
{
    if (debug == 1)
    {
        printf("%s", "\nDebug mode activated\n");
        printf("%s", "Function name: findRecord\n");
        printf("Account number to find: %d\n\n", uaccountno);        
    }
    return 0;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION: Deletes a record
//    
//                 
//  Parameters: record (**record) :
//              uaccountno (int)  : User account number.
//            
//  Return values: None.
//              
//
****************************************************************/

int deleteRecord(struct record **record, int uaccountno)
{
    struct record *deleteMe;
    struct record *current;
    struct record *prev;
    int deleted;

    current = *record;
    deleted = -1;

    if (!current)
    {
        printf("\nEmpty.\n");
        return -1;
    }

    if (current->accountno == uaccountno)
    {
        while (current != NULL && current->accountno == uaccountno)
        {
            deleteMe = current;
            current = current->next;
            free(deleteMe);
            *record = current;
            deleted = 0;
        }
    }
    else
    {
        prev = current;
        current = current->next;
        while (current != NULL)
        {
            if (current->accountno == uaccountno)
            {
                deleteMe = current;
                prev->next = current->next;
                current = current->next;
                free(deleteMe);
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }

    return 0;



}