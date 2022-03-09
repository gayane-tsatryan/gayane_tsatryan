
#include <iostream>
using namespace std;

void calculator(float, float, char );

int main()
{
    char operatr;
    float number1, number2, result;
    cout << "Input number 1: ";
    cin >> number1;
    cout << "Input operator: ";
    cin >> operatr;
    cout << "Input number 2: ";
    cin >> number2;

    calculator(number1, number2, operatr);
    return 0;
}

void calculator(float number1, float number2, char operatr)
{
    float result;

    switch (operatr) {
    case '+': {
        result = number1 + number2;
        cout << number1 << " " << operatr << " " << number2 << " = " << " " << result << " \n ";
        break;
    }
    case '-': {
        result = number1 - number2;
        cout << number1 << " " << operatr << " " << number2 << " = " << " " << result << " \n ";
        break;
    }
    case '*': {
        result = number1 * number2;
        cout << number1 << " " << operatr << " " << number2 << " = " << " " << result << " \n ";
        break;
    }
    case '/': {
        if (number2 == 0) {
            cout << "Can not divide by 0.\n";
        }
        else {
            result = number1 / number2;
            cout << number1 << " " << operatr << " " << number2 << " = " << " " << result << " \n ";
        }
        break;
    }
    default: {
        cout << "Error! Enter operator from (+,-,*,/): \n ";
    }
    }
}
