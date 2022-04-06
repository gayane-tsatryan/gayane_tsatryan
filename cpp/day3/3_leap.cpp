#include <iostream>
using namespace std;

void leapFunction(int year)
{
    int i = 0;

    while (i < 20) {

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            cout << year << endl;
            i++;
        }
        year++;
    }
}
int main()
{
    int year;
    cout << "Enter the year: \n";
    cin >> year;
    leapFunction(year);

    return 0;
}

