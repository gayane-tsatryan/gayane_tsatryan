#include <iostream>
#include "polynomial.h"
using namespace std;
int main()
{
    polynomial p;
    p.get_date();
    p.Add();
    cout << endl;
    cout << "Result ";
    p.display();
    cout << endl;
    p.SubSract();
    cout << "Result ";
    p.display();
    cout << endl;
    p.Multiplay();
    cout << "Result ";
    p.display();
    cout << endl;
    p.MultiplayByNumber();
    cout << "Result ";
    p.display();
    return 0;
}
