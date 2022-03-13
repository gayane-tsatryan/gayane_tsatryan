#include <iostream>
using namespace std;

void spiral(int);
int main()
{
    int length;
    cout << "Enter length: ";
    cin >> length;
    spiral(length);
    return 0;
}
void spiral(int length)
{
    int array[length][length];
    int count = 1, temp = 0, temp1 = length;

    while (count <= temp1 * temp1) {
        for (int i = temp; i < length; i++) {
            array[temp][i] = count++;
        }
        for (int i = temp + 1; i < length; i++) {
            array[i][length - 1] = count++;
        }
        for (int i = length - 2; i >= temp; i--) {
            array[length - 1][i] = count++;
        }
        for (int i = length - 2; i > temp; i--) {
            array[i][temp] = count++;
        }
        temp++;
        length = length - 1;
    }
    for (int i = 0; i < temp1; i++) {
        for (int j = 0; j < temp1; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

