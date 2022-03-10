#include <iostream>
using namespace std;

bool isPerfect (int);
int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << isPerfect(number)<< endl;
    return 0;
}

bool isPerfect (int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    if (sum == number && number != 0) {
        return true;
    }
    else {
        return false;
    }
}


