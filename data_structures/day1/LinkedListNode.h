#ifndef LINKED_LIST_NODE_h
#define LINKED_LIST_NODE_h

class LinkedListNode {

private:
    int _value;
    LinkedListNode* _next;

public:
    int GetValue() const;
    void SetValue(int value);

    LinkedListNode* GetNext() const;
    void SetNext(LinkedListNode* next);

    LinkedListNode(int value);
};

#endif
