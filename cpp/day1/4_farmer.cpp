#include <iostream>
using namespace std;
int main()
{
    int chikens;
    int cows;
    int pigs;
    int total;
    cout << "How many chikens do you have?  \n";
    cin >> chikens;
    cout << "How many cows do you have?  \n";
    cin >> cows;
    cout << "How many pigs  do you have?  \n";
    cin >> pigs;
    cout << "chikens = " << chikens << "\n"
         << "cows = " << cows << "\n"
         << "pigs = " << pigs << "\n"
         << "Result = " << chikens * 2 + cows * 4 + pigs * 4 << "\n";
    return 0;
}
