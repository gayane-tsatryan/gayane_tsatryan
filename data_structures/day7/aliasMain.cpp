#include <iostream>
using namespace std;

class BinaryTreeNode {
public:
    BinaryTreeNode* Left;
    BinaryTreeNode* Right;
    int Value;
    BinaryTreeNode(int value)
    {
        Value = value;
    }
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

public:
    bool Contains(int value)
    {

        BinaryTreeNode* parent = NULL;
        return (FindWithParent(value, parent) != NULL);
    }

    int Count()
    {

        return _count;
    }
    bool Remove(int value)
    {
        BinaryTreeNode* current;
        BinaryTreeNode* parent = NULL;

        current = FindWithParent(value, parent);

        if (current == NULL) {
            return false;
        }

        _count--;

        if (current->Right == NULL) {

            if (parent == NULL) {
                _head = current->Left;
            }

            else {
                int result = CompareTo(parent->Value, current->Value);

                if (result > 0) {

                    parent->Left = current->Left;
                }

                else if (result < 0) {

                    parent->Right = current->Left;
                }
            }
        }

        else if (current->Right->Left == NULL) {
            current->Right->Left = current->Left;

            if (parent == NULL) {
                _head = current->Right;
            }

            else {
                int result = CompareTo(parent->Value, current->Value);
                if (result > 0) {
                    parent->Left = current->Right;
                }
                else if (result < 0) {
                    parent->Right = current->Right;
                }
            }
        }

        else {

            BinaryTreeNode* leftmost = current->Right->Left;
            BinaryTreeNode* leftmostParent = current->Right;

            while (leftmost->Left != NULL)

            {
                leftmostParent = leftmost;
                leftmost = leftmost->Left;
            }

            leftmostParent->Left = leftmost->Right;
            leftmost->Left = current->Left;
            leftmost->Right = current->Right;

            if (parent == NULL) {
                _head = leftmost;
            }

            else

            {
                int result = CompareTo(parent->Value, current->Value);

                if (result > 0) {
                    parent->Left = leftmost;
                }

                else if (result < 0)

                {
                    parent->Right = leftmost;
                }
            }
        }

        return true;
    }

    void Clear()
    {
        _head = NULL;
        _count = 0;
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
    instance->Remove(8);
    cout << instance->_head->Right->Value << endl;
    cout << instance->_head->Left->Value << endl;
    cout << instance->Contains(18);

    return 0;
}
