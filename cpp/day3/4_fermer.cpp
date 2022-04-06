#include <iostream>
using namespace std;

void sumFunction(int chikens, int cows, int pigs)
{
    cout << "chikens = " << chikens << "\n"
         << "cows = " << cows << "\n"
         << "pigs = " << pigs << "\n"
         << "Result = " << chikens * 2 + cows * 4 + pigs * 4 << "\n";
}
int main()
{
    int chikens;
    int cows;
    int pigs;
    cout << "How many chikens do you have?  \n";
    cin >> chikens;
    cout << "How many cows do you have?  \n";
    cin >> cows;
    cout << "How many pigs  do you have?  \n";
    cin >> pigs;
    sumFunction(chikens, cows, pigs);
    return 0;
}

