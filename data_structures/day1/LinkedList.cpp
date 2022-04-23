#include <iostream>
#include "LinkedList.h"
#include <cstddef>
using namespace std;

LinkedListNode* LinkedList::GetHead() const
{
    return _head;
}
void LinkedList::SetHead(LinkedListNode* head)
{
    _head = head;
}

LinkedListNode* LinkedList::GetTail() const
{
    return _tail;
}
void LinkedList::SetTail(LinkedListNode* tail)
{
    _tail = tail;
}
//Add
void LinkedList::Add(int value)
{

    LinkedListNode* node = new LinkedListNode(value);

    if (_head == NULL) {
        _head = node;
        _tail = node;
    }

    else {
        _tail->SetNext(node);
        _tail = node;
    }
    Count++;
}

//Remove(int item)
bool LinkedList::Remove(int item)
{
    LinkedListNode* previous = NULL;
    LinkedListNode* current = _head;

    while (current != NULL) {
        if (current->GetValue() == item) {

            if (previous != NULL) {
                previous->SetNext(current->GetNext());

                if (current->GetNext() == NULL) {
                    _tail = previous;
                }
            }
            else {
                _head = _head->GetNext();

                if (_head == NULL) {
                    _tail = NULL;
                }
            }

            Count--;
            return true;
        }

        previous = current;
        current = current->GetNext();
    }
    return false;
}
//Remove()
void LinkedList::Remove()
{
    _head = NULL;
    _tail = NULL;
    Count = 0;
}
//IsEmpty
bool LinkedList::isEmpty(LinkedList* list)
{
    if (_head == NULL && _tail == NULL) {
        return true;
    }
    return false;
}
//isGetElement(int item)
bool LinkedList::isGetElementContains(int item)
{
    LinkedListNode* current = _head;

    while (current != NULL) {
        if (current->GetValue() == item) {
            return true;
        }

        current = current->GetNext();
    }
    return false;
}

//insertAfter
void insertAfter(LinkedListNode* prevNode, int newData)
{

    if (prevNode == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }

    LinkedListNode* _newNode = NULL;

    _newNode->SetValue(newData);

    _newNode->SetNext(prevNode->GetNext());

    prevNode->SetNext(_newNode);
}
//Display
void LinkedList::Display(LinkedList* node)
{
    LinkedListNode* _head1 = node->_head;
    while (node->_head != NULL) {
        cout << node->_head->GetValue() << " ";
        node->SetHead(node->_head->GetNext());
    }
    node->_head = _head1;
}
