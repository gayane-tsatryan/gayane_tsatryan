#include <iostream>
using namespace std;

void sumFunction(int a, int b, int c)
{
    cout << "chikens = " << a << "\n"
         << "cows = " << b << "\n"
         << "pigs = " << c << "\n"
         << "Result = " << a * 2 + b * 4 + c * 4 << "\n";
}
int main()
{
    int x;
    int y;
    int z;
    int total;
    cout << "How many chikens do you have?  \n";
    cin >> x;
    cout << "How many cows do you have?  \n";
    cin >> y;
    cout << "How many pigs  do you have?  \n";
    cin >> z;
    sumFunction(x, y, z);
    return 0;
}

