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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This file contains functions for reading and writing to the database.
//
****************************************************************/

#include "llist.h"
#include "fstream"
#include "cstring"
#include <string.h>
#include <ostream>
#include <iostream>
#include <istream>
#include <string>
#include <limits>

using namespace std;

struct record *start;
char filename[20];

/*****************************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   Allows for using '<<' on llist objects.
//
//  Parameters:    obj (const llist) : The original llist to copy.
//                 os (ostream) : The stream to write to.
//
//  Return values: The copied llist.
//
****************************************************************/

std::ostream& operator<<(std::ostream& os, const llist& list)
{
    #ifdef DEBUG
        cout << "Using overriden << operator to print llist." << endl;
    #endif
    struct record *current = list.start;
    os << endl << "================ Start =================" << endl << endl;
    if (current == 0)
    {
        os << endl << "\nNo records in database." << endl;
    }
    while (current != 0)
    {
        os << "Account #: " << current->accountno << endl;
        os << "Name: " << current->name << endl;
        os << "Address: " << current->address << endl;
        os << endl;
        current = current->next;
    }
    os << endl << "================ End =================" << endl << endl;
    return os;
}

/*****************************************************************
//
//  Function name: operator=
//
//  DESCRIPTION:   Allows for using '=' on llist objects.
//
//  Parameters:    obj (const llist) : The original llist to copy.
//
//  Return values: The copied llist.
//
****************************************************************/

llist&llist::operator=(const llist& obj)
{
    #ifdef DEBUG
        cout << "Using overriden = operator to assign llist." << endl;
    #endif
    strcpy(filename, obj.filename);
    start = obj.start;
    return *this;
}

/*****************************************************************
//
//  Function name: llist()
//
//  DESCRIPTION:   Basic constructor method.
//
//  Parameters:    None.
//
//  Return values: Initializes a new llist.
//
****************************************************************/

llist::llist()
{
    #ifdef DEBUG
        cout << "Called llist (Constructor method)" << endl;
    #endif
    start = 0;
}

/*****************************************************************
//
//  Function name: llist()
//
//  DESCRIPTION:   Constructor method.
//
//  Parameters:    in (char []) : The filename to read/write to.
//
//  Return values: None.
//
****************************************************************/

llist::llist(char in[])
{
    #ifdef DEBUG
        cout << "Called llist (Constructor method)" << endl;
        cout << "Using filename: " << in << endl;
    #endif
    strcpy(filename, in);
    start = 0;
    readfile();
}

/*****************************************************************
//
//  Function name: llist()
//
//  DESCRIPTION:   Copy constructor method.
//
//  Parameters:    obj (const llist) : The original database.
//
//  Return values: None.
//
****************************************************************/

llist::llist(const llist &obj) throw()
{
    #ifdef DEBUG
        cout << "Called llist (Copy constructor method)" << endl;
    #endif
    start = obj.start;
    strcpy(filename, obj.filename);
}

/*****************************************************************
//
//  Function name: ~llist()
//
//  DESCRIPTION:   Destructor method, deallocates space
//                 and writes database to a file.
//
//  Parameters:    None.
//
//  Return values: None.
//
****************************************************************/

llist::~llist()
{
    #ifdef DEBUG
        cout << "Called ~llist (Destructor method)" << endl;
    #endif
    writefile();
    cleanup();
}

/*****************************************************************
//
//  Function name: add
//
//  DESCRIPTION:   Adds a record to the database.
//
//  Parameters:    uaccountno (int)  : User account number.
//                 uname (char[])    : Name to be added to record.
//                 uaddress (char[]) : Address to be added to record.
//
//  Return values: None.
//
****************************************************************/

void llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    #ifdef DEBUG
        cout << "Called addRecord" << endl;
        cout << "Account #: " << uaccountno << endl;
        cout << "Name: " << uname << endl;
        cout << "Address: " << uaddress << endl;
    #endif
    struct record *temp, *newNode;
    temp = start;
    newNode = new struct record;
    newNode->accountno = uaccountno;
    strcpy(newNode->name, uname);
    strcpy(newNode->address, uaddress);
    newNode->next = NULL;
    if (temp == 0 || temp->accountno < newNode->accountno)
    {
        newNode->next = temp;
        start = newNode;
    }
    else
    {
        while (temp->next != 0 && temp->next->accountno > newNode->accountno)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds a record.
//
//  Parameters: uaccountno (int) : User account number to add a record to.
//
//  Return values: 0 if an account was found, -1 if not.
//
****************************************************************/

int llist::findRecord(int uaccountno)
{
    #ifdef DEBUG
        cout << "Called findRecord" << endl;
        cout << "Account #: " << uaccountno << endl;
    #endif

    struct record *temp;
    int found;
    temp = start;
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
        cout << "Account #: " << temp->accountno << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Address: " << temp->address << endl;
        cout << endl;
        temp = temp->next;
    }
    return found;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all records in the database.
//
//  Parameters: None.
//
//  Return values: None.
//
****************************************************************/

void llist::printAllRecords()
{
    #ifdef DEBUG
    cout << "Called printAllRecords." << endl;
    #endif
    struct record *current;
    current = start;
    cout << endl << "================ Start =================" << endl << endl;
    if (current == 0)
    {
        cout << endl << "\nNo records in database." << endl;
    }
    while (current != 0)
    {
        cout << "Account #: " << current->accountno << endl;
        cout << "Name: " << current->name << endl;
        cout << "Address: " << current->address << endl;
        cout << endl;
        current = current->next;
    }
    cout << endl << "================ End =================" << endl << endl;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION: Deletes a record
//
//  Parameters: uaccountno (int)  : User account number to delete records from.
//
//  Return values: 0 if an account was deleted, -1 if not.
//
****************************************************************/

int llist::deleteRecord(int uaccountno)
{
    #ifdef DEBUG
        cout << "Called deleteRecord" << endl;
        cout << "Account # to delete: " << uaccountno << endl;
    #endif
    struct record *deleteMe, *current, *prev;
    int deleted;
    current = start;
    deleted = -1;
    if (current->accountno == uaccountno)
    {
        while (current != NULL && current->accountno == uaccountno)
        {
            deleteMe = current;
            current = current->next;
            delete(deleteMe);
            start = current;
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
                delete deleteMe;
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
//  Function name: readfile
//
//  DESCRIPTION:   Reads bank accounts from a text file into database.
//
//  Parameters: None.
//
//  Return values: If the function could successfully open the file: return 0
//                 Otherwise, return -1
//
****************************************************************/

int llist::readfile()
{
    #ifdef DEBUG
        cout << "Called readfile." << endl;
    #endif
    char accountnum[10];
    char name[30];
    char address[50];
    int num;
    int terminate;
    terminate = 1;
    ifstream myfile (filename);
    if (!myfile.is_open())
    {
        return -1;
    }
    else
    {
        while (terminate != 0 && !myfile.eof())
        {
            myfile.getline(accountnum, 10, '|');
            myfile.getline(name, 30, '|');
            myfile.getline(address, 50, '|');
            if (myfile.eof())
            {
                terminate = 0;
            }
            else
            {
            num = atoi(accountnum);
            addRecord(num, name, address);
            }
            memset((accountnum), 0, sizeof(accountnum));
            memset((name), 0, sizeof(name));
            memset((address), 0, sizeof(address));

        }

        myfile.close();
        return 0;
    }

}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes bank data to a text file.
//
//  Parameters: None.
//
//  Return values: If the function could successfully open the file: return 0
//                 Otherwise, return -1
//
****************************************************************/

int llist::writefile()
{
    #ifdef DEBUG
        cout << "Called writefile." << endl;
    #endif
    struct record *current;
    current = start;
    ofstream myfile ("filename.txt");
    if (!myfile.is_open())
    {
        return -1;
    }
    else
    {
        while (current != NULL)
        {
        myfile << current->accountno << "|";
        myfile << current->name << "|";
        myfile << current->address << "|";
        current = current->next;
        }
        myfile.close();
        return 0;
    }


}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Deletes all accounts.
//
//  Parameters: None.
//
//  Return values: None.
//
****************************************************************/

void llist::cleanup()
{
    #ifdef DEBUG
        cout << "Called cleanup." << endl;
    #endif
    struct record *current, *previous;
    current = start;
    while (current != NULL)
    {
        previous = current;
        current = current->next;
        delete previous;
    }
    start = current;
}