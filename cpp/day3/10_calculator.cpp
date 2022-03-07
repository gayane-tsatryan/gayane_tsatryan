#include <iostream>
using namespace std;

void calculator(float number1, float number2, char operatr)
{
    float result;

    switch (operatr) {
    case '+': {
        result = number1 + number2;
        break;
    }
    case '-': {
        result = number1 - number2;
        break;
    }
    case '*': {
        result = number1 * number2;
        break;
    }
    case '/': {
        result = number1 / number2;
        break;
    }
    default: {
        cout << "Error! Enter operator from (+,-,*,/): \n ";
    }
    }

    if (number2 == 0 && operatr == '/') {
        cout << "Can not divide by 0.\n";
    }
    else if (operatr == '+' || operatr == '-' || operatr == '*' || operatr == '/') {
        cout << number1 << " " << operatr << " " << number2 << " = "
             << " " << result << " \n ";
    }
}
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

