#include <iostream>
using namespace std;

void minToMax();
int main()
{
    minToMax();
    return 0;
}
void minToMax()
{   
    const int length = 10;
    double array[length];
    int temp = 0;
    cout << "Input : ";
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % 300 -300)/10.0;
        cout << array[i] << ", ";
    }

    cout << endl;

    for (int i = 0; i < (length - 1); i++) {
        for (int j = 0; j < (length - i - 1); j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout << "Output: ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << ", ";
    }

    cout << endl;
}

