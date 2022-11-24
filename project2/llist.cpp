#include "llist.h"
#include "iostream"

using namespace std;

llist::llist()
{
    struct record *start = NULL;
}

llist::llist(char in[])
{

}

llist::~llist()
{

}

void llist::addRecord(int accountno, char name[], char address[])
{
    cout << "Called addrecord." << endl;
}

int llist::findRecord(int accountno)
{
    cout << "Called findRecord." << endl;
    return 0;
}

void llist::printAllRecords()
{
    cout << "Called printAllRecords." << endl;    
}

int llist::deleteRecord(int accountno)
{
    cout << "Called deleteRecord." << endl;
    return 0;    
}



