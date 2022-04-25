#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList<int> list;

    for (int i = 0; i < 10; i++) {
        int _value = rand() % 20 + 1;
        list.Add(_value);
    }
    cout << list;
    list.Add(22);
    list.removeAt(1);
    cout << list;
}
