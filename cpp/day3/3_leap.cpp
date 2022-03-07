#include <iostream>
using namespace std;

void leapFunction(int y)
{
    int i = 0;

    while (i < 20) {

        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            cout << y << endl;
            i++;
        }
        y++;
    }
}
int main()
{
    int a;
    cout << "Enter the year: \n";
    cin >> a;
    leapFunction(a);

    return 0;
}

