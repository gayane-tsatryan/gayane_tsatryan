#include <iostream>
using namespace std;

void star(int a)
{
    int i;
    const int count = a;
    i = count;

    while (i > 0) {
        int j = 0;
        while (j < i) {
            cout << " * ";
            j++;
        }

        cout << endl;
        j = 0;
        i--;
    }

    while (i < count) {
        int j = 0;
        while (j <= i) {
            cout << " * ";
            j++;
        }
        j = 0;
        cout << " " << endl;
        i++;
    }

    i = 0;
    while (i < count) {
        int j = 0;
        while (j <= count) {
            if (j < count - i) {
                cout << " ";
            }
            else {
                cout << "*";
            }
            j++;
        }
        cout << endl;
        i++;
    }

    i = 0;

    while (i < count) {
        int j = 0;
        while (j <= count + i) {
            if (j < count - i) {
                cout << " ";
            }
            else {
                cout << "*";
            }
            j++;
        }
        cout << endl;
        i++;
    }

    i = 0;
    while (i < count) {
        int j = 0;
        while (j <= count) {
            if (j < count - i) {
                cout << " ";
            }
            else {
                cout << " *";
            }
            j++;
        }
        cout << endl;
        i++;
    }
}

int main()
{
    int a;
    cout << "Enter number:  \n";
    cin >> a;
    star(a);
    return 0;
}

