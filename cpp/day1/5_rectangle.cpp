#include <iostream>
using namespace std;

int main()
{
    float Length, Breadth, perimeter, area;
    cout << "Enter Length of Rectangle:  ";
    cin >> Length;
    cout << "Enter Breadth of Rectangle:  ";
    cin >> Breadth;
    area = Length * Breadth;
    cout << "Area = " << area << "\n";
    perimeter = 2 * (Length + Breadth);
    cout << "Perimeter = " << perimeter << "\n";
    return 0;
}
