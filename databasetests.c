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

#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Tests database functions.
//                 
//           
//
//  Return values: 0.
//              
//
****************************************************************/

int main(int argc, char const *argv[])
{
    int i;
    struct record *start = NULL;
    /*
    addRecord(&start, recordNum, name, address);
    findRecord(start, numInput);
    printAllRecords(start);
    deleteRecord(&start, numInput);
    */
    readfile(&start, "test.txt");
    printAllRecords(start);

    printf("\n================== Testing addRecord ==================\n" );
    printf("\nAdding 5 records.\n");
    for (i = 0; i < 5; i++)
    {
    addRecord(&start, i + 1, "Name", "Address");
    }
    printf("There should be 5 records.\n\n");
    printAllRecords(start);

    printf("Adding a record to the front (Reze).\n\n");
    addRecord(&start, 6, "Reze", "Address");
    printAllRecords(start);

    printf("Adding a record to the back (Denji).\n\n");
    addRecord(&start, 1, "Denji", "Address");
    printAllRecords(start);

    printf("Adding multiple records to a single account (Angel, Aki, and Kobeni.)\n\n");
    addRecord(&start, 5, "Angel", "Address");
    addRecord(&start, 5, "Aki", "Address");
    addRecord(&start, 5, "Kobeni", "Address");
    printAllRecords(start);

    printf("\n================== Testing findRecord ==================\n" );

    printf("Testing findRecord on all accounts.\n");
    printf("Should print 10 records.\n\n");
    
    for (i = 0; i < 6; i++)
    {
    findRecord(start, i + 1);
    }

    printf("Testing findRecord on a nonexistant account, no. 88. Should return -1.\n");
    i = findRecord(start, 88);
    printf("findRecord returned: %d\n", i);



    printf("Testing deletion of head record.\n");
    deleteRecord(&start, 10);
    printf("Testing deletion of tail record.\n");
    deleteRecord(&start, 21);
    printf("Testing deletion of multiple records (no 5).\n");
    deleteRecord(&start, 5);

    printf("Records 10, 21, and all records under 5 should be gone.\n");
    printf("Printing database:\n");
    printAllRecords(start);

    writefile(start, "test.txt");

    return 0;
}


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
//  Parameters: record (**record) :
//              uaccountno (int)  : User account number.
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
//  DESCRIPTION:   Reads bank data from a text file.             
//
//  Parameters: record (*record) : Starting record.
//              filename (char [])  : Name of file to read from. 
//
//  Return values: If the function could successfully open the file: return 0
//                 Otherwise, return -1
//              
****************************************************************/

int readfile(struct record **record, char filename[])
{
    int terminate;
    int i;
    int accnum;
    char ch;
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


