/*****************************************************************
//
//  NAME:        Kalama Abad
//
//  HOMEWORK:    Homework 9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 3, 2022
//
//  FILE:        homework9.java
//
//  DESCRIPTION: This file contains a java class homework9 for seeing if a number is a multiple
//				 of four.
//
****************************************************************/

import java.util.InputMismatchException;
import java.util.Scanner;

class homework9
{
    static
    {
        System.loadLibrary("homework9");
    }

/*****************************************************************
//
//  Function name: isMultiple4
//
//  DESCRIPTION:   Checks if a number is a multiple of four.
//
//  Parameters:    num (int) : The number to check.
//
//  Return values: 1 if num is a multiple of four, zero if not.
//
****************************************************************/

    private static native int isMultiple4(int num);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Calls methods for seeing if a number is a multiple of four.
//
//  Parameters:    args (String[]) : Not used.
//
//  Return values: None.
//
****************************************************************/

    public static void main(String[] args)
    {
        int num;
        num = user_interface();
        print_table(num);

    }

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   Prints a table that specifies whether a number
//                 is a multiple of 4.
//
//  Parameters:    None.
//
//  Return values: 0 after printing a table.
//
****************************************************************/

    public static void print_table(int num)
    {
        System.out.println(String.format("%8s", "  Number   Multiple of 4?"));
        for (int i = 0; i <= num; i++)
        {
            if (isMultiple4(i) == 1)
            {
                System.out.print(String.format("\n%8s", i));
                System.out.print(String.format("%6s", "Yes"));
            }
            else
            {
                System.out.print(String.format("\n%8s", i));
                System.out.print(String.format("%6s", "no"));
            }
        }
        System.out.println("\n");
    }

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   Gets an integer from a user to test.
//
//  Parameters:    None.
//
//  Return values: A positive nonzero integer entered by the user.
//
****************************************************************/

    public static int user_interface()
    {
        Scanner sc = new Scanner(System.in);
        int done;
        int num;
        num = 0;
        done = 0;
        System.out.println("This program will print all multiples of 4 from 0 to a number of your choice.");
        while (done != 1)
        {
            try
            {
            System.out.println("Please provide a positive nonzero integer.");
                num = sc.nextInt();
                if (num > 0)
                {
                    done = 1;
                }
                else
                {
                    System.out.println("Error: You provided a negative integer, or zero.");
                }
            }
            catch (InputMismatchException e)
            {
                System.out.println("Error: You entered a string.");
                sc.next();
            }

        }
        sc.close();
        return num;
    }
}
