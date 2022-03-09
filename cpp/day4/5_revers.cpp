#include<iostream> 
using namespace std;

void revers(int);
int main()
{
    int length;
    cout << "Enter the number  for array's length:  ";
    cin >> length;
    revers(length);
    return 0;
}
void revers(int length)
{
    int array[length];
    int j = length - 1;
    int temp = 0;
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 300;
    }
    for (int i = 0; i < length; i++) {
        cout << array[i] << ", ";
    }

    cout << endl;

    for (int k = 0; k < j; k++) {
        temp = array[k];
        array[k] = array[j];
        array[j] = temp;
        j--;
    }
    for (int i = 0; i < length; i++) {
        cout << array[i] << ", ";
    }

    cout << endl;
}

