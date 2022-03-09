#include <iostream>
using namespace std;

void perfectNumber(int);
int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    perfectNumber(number);
    return 0;
}

void perfectNumber(int number)
{
    int sum = 0;

    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    if (sum == number && number != 0) {
        cout << number << " is perfect: \n";
    }
    else {
        cout << number << " is not perfect: \n";
    }
}

