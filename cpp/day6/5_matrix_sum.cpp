#include <iostream>
using namespace std;

void sumMatrix();
int main()
{
    sumMatrix();
    return 0;
}
void sumMatrix()
{
    const int length = 10;
    int array[10][10];
    int array1[10][10];
    int array2[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
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
        for (int j = 0; j < 10; j++) {
            if (array2[i][j] < 10) {
                cout << "  " << array2[i][j];
            }
            else {
                cout << " " << array2[i][j];
            }
        }
        cout << "    ";
        for (int j = 0; j < 10; j++) {
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

