#include <iostream>
using namespace std;

void multipleTable(int x)
{
    int b;
    int i = 0;
    while (i <= 10) {
        b = x * i;
        cout << x << " * " << i << " = " << b << "\n";
        i++;
    }
}

int main()
{
    int a;
    cout << "Enter the number for multiplication table: ";
    cin >> a;
    if (a >= 1 && a <= 10) {
        multipleTable(a);
    }
    else {
        cout << "Error! Enter number from range (1-10): \n";
    }
    return 0;
}
