#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <limits>
#include <queue>
using namespace std;

class Graph {
public:
    int _size;
    int matrix[INT8_MAX][INT8_MAX];
  
    Graph(int size);
    void addEdge(int a, int b);
    void removeEdge(int a, int b);
    void addNode();
    void removeNode(int nodenumber);
    bool isEdgeExists(int node1, int node2);
    void nodeNeighbours(int node);
    void print();
    bool isPathExists(int a, int b);
    void NodeConnections(int from);

private:
    void NodeConnections(int from, bool* visited);
};

Graph::Graph(int size)
{
    _size = size;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            matrix[i][j] = 0;
        }
    }
}
bool Graph::isPathExists(int a, int b)
{
     if (a != b) {
        bool* visited = new bool[_size];
        for (int i = 0; i < _size; i++) {
            visited[i] = false;
        }
        queue<int> queue;
        queue.push(a);
        visited[a] = true;
        while (!queue.empty()) {
            int index = queue.front();
            queue.pop();
            for (int i = 0; i < _size; i++) {
                if (!visited[i] && matrix[index][i]) {
                    if (i == b) {
                        return true;
                    }
                    else {
                        visited[i] = true;
                        queue.push(i);
                    }
                }
            }
        }
        return false;
    }
    return true;
}

void Graph::addEdge(int a, int b)
{
    if (a > _size - 1 || b > _size - 1 || a < 0 || b < 0) {
        cout << "The node is not exists !" << endl;
    }
    else if (matrix[a][b] == 1 && matrix[b][a] == 1) {
        cout << "The edge is already exists " << endl;
    }
    else {
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                matrix[a][b] = 1;
                matrix[b][a] = 1;
            }
        }
    }
}

void Graph::removeEdge(int a, int b)
{
    if (a > _size - 1 || b > _size - 1 || a < 0 || b < 0) {
        cout << "The node is not exists !" << endl;
    }
    else if (matrix[a][b] == 0) {
        cout << "There is no edge  " << endl;
    }
    else {
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                matrix[a][b] = 0;
                matrix[b][a] = 0;
            }
        }
    }
}

void Graph::addNode()
{
    _size++;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            matrix[i][_size - 1] = 0;
            matrix[_size - 1][j] = 0;
        }
    }
}

void Graph::removeNode(int nodenumber)
{
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            matrix[i][nodenumber] = matrix[i][nodenumber + 1];
            matrix[nodenumber][j] = matrix[nodenumber + 1][j];
        }
    }
    _size--;
}

bool Graph::isEdgeExists(int node1, int node2)
{
    if (matrix[node1][node2] == 1 && matrix[node2][node1] == 1) {
        return true;
    }
    return false;
}

void Graph::nodeNeighbours(int node)
{
    for (int i = 0; i < _size; i++) {
        if (matrix[node][i] == 1) {
            cout << i << " ";
        }
    }
}
void Graph::NodeConnections(int from)
{
    NodeConnections(from, new bool[_size]);
}
void Graph::NodeConnections(int from, bool* visited)
{
    visited[from] = true;

    cout << from << endl;

    for (int i = 0; i < _size; i++) {
        if (matrix[from, i] != 0 && !visited[i])
            NodeConnections(i, visited);
    }
}
void Graph::print()
{
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < _size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif
