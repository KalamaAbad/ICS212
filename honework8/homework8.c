/*****************************************************************
//
//  NAME:        Kalama Abad
//
//  HOMEWORK:    8 
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 5, 2022
//
//  FILE:        homework8.c
//
//  DESCRIPTION: This file contains C functions for reading binary data
//   
//
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int readfile(const char [], unsigned char []);
int writefile(const char [], const unsigned char []);
void printheader(const unsigned char []);
void makeheader(const unsigned char [], unsigned char []);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Generates response headers for binary files.
//                 
//                 
//  Parameters:    argc (int)  : Not used.
//                 argv (char*) : Not used.
//
//  Return values: 0 when finished.
//
****************************************************************/

int main(int argc, char const *argv[])
{
    const unsigned char *arr2;
    unsigned char arr[20];
    readfile("request1.bin", arr);
    arr2 = arr;
    printheader(arr2);
    printf("done");
    return 0;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   
//                 
//  Parameters:    filename (const char[])  : The filename.
//
//  Return values: 0 if read, -1 if not.
//
****************************************************************/

void printheader(const unsigned char input[])
{
    printf("Souce port: %d\n", ((input[1]) << 8 | (input[0])));
    printf("Destination port: %d\n", ((input[3]) << 8 | (input[2])));
    /*
    26 = 00100110
    DF = 11011111
    result : 0010011011011111
    */


}
/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads a binary file and stores in an unsigned char[]
//                 
//  Parameters:    filename (const char[])  : The filename.
//                 output (unsigned char[]) : Binary data will be stored here.
//
//  Return values: 0 if read, -1 if not.
//
****************************************************************/

int readfile(const char filename[], unsigned char output[])
{
    FILE *f;
    f = fopen(filename, "rb");
    fread(output, sizeof(unsigned char), 20, f);
    return 0; 

}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Writes a TCP header file.
//                 
//  Parameters:    filename (const char[])  : The filename.
//                 output (const unsigned char[]) : Binary data to write to file.
//
//  Return values: 0 if read, -1 if not.
//
****************************************************************/

int writefile(const char filename[], const unsigned char input[])
{
    FILE *f;
    f = fopen(filename, "wb");
    fwrite(input, sizeof(unsigned char), 20, f);
    return 0; 

}

