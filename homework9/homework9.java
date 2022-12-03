import java.util.InputMismatchException;
import java.util.Scanner;

class homework9
{
    private static native boolean 
    public static void main(String[] args) 
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
        print_table(num);
    }

    public static void print_table(int num)
    {
        for (int i = 0; i <= num; i++)
        {
            System.out.println(i);
        }
    }
}