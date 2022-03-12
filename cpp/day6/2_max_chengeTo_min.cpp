#include <iostream>
using namespace std;

void matrix();
int main()
{
    matrix();
    return 0;
}
void matrix()
{
    const int row = 5;
    const int column = 7;
    double array[row][column];
    double tempmin = 0;
    double tempmax = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            array[i][j] = (rand() % 50 - 500) / 10.0;

            if (array[i][j] < 10) {
                cout << " " << array[i][j];
            }
            else if (array[i][j] < 100) {
                cout << "   " << array[i][j];
            }
            else {
                cout << "  " << array[i][j];
            }
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++) {
        int x = 0;
        int y = 0;
        tempmin = array[i][0];
        tempmax = array[i][0];

        for (int j = 1; j < column; j++) {
            if (tempmin >= array[i][j]) {
                tempmin = array[i][j];
                x = j;
            }

            else if (tempmax < array[i][j]) {
                tempmax = array[i][j];
                y = j;
            }
        }

        array[i][x] = tempmax;
        array[i][y] = tempmin;
    }

    cout << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {

            if (array[i][j] < 10) {
                cout << " " << array[i][j];
            }
            else if (array[i][j] < 100) {
                cout << "   " << array[i][j];
            }
            else {
                cout << "  " << array[i][j];
            }
        }
        cout << endl;
    }
}

