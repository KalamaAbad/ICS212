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
address[size - 1] = '\0';
}

int user_interface() 
{
    string input;
    int length;
    int numInput;
    int finished;
    char address[200];
	char name[30]; 
    char inputToChar[10];

    while (1)
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
			add

        }



    }
    cout << "You live at: " << endl << address << endl;
    return 0;
}