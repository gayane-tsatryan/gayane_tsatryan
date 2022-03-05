#include <iostream>
using namespace std;

int main()
{
    int month_number;
    cout << " Input month number:   ";
    cin >> month_number;
    switch (month_number) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: {
        cout << " Total number of days = 31. \n ";
        break;
    }
    case 2: {
        cout << " Total number of days = 28 or 29 \n ";
        break;
    }
    case 4:
    case 6:
    case 9:
    case 11: {
        cout << " Total number of days = 30. \n ";
        break;
    }
    default: {
        cout << "Input number from range (1 - 12): \n ";
        break;
    }
    }
    return 0;
}

