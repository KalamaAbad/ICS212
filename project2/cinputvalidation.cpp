/*****************************************************************
//
//  NAME:        Kalama Abad
//
//  HOMEWORK:    7
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 5, 2022
//
//  FILE:        homework7.cpp
//
//  DESCRIPTION: This file contains C++ functions for seeing if
//               a number is a multiple of 4.
//   
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstring>


using namespace std;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Prints a table that specifies whether a number
//                 is a multiple of 4.                
//
//  Parameters:    None.
//
//  Return values: 0 after printing a table.
//
****************************************************************/

void getaddress(char address[], int size)
{
cout << "Please enter an address, followed by ;" << endl;
string input;
getline(cin, input, ';');
strncpy(address, input.c_str(), size);
}

int main() 
{
    string input;
    int length;
    char address[200];
    while (1)
    {
        cout << "Please enter a menu option: " << endl;
        cout << "add: Add a new record into the database" << endl;
        cout << "printall: Prints all records int he database" << endl;
        cout << "find: Finds record(s) with a specified account #" << endl;
        cout << "delete: Delete record(s) from the database using an account # as a key" << endl;
        cout << "quit; Quit the program" << endl;
        getline(cin, input);
        length = sizeof(input) - 1;
        

    }
    getaddress(address, 200);
    cout << "You live at: " << endl << address << endl;
    return 0;
}