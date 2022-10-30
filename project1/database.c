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
//  Parameters:    record (**record) : The address of the starting pointer.
//                 uaccountno (int)  : User account number.
//                 uname (char[])    : Name to be added to record.
//                 uaddress (char[]) : Address to be added to record.
//
//  Return values: None.
//              
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
//  Parameters: record (*record) : The first record in the database.
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
//  DESCRIPTION:   Finds a record.
//                 
//  Parameters: record (*record) : The first record in the database.
//              uaccountno (int) : User account number to add a record to.
//            
//  Return values: 0 if an account was found, -1 if not.        
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
//  DESCRIPTION: Deletes a record
//    
//                 
//  Parameters: record (**record) : The address of the starting record pointer.
//              uaccountno (int)  : User account number to delete records from.
//            
//  Return values: None.
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
//  Parameters: record (*record) : The starting record.
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
        fprintf(f, "%d|", current->accountno);
	    fprintf(f, "%s|", current->name);
	    fprintf(f, "%s|", current->address);
        current = current->next;
        }
        fclose(f);
        return 0;
    }


}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads bank accounts from a text file into database.          
//
//  Parameters: record (*record) : The starting record.
//              filename (char [])  : Name of file to read from. 
//
//  Return values: If the function could successfully open the file: return 0
//                 Otherwise, return -1
//              
****************************************************************/

int readfile(struct record **record, char filename[])
{
    char ch;
    int terminate;
    int i;
    int accnum;
    char num[10];
    char name[30];
    char address[200];
    FILE *f;

    accnum = 0;
    
    printf("hello");

    f = fopen("test.txt", "r");
    if (f == NULL)
    {
        printf("here");
        return -1;
    }
    else
    {
        while (!feof(f))
        {
            i = 0;
            terminate = 0;
            while (i < 10 && terminate == 0) 
            {
                ch = fgetc(f);
                if (ch == '|')
                {
                    terminate = 1;
                }
                else
                {
                    num[i] = ch;
                }
                i++;
            }
            accnum = atoi(num);
            i = 0;
            terminate = 0;
            while (i < 30 && terminate == 0)
            {
                ch = fgetc(f);
                if (ch == '|')
                {
                    terminate = 1;
                }
                else
                {
                    name[i] = ch;
                }
                i++;               
            }
            i = 0;
            terminate = 0;
            while (i < 200 && terminate == 0)
            {
                ch = fgetc(f);
                if (ch == '|')
                {
                    terminate = 1;
                }
                else
                {
                    address[i] = ch;
                }
                i++;
            }
            if (!feof(f))
            {
            addRecord(record, accnum, name, address);
            memset(name, 0, sizeof(name));
            memset(address, 0, sizeof(address));
            memset(num, 0, sizeof(num));
            }
            else
            {
            memset(name, 0, sizeof(name));
            memset(address, 0, sizeof(address));
            memset(num, 0, sizeof(num));
            }
        }
        fclose(f);
        return 0;
    }
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Deletes all accounts.        
//
//  Parameters: record (**record) : The address of the starting pointer.
//
//  Return values: None.
//              
****************************************************************/

void cleanup(struct record **record)
{
    struct record *current, *previous;
    current = *record;
    while (current != NULL)
    {
        previous = current;
        current = current->next;
        free(previous);
    }
    *record = current;
}