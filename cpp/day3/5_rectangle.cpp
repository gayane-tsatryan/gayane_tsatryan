#include <iostream>
using namespace std;

float rectArea (float, float);
float rectPerimeter (float, float);

int main()
{
    float Length, Breadth;
    cout << "Enter Length of Rectangle:  ";
    cin >> Length;
    cout << "Enter Breadth of Rectangle:  ";
    cin >> Breadth;
    cout << "Area = " << rectArea (Length, Breadth) << endl
         << "Perimeter = " << rectPerimeter (Length, Breadth) << endl;
    return 0;
}

float rectArea (float Length, float Breadth)
{
    float area;
    area = Length * Breadth;
    return area;
}
float rectPerimeter (float Length, float Breadth)
{
    float perimeter;
    perimeter = 2 * (Length + Breadth);
    return perimeter;
}
