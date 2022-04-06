#include <iostream>
#include <cstdlib>
using namespace std;

void gameFunction(int number1)
{
    int number2;
    cout << "Enter number: \n";
    do {
        int number2;
        cin >> number2;
        if (number2 < number1) {
            cout << "Enter the larg number: \n";
        }
        else if (number2 > number1) {
            cout << "Enter the small number: \n";
        }
        else {
            cout << "You are winner!!! \n";
            break;
        }

    } while (number2 != number1);
}
int main()
{
    int number;
    cout << "Enter number: \n";
    cin >> number;
    system("clear");

    gameFunction(number);

    return 0;
}
