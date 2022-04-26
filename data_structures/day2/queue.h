#ifndef QUEUE_h
#define QUEUE_h

#include "LinkedList.h"

template <typename T>
class Queue<T> {
    LinkedList<T> _items = new LinkedList<T>();

public:
    void push(T value)
    {
        _items.AddFirst(value);
    }

    T pop()
    {
        if (_items.Count == 0) {
            throw new InvalidOperationException("empty");
        }

        T last = _items.Last.Value;
        _items.RemoveLast();
        return last;
    }

    T Peek()
    {
        if (_items.Count == 0) {
            throw new InvalidOperationException("empty");
        }

        return _items.Last.Value;
    }

    int Count = _items.Count;
}

Queue()= default;
~Queue();
}
;

template <typename T>
Queue<T>::~Queue()
{
    _list.clear();
}
#endif
