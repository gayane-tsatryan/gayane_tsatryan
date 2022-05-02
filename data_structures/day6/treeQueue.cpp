#include <iostream>
#include <queue>
using namespace std;

class Tree {
public:
    int _data;
    Tree* _left;
    Tree* _right;

    Tree(int data)
    {
        _data = data;
        _left = nullptr;
        _right = nullptr;
    }
    Tree()
    {
        _data = 0;
        _left = nullptr;
        _right = nullptr;
    }
};

int minFunction(Tree* root)
{
    int min = root->_data;
    if (root == NULL) {
        return 0;
    }
    queue<Tree*> q;

    q.push(root);

    while (!q.empty()) {

        Tree* tree = q.front();

        if (min >= tree->_data) {
            min = tree->_data;
        }
        q.pop();

        if (tree->_left != NULL)
            q.push(tree->_left);

        if (tree->_right != NULL)
            q.push(tree->_right);
    }
    return min;
}

int maxFunction(Tree* root)
{
    int _max = root->_data;
    if (root == NULL) {
        return 0;
    }
    queue<Tree*> q;

    q.push(root);

    while (!q.empty()) {

        Tree* tree = q.front();

        if (_max <= tree->_data) {
            _max = tree->_data;
        }
        q.pop();

        if (tree->_left != NULL)
            q.push(tree->_left);

        if (tree->_right != NULL)
            q.push(tree->_right);
    }
    return _max;
}

int sumFunction(Tree* root)
{
    int _sum = 0;
    if (root == NULL) {
        return 0;
    }
    queue<Tree*> q;

    q.push(root);

    while (!q.empty()) {

        Tree* tree = q.front();

        _sum += tree->_data;
        q.pop();

        if (tree->_left != NULL)
            q.push(tree->_left);

        if (tree->_right != NULL)
            q.push(tree->_right);
    }
    return _sum;
}

void print(Tree* root)
{
    if (root == NULL)
        return;

    queue<Tree*> q;

    q.push(root);

    while (!q.empty()) {

        Tree* tree = q.front();
        cout << tree->_data << " ";
        q.pop();

        if (tree->_left != NULL)
            q.push(tree->_left);

        if (tree->_right != NULL)
            q.push(tree->_right);
    }
}
Tree* insert(Tree* node, int data)
{
    if (node == NULL)
        return new Tree(data);
    else {
        if (data <= node->_data) {
            node->_left = insert(node->_left, data);
        }
        else {
            node->_right = insert(node->_right, data);
        }
        return node;
    }
}

int main()
{
    Tree* root = new Tree(1);
    root->_left = new Tree(2);
    root->_right = new Tree(3);
    root->_left->_left = new Tree(4);
    root->_left->_right = new Tree(5);
    root->_right->_left = new Tree(6);
    root->_right->_right = new Tree(7);
    insert(root, 45);
    print(root);
    cout << endl;
    cout << minFunction(root) << endl;
    cout << maxFunction(root) << endl;
    cout << sumFunction(root) << endl;
    return 0;
}
