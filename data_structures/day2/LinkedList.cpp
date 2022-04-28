#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
int LinkedList<T>::getCount() const
{
    return _count;
}

template <class T>
T LinkedList<T>::getFirstElement()
{
    Node<T>* instance = _head;
    return _head->_value;
}

template <class T>
T LinkedList<T>::getLastElement()
{
    Node<T>* instance = _head;
    for (int i = 0; i < getCount() - 2; i++) {
        instance = instance->_next;
    }
    return instance->_next->_value;
}

template <class T>
void LinkedList<T>::Add(T value)
{
    Node<T>* _node = new Node<T>(value);
    if (_head == NULL) {
        _head = _node;
        _tail = _node;
    }
    else {
        _tail->_next = _node;
        _tail = _node;
    }
    _count++;
}

template <class T>
void LinkedList<T>::AddAt(T value, int index)
{
    if (index == 0) {
        _head = new Node<T>(value, _head);
    }
    else {
        Node<T>* instance = _head;
        for (int i = 0; i < index - 1; i++) {
            instance = instance->_next;
        }
        Node<T>* newNode = new Node<T>(value, instance->_next);
        instance->_next = newNode;
    }
    _count++;
}

template <class T>
void LinkedList<T>::removeAt(int index)
{
    if (index == 0) {
        Node<T>* instance = _head;
        _head = _head->_next;
        delete instance;
    }
    else {
        Node<T>* instance = _head;
        for (int i = 0; i < index - 1; i++) {
            instance = instance->_next;
        }
        Node<T>* instnce1 = instance->_next;
        instance->_next = instnce1->_next;
        delete instnce1;
    }
    _count--;
}
template <class T>
void LinkedList<T>::removeFirst()
{
    removeAt(0);
}
template <class T>
void LinkedList<T>::removeLast()
{
    removeAt(getCount() - 1);
}
template <class T>
void LinkedList<T>::clear()
{
    while (_count) {
        Node<T>* instnce = _head;
        _head = _head->_next;
        delete instnce;
        _count--;
    }
}

template <class T>
T LinkedList<T>::getElement(int index) const
{
    Node<T>* instance = _head;
    int _count = 0;
    while (instance != nullptr) {
        if (_count == index) {
            return (instance->_value);
        }
        _count++;
        instance = instance->_next;
    }
    return instance->_value;
}

template <class T>
ostream& operator<<(ostream& out, const LinkedList<T>& instnce)
{
    Node<T>* _temporary;
    _temporary = instnce._head;
    while (_temporary != NULL) {
        out << _temporary->_value << " ";
        _temporary = _temporary->_next;
    }
    out << endl;
    return out;
}
