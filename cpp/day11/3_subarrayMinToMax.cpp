#include <iostream>
using namespace std;

void subArr(int array[], int length);

int main()
{
    int length;
    cout << "Enter array length: ";
    cin >> length;
    int array[length];
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 100 + 1;
    }
    subArr(array, length);
    cout << endl;
    return 0;
}

void subArr(int array[], int length)
{
    int max = 1, temp = 1, index = 0;
    for (int i = 1; i < length; i++) {
        if (array[i] > array[i - 1])
            temp++;
        else {
            if (max < temp) {
                max = temp;
                index = i - max;
            }

            temp = 1;
        }
    }

    if (max < temp) {
        max = temp;
        index = length - max;
    }

    for (int i = index; i < max + index; i++)
        cout << array[i] << " ";
}
