#include <iostream>
#include <cstdlib>
using namespace std;

void gameFunction(int x)
{
    int y;
    cout << "Enter number: \n";
    do {
        int y;
        cin >> y;
        if (y < x) {
            cout << "Enter the larg number: \n";
        }
        else if (y > x) {
            cout << "Enter the small number: \n";
        }
        else {
            cout << "You are winner!!! \n";
            break;
        }

    } while (y != x);
}
int main()
{
    int a;
    cout << "Enter number: \n";
    cin >> a;
    system("clear");

    gameFunction(a);

    return 0;
}
