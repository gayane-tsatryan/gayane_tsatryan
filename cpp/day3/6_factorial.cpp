#include <iostream>
using namespace std;

int factorial(int number)
{
    if (number > 1)
        return number * factorial(number - 1);
    else
        return 1;
}

int main()
{
    int number;
    cout << "Enter number:  \n";
    cin >> number;
    cout << number << "! = " << factorial(number) << endl;
    return 0;
}

