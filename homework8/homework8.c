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
//  Parameters:    argc (int)  : Not used.
//                 argv (char*) : Not used.
//
//  Return values: 0 when finished.
//
****************************************************************/

int main(int argc, char const *argv[])
{
    /*
    pull goddamn it
    */
    unsigned char headerFromFile[20];
    const unsigned char *header;
    unsigned char responseHeader[20];

    readfile("request3.bin", headerFromFile);
    header = headerFromFile;
    printf("\n============ Printing TCP header 3 ============\n");
    printheader(header);
    makeheader(header, responseHeader);
    printf("\n============ Printing TCP response header 3 ============\n");
    printheader(responseHeader);
    writefile("response3.bin", responseHeader);

    readfile("request2.bin", headerFromFile);
    header = headerFromFile;
    printf("\n\n============ Printing TCP header 2 ============\n");
    printheader(header);
    makeheader(header, responseHeader);
    printf("\n============ Printing TCP response header 2 ============\n");
    printheader(responseHeader);
    writefile("response2.bin", responseHeader);

    readfile("request1.bin", headerFromFile);
    header = headerFromFile;
    printf("\n\n============ Printing TCP header 1 ============\n");
    printheader(header);
    makeheader(header, responseHeader);
    printf("\n============ Printing TCP response header 1 ============\n");
    printheader(responseHeader);
    writefile("response1.bin", responseHeader);
    return 0;
}

/*****************************************************************
//
//  Function name: printheader
//
//  DESCRIPTION:   Prints a TCP header.
//
//  Parameters:    input (const unsigned char[])  : The header to print.
//
//  Return values: 0 if read, -1 if not.
//
****************************************************************/

void printheader(const unsigned char input[])
{
    int flag;
    int i;
    i = 0;
    printf("Souce port: %d\n", ((input[1]) << 8 | (input[0])));
    printf("Destination port: %d\n", ((input[3]) << 8 | (input[2])));
    printf(("Sequence number: %u\n"), ((input[7]) << 24 | (input[6]) << 16 | (input[5]) << 8 | (input[4])));
    printf(("Acknowledgement number: %u\n"), ((input[11]) << 24 | (input[10]) << 16 | (input[9]) << 8 | (input[8])));
    flag = input[13];
    printf("Flags: ");
    while (i < 6)
    {
        if ((flag & 1))
        {
            (i == 0) ? printf("FIN ") : 0;
            (i == 1) ? printf("SYN ") : 0;
            (i == 2) ? printf("RST ") : 0;
            (i == 3) ? printf("PSH ") : 0;
            (i == 4) ? printf("ACK ") : 0;
            (i == 5) ? printf("URG ") : 0;
        }
        flag = flag >> 1;
        i++;
    }
}
/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads a binary file.
//
//  Parameters:    filename (const char[])  : The file to read from.
//                 output (unsigned char[]) : Binary data will be stored here in hex format.
//
//  Return values: 0 if read, -1 if not.
//
****************************************************************/

int readfile(const char filename[], unsigned char output[])
{
    FILE *f;
    f = fopen(filename, "rb");
    if (ferror(f) || f == NULL)
    {
    return -1;
    }
    fread(output, sizeof(unsigned char), 20, f);
    fclose(f);
    return 0;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes a binary TCP header file.
//
//  Parameters:    filename (const char[])  : The file to write to.
//                 output (const unsigned char[]) : The header to write to the file.
//
//  Return values: 0 if read, -1 if not.
//
****************************************************************/

int writefile(const char filename[], const unsigned char input[])
{
    FILE *f;
    f = fopen(filename, "wb");
    if (ferror(f) || f == NULL)
    {
        return -1;
    }
    fwrite(input, sizeof(unsigned char), 20, f);
    fclose(f);
    return 0;
}

/*****************************************************************
//
//  Function name: makeheader
//
//  DESCRIPTION:   Generates a response header.
//
//  Parameters:    input (const unsigned char[])  : The header to generate a response to.
//                 output (const unsigned char[]) : This is where we will store the response.
//
//  Return values: None.
//
****************************************************************/

void makeheader(const unsigned char input[], unsigned char output[])
{
    unsigned int plusOne;
    int i;

    output[0] = input[2];
    output[1] = input[3];

    if (((input[1] << 8 | input[0]) >> 15) != 0)
    {
        output[2] = (input[0] ^ (1 << (6)));
        output[3] = (input[1] ^ (1 << (2)));
    }
    else
    {
        output[2] = input[0];
        output[3] = input[1];
    }

    output[8] = input[4];
    output[9] = input[5];
    output[10] = input[6];
    output[11] = input[7];

    plusOne = (((input[7]) << 24 | (input[6]) << 16 | (input[5]) << 8 | (input[4])) + 1);

    output[7] = (plusOne >> 24) & 0xFF;
    output[6] = (plusOne >> 16) & 0xFF;
    output[5] = (plusOne >> 8) & 0xFF;
    output[4] = plusOne & 0xFF;

    if ((input[13] & 2) == 2)
    {
        output[13] = 16 ^ input[13];
    }

    for (i = 14; i < 20; i++)
    {
        output[i] = input[i];
    }
}
