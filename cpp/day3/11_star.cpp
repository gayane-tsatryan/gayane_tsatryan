#include <iostream>
using namespace std;

void star1 (int);
void star2 (int);
void star3 (int);
void star4 (int);
void star5 (int);

int main ()
{
    int a;
    cout << "Enter number:  \n";
    cin >> a;
    star1 (a);
    star2 (a);
    star3 (a);
    star4 (a);
    star5 (a);

    return 0;
}
void star1 (int a)
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
}
void star2 (int a)
{
    int i = 0;
    const int count = a;
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
}
void star3 (int a)
{
    int i = 0;
    const int count = a;
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
}
void star4 (int a)
{
    int i = 0;
    const int count = a;
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
}
void star5 (int a)
{
    int i = 0;
    const int count = a;
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
