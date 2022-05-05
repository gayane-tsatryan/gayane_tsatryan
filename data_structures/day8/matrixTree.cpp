#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class BinaryTreeNode {
public:
    BinaryTreeNode* Left;
    BinaryTreeNode* Right;
    int Value;
    BinaryTreeNode(int value)
    {
        Left = NULL;
        Right = NULL;
        Value = value;
    }
};

class BinaryTree {
private:
    int _count;

public:
    BinaryTreeNode* _head;

    void print(BinaryTree* root)
    {
        if (root == NULL)
            return;

        queue<BinaryTreeNode*> q;

        q.push(root->_head);

        while (!q.empty()) {

            BinaryTreeNode* tree = q.front();
            cout << tree->Value << " ";
            q.pop();

            if (tree->Left != NULL)
                q.push(tree->Left);

            if (tree->Right != NULL)
                q.push(tree->Right);
        }
    }
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

    bool Contains(int value)
    {

        BinaryTreeNode* parent = NULL;
        return (FindWithParent(value, parent) != NULL);
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
};

void Input(int** arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
        }
    }
}

bool isBinaryTree(int** arr, int size, vector<int>& matrixIndexes)
{
    Input(arr, size);

    bool row = true;
    int temp2 = 0;

    for (int i = 0; i < size; i++) {
        int _temp = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 1) {
                ++_temp;
                if (_temp > 2) {
                    row = false;
                }
            }
            if (arr[i][j] == arr[j][i] && arr[j][i] == 1) {
                row = false;
            }

            if (arr[i][j] == 1) {
                matrixIndexes.push_back(j);
            }
        }

        int count = 0;
        for (int k = 0; k < size; k++) {
            if (arr[k][i] == 0) {
                ++count;
            }
            if (count == size) {
                ++temp2;
            }
        }
    }
    if (temp2 != 1) {
        row = false;
    }
    return row;
}
int getRoot(int** arr, int size, vector<int>& matrixIndexes)
{
    int index = -1;
    bool isbin = isBinaryTree(arr, size, matrixIndexes);
    if (isbin) {
        for (int i = 0; i < size; i++) {
            int count = 0;
            for (int j = 0; j < size; j++) {
                if (arr[j][i] == 0) {
                    ++count;
                }
            }
            if (count == size) {
                index = i;
            }
        }
    }
    return index;
}

int main()
{
    int size = 4;
    int** arr = new int*[size];

    vector<int> matrixIndexes;
    int _length = getRoot(arr, size, matrixIndexes);
    BinaryTree* tree = new BinaryTree();

    if (_length != -1) {
        tree->Add(_length);
        for (int i = 0; i < matrixIndexes.size(); i++) {
            tree->Add(matrixIndexes[i]);
        }
    }
    tree->print(tree);

    return 0;
}
