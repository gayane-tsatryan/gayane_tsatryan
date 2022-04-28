#ifndef LINKED_LIST_h
#define LINKED_LIST_h

#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T _value;
    Node<T>* _next = nullptr;
    Node<T>(T value, Node<T>* next = nullptr)
    {
        _value = value;
        _next = next;
    }
};

template <class T>
class LinkedList {
    Node<T>* _head;
    Node<T>* _tail;
    int _count;

public:
    void Add(T);
    void AddAt(T, int);
    void removeAt(int);
    void removeLast();
    void removeFirst();
    T getFirstElement();
    T getLastElement();
    void clear();
    T getElement(const int) const;
    int getCount() const;

    template <class Type>
    friend ostream& operator<<(ostream& out, const LinkedList<Type>&);

    LinkedList()
    {
        _count = 0;
        _head = nullptr;
        _tail = nullptr;
    }
    ~LinkedList()
    {
        clear();
    }
};
#endif
