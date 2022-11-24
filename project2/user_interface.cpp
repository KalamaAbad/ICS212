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
//  DATE:        September 12, 2022
//
//  FILE:        user_interface.cpp
//
//  DESCRIPTION: This file contains C functions for a user interface.
//   
//
****************************************************************/
#include <iostream>
#include <istream>
#include <string>
#include <cstring>
#include <limits>
#include "llist.cpp"

using namespace std;

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION: Writes user input to an address-storing char[]
//                 
//  Parameters: name (char[]) : the array to store into 
//              size (int)    : array size.      
//                             
//  Return values: None.
//              
//
****************************************************************/

void getaddress(char address[], int size)
{
cout << "Please enter an address, followed by ;" << endl;
string input;
getline(cin, input, ';');
strncpy(address, input.c_str(), size);
address[size - 1] = '\0';
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION: Allows user to input menu options to interact with
//               the database.
//                 
//  Parameters:    argc (int) : The number of elements in argv.
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values: 0 if quit.
//              
//
****************************************************************/

int main(int argc, char *argv[])
{
cout << "Hi";
string input;
int quit;
int length;
int numInput;
int finished;
char address[200];
char name[30]; 
char inputToChar[10];
quit = 0;
llist list;

    while (quit != 1)
    {
        cout << "Please enter a menu option: " << endl;
        cout << "add: Add a new record into the database" << endl;
        cout << "printall: Prints all records int he database" << endl;
        cout << "find: Finds record(s) with a specified account #" << endl;
        cout << "delete: Delete record(s) from the database using an account # as a key" << endl;
        cout << "quit; Quit the program" << endl;
        getline(cin, input);
        strncpy(inputToChar, input.c_str(), 10);
        length = strlen(inputToChar) - 1;
        
        if (strncmp(inputToChar, "add", length) == 0)
        {
            cout << "What is the account number?" << endl;
            finished = 0;
            while (finished == 0)
            {
                cout << "Please enter an integer greater than zero:" << endl;
        		cin >> numInput;
        		if (!cin)
        		{
            	cout << "Invalid input: You entered a string." << endl;
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}
        		else if (numInput <= 0)
        		{
            	cout << "Invalid input: You entered zero or a negative number." << endl;
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}
        		else
        		{
            	finished = -1;
				cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}
            }
			finished = 0;
			while (finished == 0)
			{
				cout << "What is the name?" << endl;
				getline(cin, input);
		        strncpy(name, input.c_str(), 30);
				name[29] = '\0';
            	finished = -1;
			}
			getaddress(address, 200);
			list.addRecord(numInput, name, address);
        }
		else if (strncmp(inputToChar, "delete", length) == 0)
		{
			cout << "Enter an account number to delete from:" << endl;
			finished = 0;
            while (finished == 0)
            {
                cout << "Please enter an integer greater than zero:" << endl;
        		cin >> numInput;
        		if (!cin)
        		{
            	cout << "Invalid input: You entered a string." << endl;
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}
        		else if (numInput <= 0)
        		{
            	cout << "Invalid input: You entered zero or a negative number." << endl;
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}
        		else
        		{
            	finished = -1;
        		}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
			list.deleteRecord(numInput);
		}
		else if (strncmp(inputToChar, "printall", length) == 0)
		{
			list.printAllRecords();
		}
		else if (strncmp(inputToChar, "find", length) == 0)
		{
			cout << "Enter an account number to find:" << endl;
			finished = 0;
            while (finished == 0)
            {
                cout << "Please enter an integer greater than zero:" << endl;
        		cin >> numInput;
        		if (!cin)
        		{
            	cout << "Invalid input: You entered a string." << endl;
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}
        		else if (numInput <= 0)
        		{
            	cout << "Invalid input: You entered zero or a negative number." << endl;
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}
        		else
        		{
            	finished = -1;
        		}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
			list.findRecord(numInput);
		}
		else if (strncmp(inputToChar, "quit", length) == 0)
		{
			quit = 1;
		}
    }
}