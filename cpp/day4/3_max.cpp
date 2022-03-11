#include <iostream>
using namespace std;

void arrayMax();
int main()
{
    arrayMax();
    return 0;
}

void arrayMax()
{
    const int length = 10;
    double array[length];
    double max;
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % 300 -300)/10.0;
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

