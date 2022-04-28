#ifndef DEQUE_h
#define DEQUE_h

#include "LinkedList.h"

template <typename T>
class Deque {
    LinkedList<T> _items;

public:
    void EnqueueFirst(T value)
    {
        _items.AddAt(value, 0);
    }

    void EnqueueLast(T value)
    {
        _items.AddAt(value, _items.getCount() - 1);
    }

    T DequeueFirst()
    {
        if (_items.getCount() == 0) {
            throw new InvalidOperationException("empty");
        }

        T temp = _items.getFirstElement();
        _items.removeFirst();

        return temp;
    }

    T DequeueLast()
    {
        if (_items.getCount() == 0) {
            throw new InvalidOperationException("empty"); //!!!!!
        }

        T temp = _items.getLastElement();
        _items.removeLast();
        return temp;
    }

    T PeekFirst()
    {
        if (_items.getCount() == 0) {
            throw new InvalidOperationException("empty");
        }

        return _items.getFirstElement();
    }

    T PeekLast()
    {
        if (_items.getCount() == 0) {
            throw new InvalidOperationException("empty");
        }
        return _items.getLastElement();
    }

    int _Count = _items.getCount();
}
#endif
