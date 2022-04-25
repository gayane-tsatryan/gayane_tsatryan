#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
int LinkedList<T>::GetCount() const
{
    return _count;
}
template <class T>
void LinkedList<T>::Add(T value)
{
    if (_head == NULL) {
        _head = new Node<T>(value);
    }
    else {
        Node<T>* instance = _head;
        while (instance->_next != nullptr) {
            instance = instance->_next;
        }
        instance->_next = new Node<T>(value);
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
void LinkedList<T> ::removeLast()
{
    removeAt(GetCount() - 1);
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
