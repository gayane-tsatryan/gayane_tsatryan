#include <iostream>
using namespace std;

void decToBinary(int);

int main()
{
    int number;
    cout << "Input: ";
    cin >> number;
    cout << "Output: ";
    decToBinary(number);
    cout << endl;

    return 0;
}

void decToBinary(int number)
{
    int array[32];
    int i = 0;

    if (number == 0) {
        cout << "0";
    }
    else {

        while (number > 0) {
            array[i] = number % 2;
            number = number / 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            cout << array[j];
        }
    }
}
