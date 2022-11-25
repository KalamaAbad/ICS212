#include "llist.h"
#include "fstream"
#include "iostream"

using namespace std;

struct record *start;
char filename[20];

llist::llist()
{
    start = nullptr;
}

llist::llist(char in[])
{
    readfile();
    llist();
}

llist::~llist()
{
    writefile();
    cleanup();
}

void llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    struct record *temp, *newNode;
    temp = start;
    newNode = new struct record;
    newNode->accountno = uaccountno;
    strcpy(newNode->name, uname);
    strcpy(newNode->address, uaddress);
    newNode->next = NULL;
    if (temp == nullptr || temp->accountno < newNode->accountno)
    {
        newNode->next = temp;
        start = newNode;
    }
    else
    {
        while (temp->next != nullptr && temp->next->accountno > newNode->accountno)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int llist::findRecord(int uaccountno)
{
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

void llist::printAllRecords()
{
    cout << "Called printAllRecords." << endl;
    struct record *current;
    current = start;
    cout << endl << "================ Start =================" << endl << endl; 
    if (current == nullptr)
    {
        cout << endl << "\nNo records in database." << endl;
    }
    while (current != nullptr)
    {
        cout << "Account #: " << current->accountno << endl;
	    cout << "Name: " << current->name << endl;
	    cout << "Address: " << current->address << endl;
        cout << endl;
        current = current->next;
    }
    cout << endl << "================ End =================" << endl << endl; 
}

int llist::deleteRecord(int uaccountno)
{
    cout << "Called deleteRecord." << endl;
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
            free(deleteMe);
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

int llist::readfile()
{
    return 0;
}

int llist::writefile()
{
    FILE *f;
    struct record *current;
    current = start;
    ofstream myfile (filename);
    if (!myfile.is_open())
    {
        return -1;
    }
    else
    {
        while (current != NULL)
        {
        myfile << "|" << current->accountno;
	    myfile << "|" << current->name;
	    myfile << "|" << current->address;
        current = current->next;
        }
        myfile.close();
        return 0;
    }


}

void llist::cleanup()
{
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


