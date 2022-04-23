#include <iostream>
using namespace std;
#include "LinkedList.h"

int main()
{
    LinkedList* instance = new LinkedList{};

    for (int i = 1; i <= 20; i++) {
        instance->Add(i);
    }
  
    cout << "Print  list" << endl;
    instance->Display(instance);
    cout << "\nIs empty list \n" << instance->isEmpty(instance) << endl;
    cout << "Is element  contains in list  \n" << instance->isGetElementContains(3) << endl;
    cout << "Remove value:" << endl;
    instance->Remove(10);
    instance->Display(instance);
    cout << "\nRemove all list" << endl;
    instance->Remove();
    instance->Display(instance);
    cout << "\nIs empty list \n" << instance->isEmpty(instance) << endl;
    return 0;
}
