#include <iostream>
using namespace std;

void matrix1();
int main()
{
    matrix1();
    return 0;
}
void matrix1()
{
    const int length = 5;
    int array[5][5] = {};
    int sum = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            array[i][j] = rand() % 10;
            cout << " " << array[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            sum += array[i][j];
        }
    }
    cout << "sum = " << sum << endl;

    sum = 0;
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            sum += array[i][j];
        }
    }
    cout << "sum = " << sum << endl;

    sum = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            sum += array[i][j];
        }
    }
    cout << "sum = " << sum << endl;

    sum = 0;
    for (int i = 1; i < length; i++) {
        for (int j = length - i; j < length; j++) {
            sum += array[i][j];
        }
    }
    cout << "sum = " << sum << endl;

    sum = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length - i - 1; j++) {
            sum += array[i][j];
        }
    }
    cout << "sum = " << sum << endl;

    sum = 0;
    int temp = 0;
    if (length % 2 == 1) {
        temp = (length / 2) + 1;
    }
    else {
        temp = length / 2;
    }
    int temp1 = temp;
    for (int i = 1; i < length - 1; i++) {

        if (i == temp || i > temp) {
            temp--;
            for (int j = 0; j < temp; j++) {
                sum += array[i][j];
            }
        }
        else {
            for (int j = 0; j < i; j++) {
                sum += array[i][j];
            }
        }
    }
    cout << "sum = " << sum << endl;

    sum = 0;
    int temp2 = temp1;
    for (int i = temp1; i < length; i++) {
        for (int j = temp1 - 1; j < i; j++) {
            sum += array[i][j];
        }
        temp1--;
    }
    cout << "sum = " << sum << endl;

    sum = 0;
    for (int i = 1; i < length - 1; i++) {

        if (i == temp2 || i > temp2) {
            temp2++;
            for (int j = temp2; j < length; j++) {
                sum += array[i][j];
            }
        }
        else {
            for (int j = length - i; j < length; j++) {
                sum += array[i][j];
            }
        }
    }
    cout << "sum = " << sum << endl;
}

