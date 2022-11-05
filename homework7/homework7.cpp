#include <iostream>
#include <iomanip>

using namespace std;

void is_multiple4(int num, int* address);
int user_interface(); 


void is_multiple4(int num, int *ptr)
{
    // check if is multiple of 4
    // if it is, change int at address to 0

}

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
        else if (number < 0)
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



int main() 
{
    int num;
    num = user_interface();
    cout << num << std::endl;

    return 0;
}