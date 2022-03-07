#include <iostream>
using namespace std;

void rectAreaPerimeter(float a, float b)
{
    float perimeter, area;
    area = a * b;
    cout << "Area = " << area << "\n";
    perimeter = 2 * (a + b);
    cout << "Perimeter = " << perimeter << "\n";
}

int main()
{
    float x, y;
    cout << "Enter Length of Rectangle:  ";
    cin >> x;
    cout << "Enter Breadth of Rectangle:  ";
    cin >> y;
    rectAreaPerimeter(x, y);
    return 0;
}
