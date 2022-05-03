#ifndef NODE_H
#define NODE_H

class Node {
public:
    int _data;
    Node* _left;
    Node* _right;

    Node(int data);
    Node();
};
#endif
