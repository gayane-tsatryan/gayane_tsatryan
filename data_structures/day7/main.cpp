#include <iostream>
#include "BSTREE.h"
using namespace std;

int main()
{
    Tree* instance = new Tree();

    instance->insert(instance->_root, 12);
    instance->insert(instance->_root, 1);
    instance->insert(instance->_root, 2);
    instance->insert(instance->_root, 22);
    instance->insert(instance->_root, 9);
    instance->insert(instance->_root, 7);

    instance->sortingBST(instance->_root);
    cout << endl;
    cout << instance->isElemenInTree(instance->_root, 12) << endl;
    cout << instance->_root->_data << endl;
    return 0;
}
