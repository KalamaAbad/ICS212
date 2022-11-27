#include "llist.h"
#include "fstream"
#include "iostream"
#include "cstring"
#include <string.h>
#include <sstream>

using namespace std;

struct record *start;
char filename[20];
int debug;

#ifdef DEBUG
debug = 1;
#endif

ostream& operator<<(ostream& output, const llist &obj) 
{
    output << "Called printAllRecords." << endl;
    struct record *current;
    current = obj.start;
    output << endl << "================ Start =================" << endl << endl; 
    if (current == nullptr)
    {
        output << endl << "\nNo records in database." << endl;
    }
    while (current != nullptr)
    {
        output << "Account #: " << current->accountno << endl;
	    output << "Name: " << current->name << endl;
	    output << "Address: " << current->address << endl;
        output << endl;
        current = current->next;
    }
    output << "================ End =================" << endl << endl;
    return output;
}

llist::operator=(const llist &obj)
{

}

llist::llist()
{
    start = nullptr;
}

llist::llist(char in[])
{
    strcpy(filename, in);
    start = nullptr;
    readfile();
}

llist::llist(const llist &obj) throw()
{
    start = obj.start;
    strcpy(filename, obj.filename);
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
    struct record *current;
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

int llist::writefile()
{
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




