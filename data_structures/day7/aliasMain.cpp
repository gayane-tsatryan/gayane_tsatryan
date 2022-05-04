#include <iostream>
using namespace std;

class BinaryTreeNode {
public:
    BinaryTreeNode(int value)
    {
        Value = value;
    }
    BinaryTreeNode* Left;
    BinaryTreeNode* Right;
    int Value;
};

class BinaryTree {
private:
    int _count;

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
        _count++;
    }

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

    bool Contains(int value)
    {

        BinaryTreeNode* parent = NULL;
        return (FindWithParent(value, parent) != NULL);
    }

private:
    BinaryTreeNode* FindWithParent(int value, BinaryTreeNode* parent)
    {

        BinaryTreeNode* current = _head;
        parent = NULL;

        while (current != NULL) {
            int result = CompareTo(current->Value, value);
            if (result > 0) {

                parent = current;
                current = current->Left;
            }
            else if (result < 0) {

                parent = current;
                current = current->Right;
            }
            else {

                break;
            }
        }
        return current;
    }

    int Count()
    {
        return _count;
    }
};

int main()
{
    BinaryTree* instance = new BinaryTree();

    instance->Add(8);
    instance->Add(5);
    instance->Add(9);
    cout << instance->_head->Right->Value << endl;
    cout << instance->_head->Left->Value << endl;
    cout << instance->Contains(18);

    return 0;
}
