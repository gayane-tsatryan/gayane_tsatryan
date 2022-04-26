#ifndef DEQUE_h
#define DEQUE_h

#include "LinkedList.h"

template <typename T>
class Deque<T> {
    LinkedList<T>;

public:
    void EnqueueFirst(T value)
    {
        _items.AddFirst(value);
    }

    void EnqueueLast(T value)
    {
        _items.AddLast(value);
    }

    T DequeueFirst()
    {
        if (_items.Count == 0) {
            throw new InvalidOperationException("empty");
        }

        T temp = _items.First.Value;
        _items.RemoveFirst();

        return temp;
    }

    T DequeueLast()
    {
        if (_items.Count == 0) {
            throw new InvalidOperationException("empty"); //!!!!!
        }

        T temp = _items.Last.Value;
        _items.RemoveLast();
        return temp;
    }

    T PeekFirst()
    {
        if (_items.Count == 0) {
            throw new InvalidOperationException("empty");
        }

        return _items.First.Value;
    }

    T PeekLast()
    {
        if (_items.Count == 0) {
            throw new InvalidOperationException("empty");
        }
        return _items.Last.Value;
    }

    int _Count = _items.Count;
}
#endif
