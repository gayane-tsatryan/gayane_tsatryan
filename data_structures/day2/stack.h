#ifndef STACK_h
#define STACK_h

#include "LinkedList.h"

template <typename T>
class Stack {
private:
    LinkedList<T> _list;

public:
    T pop();
    T peek() const;
    void push(const T&);
    bool isEmpty() const;
    Stack();
    ~Stack();
};

template <typename T>
Stack<T>::Stack() = default;

template <typename T>
T Stack<T>::pop()
{
    T top = peek();
    _list.RemoveLast();
    return top;
}

template <typename T>
T Stack<T>::peek() const
{

    return _list.getElement(_list.GetCount() - 1);
}

template <typename T>
void Stack<T>::push(const T& value)
{
    _list.Add(value);
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return _list.GetCount() == 0;
}
template <typename T>
Stack<T>::~Stack()
{
    _list.clear();
}
#endif
