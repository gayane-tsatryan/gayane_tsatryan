#include <iostream>
using namespace std;

class BinaryTreeNode {
public:
    BinaryTreeNode* Left;
    BinaryTreeNode* Right;
    int Value;
    static int _level;
    BinaryTreeNode(int value)
    {
        Value = value;
    }

    void print()
    {
        for (int i = 0; i < _level; ++i)
            cout << ' ';
        cout << Value << endl;
        ++_level;
        if (Left) {
            Left->print();
            --_level;
        }
        if (Right) {
            Right->print();
            --_level;
        }
    }
};
int BinaryTreeNode::_level = 0;
class BinaryTree {
public:
    BinaryTreeNode* _head;

    int CompareTo(int value1, int value2)
    {
        if (value1 > value2) {
            return 1;
        }
        else if (value1 < value2) {
            return -1;
        }
        else {
            return 0;
        }
    }

    void Add(int value)
    {

        if (_head == NULL) {
            _head = new BinaryTreeNode(value);
        }

        else {
            AddTo(_head, value);
        }
    }

private:
    void AddTo(BinaryTreeNode* node, int value)
    {

        if (CompareTo(node->Value, value) > 0) {

            if (node->Left == NULL) {
                node->Left = new BinaryTreeNode(value);
            }
            else {
                AddTo(node->Left, value);
            }
        }
        else {

            if (node->Right == NULL) {
                node->Right = new BinaryTreeNode(value);
            }
            else {

                AddTo(node->Right, value);
            }
        }
    }

public:
    void print()
    {
        if (!_head)
            return;
        _head->print();
    }
};

int main()
{
    BinaryTree* instance = new BinaryTree();

    instance->Add(8);
    instance->Add(5);
    instance->Add(9);
    instance->Add(10);
    instance->Add(7);
    instance->print();

    cout << instance->_head->Left->Value;
    cout << instance->_head->Right->Value;
    return 0;
}
