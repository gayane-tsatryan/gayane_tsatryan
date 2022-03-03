#include <iostream>
using namespace std;
int main()
{
    float a, b, perimeter, area;
    cout << "Enter Length of Rectangle:  ";
    cin >> a;
    cout << "Enter Breadth of Rectangle:  ";
    cin >> b;
    area = a * b;
    cout << "Area = " << area << "\n";
    perimeter = 2 * (a * b);
    cout << "Perimeter = " << perimeter << "\n";
    return 0;
}

