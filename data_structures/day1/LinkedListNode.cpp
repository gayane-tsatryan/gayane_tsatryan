#include <iostream>
#include "LinkedListNode.h"
using namespace std;

int LinkedListNode::GetValue() const
{
    return _value;
}
void LinkedListNode::SetValue(int value)
{
    _value = value;
}

LinkedListNode* LinkedListNode::GetNext() const
{
    return _next;
}
void LinkedListNode::SetNext(LinkedListNode* next)
{
    _next = next;
}

LinkedListNode::LinkedListNode(int value)
{
    _value = value;
}

