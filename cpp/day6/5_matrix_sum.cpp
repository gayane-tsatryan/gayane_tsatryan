#include <iostream>
using namespace std;

void sumMatrix(int);
int main()
{   
    int length;
    cout << "Input length of matrix: ";
    cin >> length;
    sumMatrix(length);
    return 0;
}
void sumMatrix(int a)
{
    const int length = a;
    int array[length][length];
    int array1[length][length];
    int array2[length][length];
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            array1[i][j] = rand() % 10 + 1;
            array2[i][j] = rand() % 10 + 1;
            array[i][j] = array1[i][j] + array2[i][j];
            if (array1[i][j] < 10) {
                cout << "  " << array1[i][j];
            }
            else {
                cout << " " << array1[i][j];
            }
        }

        cout << "    ";
        for (int j = 0; j < length; j++) {
            if (array2[i][j] < 10) {
                cout << "  " << array2[i][j];
            }
            else {
                cout << " " << array2[i][j];
            }
        }
        cout << "    ";
        for (int j = 0; j < length; j++) {
            if (array[i][j] < 10) {
                cout << "  " << array[i][j];
            }
            else {
                cout << " " << array[i][j];
            }
        }
        cout << endl;
    }
}

