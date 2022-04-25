#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "stack.h"
#include "queue.h"
using namespace std;

int main()
{
    // list

    LinkedList<int> list;

    for (int i = 0; i < 10; i++) {
        int _value = rand() % 10 + 1;
        list.Add(_value);
    }

    list.AddAt(4, 2);
    cout << list;
    list.Add(12);
    list.removeAt(4);
    cout << list;

    //  Stack

    Stack<int> stack;
    stack.push(12);
    stack.push(23);
    cout << stack.peek() << endl;
    cout << stack.pop();

    //Queue

    Queue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    cout << queue.pop() << endl;
}
