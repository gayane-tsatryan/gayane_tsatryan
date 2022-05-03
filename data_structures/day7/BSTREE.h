#ifndef BS_TREE_H
#define BS_TREE_H
#include "NODE.h"

class Tree {
public:
    Node* _root;

    Tree();
    Tree(int value);
    Node* insert(Node*& root, int data);
    bool isElemenInTree(Node* root, int value);
    void sortingBST(Node* root);
};
#endif
