#ifndef QUEUE_h
#define QUEUE_h

#include "LinkedList.h"

template <typename T>
class Queue {
    LinkedList<T> _items = new LinkedList<T>();

public:
    void push(T value)
    {
        _items.AddAt(value,0);
    }

    T pop()
    {
        if (_items.getCount() == 0) {
            throw new InvalidOperationException("empty");
        }

        T last = _items.getLastElement();
        _items.removeLast();
        return last;
    }

    T Peek()
    {
        if (_items.getCount() == 0) {
            throw new InvalidOperationException("empty");
        }

        return _items.getLastElement();
    }

    int Count = _items.getCount();

    Queue() = default;
    ~Queue()
    {
        _list.clear();
    }
};

#endif
