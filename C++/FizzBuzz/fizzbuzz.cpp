#include <iostream>

using namespace std;

int main () 
{
    int maxNum = 100;

    cout << "Welcome to FizzBuzz! " << endl;

    for (int i = 0; i <= maxNum; i++)
    {
        if (i % 15 == 0)
        {
            cout << "Fizz Buzz" << endl;
        }
        else if (i % 3 == 0)
        {
            cout << "Fizz" << endl;
        }
        else if (i % 5 == 0)
        {
            cout << "Buzz " << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

    return 0;
}
