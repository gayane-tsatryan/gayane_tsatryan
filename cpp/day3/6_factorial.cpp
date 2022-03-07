#include <iostream>
using namespace std;

int factorial(int x)
{
    if (x > 1)
        return x * factorial(x - 1);
    else
        return 1;
}

int main()
{
    int a;
    cout << "Enter number:  \n";
    cin >> a;
    cout << a << "! = " << factorial(a) << endl;
    return 0;
}

