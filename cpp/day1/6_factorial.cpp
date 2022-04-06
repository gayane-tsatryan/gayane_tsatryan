#include <iostream>
using namespace std;

int main()
{
    int number;
    int i = 1;
    long long factorial = 1;

    cout << "Enter  the number: ";
    cin >> number;

    if (number < 0)
        cout << "Error! \n";
    else {
        while (i <= number) {
            factorial *= i;
            i++;
        }

        cout << number << "! "
             << "= " << factorial << "\n";
    }

    return 0;
}
