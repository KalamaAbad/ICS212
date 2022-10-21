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
//  FILE:        user_interface.c
//
//  DESCRIPTION: This file contains C functions for a user interface.
//   
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include "database.h"

int debug = 0;

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
int i;
int eof;
int terminate;
printf("%s", "Please enter an address, followed by ;\n");
i = 0;
eof = size - 1;
terminate = 0;
while (i < eof && terminate == 0)
{
    if ((address[i] = getchar()) == ';')
    {
        terminate = 1;
    }
    i++;
}
address[i] = '\0';
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
struct record *start = NULL;
char input[30];
char name[30];
char address[200];
char eatMe;
int length;
int numInput;
int recordNum;
int finished;
int quit;

quit = 0;

if (argc == 2)
{
    if (strcmp(argv[1], "debug") == 0)
    {
    debug = 1;
    printf("\nThis program is in debug mode.\n");
    }
    else
    {
        printf("\nInvalid arugment, exitting program.\n");
        quit = 1;
    }
}
else if (argc > 2)
{
    printf("Invalid arugment, exitting program.\n");
    quit = 1;
}


while (quit != 1) 
{
    printf("%s", "Please pick an option from the menu and enter into the terminal.\n");
    printf("%s", "add: Add a new record in the database\n");
    printf("%s", "printall: Prints all records in the database\n");
    printf("%s", "find: Finds record(s) with a specified account #\n");
    printf("%s", "delete: Delete existing record(s) from the database using an account # as a key\n");
    printf("%s", "quit: Quit the program\n");

    fgets(input, 7, stdin);
    length = strlen(input) - 1;

    if (strncmp(input, "add", length) == 0)
    {
        printf("What is the account number?\n");
        finished = 0;

        while (finished == 0)
        {
            if (scanf("%d", &numInput) == 1) 
            {
                if (numInput > 0)
                {
                recordNum = numInput;
                finished = 1;
                }
                else
                {
                    printf("%s", "Error: Invalid input, please enter a positive integer.\n");
                    while ((eatMe = getchar()) != EOF && eatMe != '\n');
                }
            }
            else 
            {  
                printf("%s", "Error: Invalid input. You entered a string or character. Please enter an integer.\n");
                while ((eatMe = getchar()) != EOF && eatMe != '\n');
            }
        }

        while ((eatMe = getchar()) != EOF && eatMe != '\n');
        finished = 0;

        while (finished == 0)
        {
            printf("%s", "What is the name?\n");
            scanf("%s", name);  
            while ((eatMe = getchar()) != EOF && eatMe != '\n');
            finished = 1;
        }
        getaddress(address, 200);
        add(&start, recordNum, name, address);
    }

    else if (strncmp(input, "printall", length) == 0)
    {
        printAllRecords(start);
    }

    else if (strncmp(input, "find", length) == 0)
    {
        finished = 0;
        while (finished == 0)
        {
            printf("%s", "Enter an account number to find\n");  
            if (scanf("%d", &numInput) == 1) 
            {
                if (numInput > 0)
                {
                findRecord(start, numInput);
                finished = 1;
                }
                else
                {
                    printf("%s", "Error: Invalid input, please enter a positive integer.\n");
                    while ((eatMe = getchar()) != EOF && eatMe != '\n');
                }
            }
            else 
            {  
                printf("%s", "Error: Invalid input. You entered a string or character. Please enter an integer.\n");
                while ((eatMe = getchar()) != EOF && eatMe != '\n');
            }
        }

    }

    else if (strncmp(input, "delete", length) == 0)
    {
        finished = 0;
        while (finished == 0)
        {
            printf("%s", "Enter an account number to delete\n");  
            if (scanf("%d", &numInput) == 1) 
            {
                if (numInput > 0)
                {
                deleteRecord(&start, numInput);
                finished = 1;
                }
                else
                {
                    printf("%s", "Error: Invalid input, please enter a positive integer.\n");
                    while ((eatMe = getchar()) != EOF && eatMe != '\n');
                }
            }
            else 
            {  
                printf("%s", "Error: Invalid input. You entered a string or character. Please enter an integer.\n");
                while ((eatMe = getchar()) != EOF && eatMe != '\n');
            }
        }

        
    }
    else if (strncmp(input, "quit", length) == 0)
    {
        quit = 1;
    }
}
return 0;
}
