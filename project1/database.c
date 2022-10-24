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
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a record to the database.
//                 
//  Parameters:    record (**record) : The address of the pointer to the starting record.
//                 uaccountno (int)  : The account to add a record to.
//                 uname (char[])    : Name to be added to record.
//                 uaddress (char[]) : Address to be added to record.
//
//  Return values: None.
//              
****************************************************************/

void addRecord(struct record **record, int uaccountno, char uname[], char uaddress[])
{
    struct record *temp, *newNode;
    temp = *record;
    newNode = (struct record*)malloc(sizeof(struct record));
    newNode->accountno = uaccountno;
    strcpy(newNode->name, uname);
    strcpy(newNode->address, uaddress);
    newNode->next = NULL;
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
//  Parameters: record (*record) : A pointer to the first record.
//            
//  Return values: None.
//              
****************************************************************/
void printAllRecords(struct record *record)
{
    struct record *current;
    current = record;
    printf("\n========== Current Database ==========\n");
    if (current == NULL)
    {
        printf("\nNo records in database.\n");
    }
    while (current != NULL)
    {
        printf("\nAccount #: %d\n", current->accountno);
	    printf("Name: %s\n", current->name);
	    printf("Address: %s\n", current->address);
        current = current->next;
    }
    printf("\n================ End =================\n");
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds all records matching a provided account no.
//                 
//  Parameters: record (*record) : A pointer to first record.
//              uaccountno (int) : Account no. of record(s) to find.
//            
//  Return values: 0 if a record is found, -1 if not.
//              
****************************************************************/

int findRecord (struct record *record, int uaccountno)
{
    struct record *temp;
    int found;
    temp = record;
    found = -1;
    while (temp != NULL && temp->accountno != uaccountno)
    {
        temp = temp->next;
    }
    if (temp != NULL && temp->accountno == uaccountno)
    {
        found = 0;
    }
    while (temp != NULL && temp->accountno == uaccountno)
    {
        printf("\nAccount #: %d\n", temp->accountno);
	    printf("Name: %s\n", temp->name);
	    printf("Address: %s\n", temp->address);
        temp = temp->next;
    }
    return found;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION: Deletes all records matching a provided account no.
//                 
//  Parameters: record (**record) : Starting record.
//              uaccountno (int)  : Account no. of record(s) to delete.
//            
//  Return values: 0 if record was deleted, -1 if not.
//              
//
****************************************************************/

int deleteRecord(struct record **record, int uaccountno)
{
    struct record *deleteMe, *current, *prev;
    int deleted;
    current = *record;
    deleted = -1;
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
                deleted = 0;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    return deleted;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes bank data to a text file.
//                 
//  Parameters: record (*record) : Starting record.
//              filename (char [])  : Name of file to write to.
//                                                 
//  Return values: If the function could successfully open the file: return 0
//                 Otherwise, return -1     
//
****************************************************************/

int writefile(struct record *record, char filename[])
{
    FILE *f;
    struct record *current;
    current = record;
    f = fopen(filename, "w");
    if (f == NULL || current == NULL)
    {
        return -1;
    }
    else
    {
        while (current != NULL)
        {
        fprintf(f, "|%d|", current->accountno);
	    fprintf(f, "|%s|", current->name);
	    fprintf(f, "|%s|", current->address);
        current = current->next;
        }
        return 0;
    }


}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads bank data from a text file.             
//
//  Parameters: record (*record) : Starting record.
//              filename (char [])  : Name of file to read from. 
//
//  Return values: If the function could successfully open the file: return 0
//                 Otherwise, return -1
//              
****************************************************************/

int readfile(struct record *record, char filename[])
{
    char string[100];
    FILE *f;
    struct record *current;
    current = record;
    f = fopen(filename, "r");
    if (f == NULL || current == NULL)
    {
        return -1;
    }
    else
    {
        while (!feof(f))
        {
            fgets(string, 100, f);
            printf("\n%s", line);

        }
        return 0;
    }
    return 0;

}


