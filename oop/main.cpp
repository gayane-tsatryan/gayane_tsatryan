#include <iostream>
#include "programmer.h"
using namespace std;

int main()
{
    //Programmer * ptrProgHomo = new Homosapience();
    // Programmer* ptrProgHum = new Human();
    Programmer programmer = new Programmer();
    programmer.HardWork();
    cout << programmer._compSkills;
    return 0;
}
