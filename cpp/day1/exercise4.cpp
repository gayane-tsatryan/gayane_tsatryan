#include <iostream>
using namespace std;
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
    cout << "chikens = " << x << "\n"
         << "cows = " << y << "\n"
         << "pigs = " << z << "\n"
         << "Result = " << x * 2 + y * 4 + z * 4 << "\n";
    return 0;
}
