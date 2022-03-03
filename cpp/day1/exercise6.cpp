#include <iostream>
using namespace std;

int main()
{
    int n;
    int i = 1;
    long long factorial = 1;

    cout << "Enter  the numbe: ";
    cin >> n;

    if (n < 0)
        cout << "Error! \n";
    else {
        while (i <= n) {
            factorial *= i;
            i++;
        }

        cout << n << "! "
             << "= " << factorial << "\n";
    }

    return 0;
}

