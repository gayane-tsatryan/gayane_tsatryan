#include <iostream>
#include "NODE.h"
using namespace std;

Node::Node(int data)
{
    _data = data;
    _left = nullptr;
    _right = nullptr;
}
Node::Node()
{
    _data = 0;
    _left = nullptr;
    _right = nullptr;
}
