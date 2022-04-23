#ifndef LINKED_LIST_h
#define LINKED_LIST_h
#include "LinkedListNode.h"

class LinkedList {

private:
    LinkedListNode* _head = NULL;
    LinkedListNode* _tail = NULL;

public:
    int Count = 0;
    LinkedListNode* GetHead() const;
    void SetHead(LinkedListNode* head);

    LinkedListNode* GetTail() const;
    void SetTail(LinkedListNode* tail);

    void Add(int value);
    bool Remove(int item);
    void Remove();
    bool isGetElementContains(int item);
    bool isEmpty(LinkedList* list);
    void insertAfter(LinkedListNode* prevNode, int newData);
    void Display(LinkedList* node);
};
#endif
