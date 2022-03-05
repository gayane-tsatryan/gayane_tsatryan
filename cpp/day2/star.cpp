#include <iostream>
using namespace std;

int main()
{
    int c, i = 0;
    cout << "Enter count: \n";
    cin >> c;
    const int count = c;
    i = count;

    while (i > 0) {
        int j = 0;
        while (j < i) {
            cout << " * ";
            j++;
        }

        j = 0;

        cout << " " << endl;

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

        while (j < count - i) {
            cout << " ";
            j++;
        }
        j = 0;
        while (j <= i) {
            cout << "*";
            j++;
        }
        j = 0;

        i++;

        cout << " " << endl;
    }
    i = 0;

    while (i < count) {
        int j = 0;

        while (j < count - i) {
            cout << " ";
            j++;
        }
        j = 0;
        while (j <= i) {
            cout << " *";
            j++;
        }
        j = 0;

        i++;

        cout << " " << endl;
    }
    i = 0;

    while (i < count) {
        int j = 0;

        while (j < count - i) {
            cout << " ";
            j++;
        }

        j = 0;

        while (j <= 2 * i) {
            cout << "*";
            j++;
        }

        j = 0;
        i++;

        cout << " " << endl;
    }

    return 0;
}

