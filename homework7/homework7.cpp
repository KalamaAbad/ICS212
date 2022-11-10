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

using namespace std;

void is_multiple4(int num, int* address);
int user_interface(); 

/*****************************************************************
//
//  Function name: is_multiple4
//
//  DESCRIPTION:   Checks if a number is a multiple of 4.
//                 
//                 
//  Parameters:    num (int)  : The number to check.
//                 ptr (int*) : The address of the number to update
//                              if the number is a multiple of 4.
//
//  Return values: None.
//
****************************************************************/

void is_multiple4(int num, int *ptr)
{
    if (num % 4 == 0)
    {
        *ptr = 0;
    }
    else
    {
        *ptr = -1;
    }

}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   Gets an integer from a user to test.                
//                 
//  Parameters:    None.
//
//  Return values: A positive integer entered by the user.
//
****************************************************************/

int user_interface()
{
    int number;
    int done;
    done = -1;
    while (done == -1)
    {
        cout << "Please enter an integer greater than zero:" << endl;
        cin >> number;
        if (!cin)
        {
            cout << "Invalid input: You entered a string." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (number <= 0)
        {
            cout << "Invalid input: You entered zero or a negative number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            done = 0;
        }

    }

    return number;
}

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

int main() 
{
    int i;
    int isMultiple;
    int num;
    i = 0;
    num = user_interface();
    cout << setw(8) << "  Number   Multiple of 4?" << endl;

    while (i <= num)
    {
        is_multiple4(i, &isMultiple);
        if (isMultiple == 0)
        {
            cout << setw(8) << i;
            cout << setw(6) << "Yes" << endl;
        }
        else
        {
            cout << setw(8) << i;
            cout << setw(6) << "No" << endl;
        }
        i++;
    }

    return 0;
}