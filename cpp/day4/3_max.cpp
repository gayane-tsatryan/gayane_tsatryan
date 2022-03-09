#include <iostream>
using namespace std;

void arrayMax(int);
int main()
{
    int length;
    cout << "Enter namber for array's length:  \n";
    cin >> length;
    arrayMax(length);
    return 0;
}

void arrayMax(int length)
{

    int array[length];
    int max;
    for (int i = 0; i < length; i++) {
        array[i] = rand() % 300;
    }
    max = array[0];
    for (int i = 0; i < length; i++) {
        if (max < array[i]) {
	    max = array[i];
	}
        cout << array[i] << ", ";
    }

    cout << endl;
    cout << "Max = " << max << endl;
}

