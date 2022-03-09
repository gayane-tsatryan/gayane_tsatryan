#include <iostream>
using namespace std;

float rectArea (float, float);
float rectPerimeter (float, float);

int main()
{
    float x, y;
    cout << "Enter Length of Rectangle:  ";
    cin >> x;
    cout << "Enter Breadth of Rectangle:  ";
    cin >> y;
    cout << "Area = " << rectArea (x, y) << endl
         << "Perimeter = " << rectPerimeter (x, y) << endl;
    return 0;
}

float rectArea (float a, float b)
{
    float area;
    area = a * b;
    return area;
}
float rectPerimeter (float a, float b)
{
    float perimeter;
    perimeter = 2 * (a + b);
    return perimeter;
}
