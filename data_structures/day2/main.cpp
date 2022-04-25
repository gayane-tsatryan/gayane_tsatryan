#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "stack.h"
using namespace std;

int main()
{
    LinkedList<int> list;

    for (int i = 0; i < 10; i++) {
        int _value = rand() % 10 + 1;
        list.Add(_value);
    }
    list.Add(12);
    list.Add(22);
    list.removeAt(4);
    cout << list << endl;
    Stack<int> stack;
    stack.push(12);
    stack.push(23);
    cout << stack.peek() << endl;
    cout << stack.pop() << endl;
}
