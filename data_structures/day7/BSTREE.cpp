#include <iostream>
#include "BSTREE.h"
using namespace std;

Node* Tree::insert(Node*& root, int data)
{
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    else {
        if (data <= root->_data) {
            root->_left = insert(root->_left, data);
        }
        else {
            root->_right = insert(root->_right, data);
        }
        return root;
    }
}
bool Tree::isElemenInTree(Node* root, int value)
{

    if (root == NULL) {
        return false;
    }

    while (root != NULL) {
        if (value > root->_data) {
            root = root->_right;
        }
        else if (value < root->_data) {
            root = root->_left;
        }
        else {
            return true;
        }
    }

    return false;
}
Tree::Tree(int value)
{
    _root = new Node(value);
}
Tree::Tree()
{
    _root = NULL;
}
void Tree::sortingBST(Node* root)
{
    if (root == NULL) {
        return;
    }
    sortingBST(root->_left);
    cout << root->_data << " ";
    sortingBST(root->_right);
}
