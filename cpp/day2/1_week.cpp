#include <iostream>
using namespace std;

int main()
{
    int week_number;
    cout << " Input  week number(1 - 7) :  ";
    cin >> week_number;
    switch (week_number) {
    case 1:
        cout << " Monday \n ";
        break;
    case 2:
        cout << " Tuesday \n ";
        break;
    case 3:
        cout << " Wednesday \n ";
        break;
    case 4:
        cout << " Thursday \n ";
        break;
    case 5:
        cout << " Friday \n ";
        break;
    case 6:
        cout << " Saturday \n ";
        break;
    case 7:
        cout << " Sunday \n ";
        break;
    default:
        cout << " Input number from range (1 - 7):  \n ";
        break;
    }

    return 0;
}

