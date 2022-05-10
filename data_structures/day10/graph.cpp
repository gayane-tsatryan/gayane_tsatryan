#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream>
using namespace std;
class Graph {
public:
    int _verticesNumber;

    LinkedList<int>* _array;
    Graph(int verticenum)
    {
        _verticesNumber = verticenum;
        _array = new LinkedList<int>[_verticesNumber];
        for (int i = 0; i < _verticesNumber; i++) {
            _array[i]._head = NULL;
            _array[i]._tail = NULL;
        }
    }

    void addNode()
    {
        ++_verticesNumber;
        LinkedList<int>* _array1 = new LinkedList<int>[_verticesNumber];
        for (int i = 0; i < _verticesNumber; i++) {
            _array1[i] = _array[i];
            Node<int>* temp = _array[i]._head;
            while (temp != NULL) {
                int a = temp->_value;
                _array1[i].Add(a);
                temp = temp->_next;
            }
        }
        delete _array;
        _array = _array1;
    }
    void removeNode(int index)
    {
        --_verticesNumber;
        LinkedList<int>* _array1 = new LinkedList<int>[_verticesNumber];
        for (int i = 0; i < _verticesNumber; i++) {
            if (i >= index) {
                _array1[i] = _array[i + 1];
                Node<int>* temp = _array[i + 1]._head;
                while (temp != NULL) {
                    int a = temp->_value;
                    _array1[i].Add(a);
                    temp = temp->_next;
                }
            }
            else {
                _array1[i] = _array[i];
                Node<int>* temp = _array[i]._head;
                while (temp != NULL) {
                    int a = temp->_value;
                    _array1[i].Add(a);
                    temp = temp->_next;
                }
            }
        }
        delete _array;
        _array = _array1;
    }

    bool isEdge(int a, int b)
    {

        for (int i = 0; i < _verticesNumber; i++) {
            Node<int>* temp = _array[a]._head;

            while (temp != NULL) {
                if (b == temp->_value) {
                    return true;
                }
                temp = temp->_next;
            }
            return false;
        }
    }
    void addEdge(int value, int v)
    {
        if (!isEdge(value, v)) {
            _array[value].Add(v);
            _array[v].Add(value);
        }
    }
    void removeEdge(int value, int v)
    {
        if (isEdge(value, v)) {
            _array[value].removeAt(v);
            _array[v].removeAt(value);
        }
    }
    void findNeighbours(int value)
    {
        Node<int>* temp = _array[value]._head;

        while (temp != NULL) {
            cout << temp->_value;
            temp = temp->_next;
        }
    }
    void Display()
    {
        for (int i = 0; i < _verticesNumber; i++) {
            cout << i << " :";

            Node<int>* temp = _array[i]._head;

            while (temp != NULL) {
                cout << temp->_value << " ";
                temp = temp->_next;
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph* graph = new Graph(4);

    graph->addEdge(2, 3);
    graph->addEdge(0, 2);

    graph->addEdge(0, 1);

    graph->removeEdge(2, 3);
    graph->addEdge(3, 2);
    graph->Display();
    cout << graph->isEdge(0, 1);
    return 0;
}
