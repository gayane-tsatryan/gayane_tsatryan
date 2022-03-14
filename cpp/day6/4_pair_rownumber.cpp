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
    int array[row][column];
    int temp = 0;
    int temp1 = 0;
    string number = "";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            array[i][j] = rand()%70;
            cout << array[i][j];
            if (array[i][j] % 2 == 0) {
                temp++;
            }
        }

        if (temp == column) {
            temp1++;
            cout << i << endl;
            break;
        }
        temp = 0;
    }

    if (temp1 == 0) {
        cout << "No!" << endl;
    }
}

