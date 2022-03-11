#include<iostream> 
using namespace std;

void revers();
int main()
{
    revers();
    return 0;
}
void revers()
{    
    const int length = 10;
    double array[length];
    int j = length - 1;
    int temp = 0;
    cout << "Input: ";
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % 300 -300)/10.0;
        cout << array[i] << ", ";
    }

    cout << endl;

    for (int k = 0; k < j; k++) {
        temp = array[k];
        array[k] = array[j];
        array[j] = temp;
        j--;
    }
    cout << "Output: ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << ", ";
    }

    cout << endl;
}

