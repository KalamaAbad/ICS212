#include "llist.h"
#include "iostream"

using namespace std;

struct record *start;

llist::llist()
{
    start = 0;
}

llist::llist(char in[])
{

}

llist::~llist()
{

}

void llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    cout << "Called addrecord." << endl;
    struct record *temp, *newNode;
    temp = start;
    newNode = (struct record*)malloc(sizeof(struct record));
    newNode->accountno = uaccountno;
    strcpy(newNode->name, uname);
    strcpy(newNode->address, uaddress);
    newNode->next = NULL;
    if (temp == NULL || temp->accountno < newNode->accountno)
    {
        newNode->next = temp;
        start = newNode;
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

int llist::findRecord(int accountno)
{
    cout << "Called findRecord." << endl;
    return 0;
}

void llist::printAllRecords()
{
    cout << "Called printAllRecords." << endl;
    struct record *current;
    current = start;
    cout << start << current;
    printf("\n========== Current Database ==========\n");
    if (start == 0)
    {
        printf("\nNo records in database.\n");
    }
    while (current != 0)
    {
        printf("\nAccount #: %d\n", current->accountno);
	    printf("Name: %s\n", current->name);
	    printf("Address: %s\n", current->address);
        current = current->next;
    }
    printf("\n================ End =================\n");    
}

int llist::deleteRecord(int accountno)
{
    cout << "Called deleteRecord." << endl;
    return 0;    
}





