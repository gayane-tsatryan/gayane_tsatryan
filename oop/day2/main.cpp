#include <iostream>
#include "polynomial.h"
using namespace std;

int main()
{
    polynomial P;
    polynomial P1;
    polynomial P2;
    P1.GetData();
    P2.GetData();
    P.Multiplay(P1, P2);
    P.Add(P1, P2);
    P.Substract(P1, P2);
    P.MultByNumber(2, P1);
    return 0;
}
