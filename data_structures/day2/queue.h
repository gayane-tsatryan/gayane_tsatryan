#ifndef QUEUE_h
#define QUEUE_h

#include "LinkedList.h"

template <typename T>
class Queue {
private:
    LinkedList<T> _list;

public:
    void push(T);
    T pop();
    T front() const;
    T back() const;
    bool isEmpty() const;
    Queue() = default;
    ~Queue();
};
template <typename T>
void Queue<T>::push(T value)
{
    _list.Add(value);
}

template <typename T>
T Queue<T>::pop()
{
    T _value = front();
    _list.removeAt(_list.GetCount() - 1);
    return _value;
}

template <typename T>
T Queue<T>::front() const
{
    return _list.getElement(0);
}

template <typename T>
T Queue<T>::back() const
{
    return _list.getElement(_list.GetCount() - 1);
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return _list.GetCount() == 0;
}
template <typename T>
Queue<T>::~Queue()
{
    _list.clear();
}
#endif
