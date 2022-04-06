#include <iostream>
using namespace std;

void star1 (int);
void star2 (int);
void star3 (int);
void star4 (int);
void star5 (int);

int main ()
{
    int starQuantity;
    cout << "Enter number:  \n";
    cin >> starQuantity;
    star1 (starQuantity);
    star2 (starQuantity);
    star3 (starQuantity);
    star4 (starQuantity);
    star5 (starQuantity);

    return 0;
}
void star1 (int starQuantity)
{
    int i;
    const int count = starQuantity;
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
void star2 (int starQuantity)
{
    int i = 0;
    const int count = starQuantity;
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
void star3 (int starQuantity)
{
    int i = 0;
    const int count = starQuantity;
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
void star4 (int starQuantity)
{
    int i = 0;
    const int count = starQuantity;
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
void star5 (int starQuantity)
{
    int i = 0;
    const int count = starQuantity;
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
