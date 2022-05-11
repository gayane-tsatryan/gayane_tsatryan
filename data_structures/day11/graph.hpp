#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <climits>

using namespace std;

class Graph {
public:
    int _size;
    int** matrix;
    Graph(int size);
    int findMinDist(int*, bool*);
    void addEdge(int a, int b, int weight);
    void removeEdge(int a, int b);
    void addNode();
    void removeNode(int);
    bool isNodeExists(int node);
    bool isEdgeExists(int node1, int node2);
    void dijkstra(int**, int);
    void printPath(int dist[]);
    void nodeNeighbours(int node);
    ~Graph();
    void print();
};

Graph::Graph(int size)
{
    _size = size;
    matrix = new int*[_size];
    for (int i = 0; i < _size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < _size; j++) {
            matrix[i][j] = INT8_MAX;
        }
    }
}
int Graph::findMinDist(int* dist, bool* isvis)
{
    int min = INT8_MAX;
    for (int i = 0; i < _size; i++) {
        if (dist[i] < min && !isvis[i]) {
            min = dist[i];
        }
    }
    return min;
}

bool Graph::isEdgeExists(int node1, int node2)
{
    if (matrix[node1][node2] != 127) {
        return true;
    }
    return false;
}

bool Graph::isNodeExists(int node)
{
    if (node > _size - 1 || node < 0) {
        return false;
    }
    return true;
}

void Graph::addEdge(int a, int b, int weight)
{
    if (isNodeExists(a) && isNodeExists(b) && !isEdgeExists(a, b)) {
        matrix[a][b] = weight;
        matrix[b][a] = weight;
    }
    else {
        cout << "Action can not be perfomed" << endl;
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

Graph::~Graph()
{
    for (int i = 0; i < _size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Graph::nodeNeighbours(int node)
{
    for (int i = 0; i < _size; i++) {
        if (matrix[node][i] != 127) {
            cout << i << " ";
        }
    }
}

void Graph::removeEdge(int a, int b)
{
    if (isNodeExists(a) && isNodeExists(b) && isEdgeExists(a, b)) {

        matrix[a][b] = INT8_MAX;
        matrix[b][a] = INT8_MAX;
    }
    else
        cout << "Action can not be perfomed!" << endl;
}
void Graph::addNode()
{
    ++_size;
    int** newmatrix = new int*[_size];
    for (int i = 0; i < _size; i++) {
        newmatrix[i] = new int[_size];
        for (int j = 0; j < _size; j++) {
            if (i < _size - 1 && j < _size - 1) {
                newmatrix[i][j] = matrix[i][j];
            }
            else {
                newmatrix[i][j] = INT8_MAX;
            }
        }
    }
    delete matrix;
    matrix = newmatrix;
}

void Graph::removeNode(int index)
{
    --_size;
    int** newmatrix = new int*[_size];
    for (int i = 0; i < _size; i++) {
        newmatrix[i] = new int[_size];
        for (int j = 0; j < _size; j++) {
            if (i < index && j >= index) {
                newmatrix[i][j] = matrix[i][j + 1];
            }
            else if (i < index && j < index) {
                newmatrix[i][j] = matrix[i][j];
            }
            else if (i >= index && j < index) {
                newmatrix[i][j] = matrix[i + 1][j];
            }
            else {
                newmatrix[i][j] = matrix[i + 1][j + 1];
            }
        }
    }
    delete matrix;
    matrix = newmatrix;
}
void Graph::printPath(int* dist)
{
    cout << "Vertex               stance " << endl;
    cout << "===========================" << endl;
    for (int i = 0; i < _size; i++)
        cout << i << "     " << dist[i] << endl;
}

void Graph::dijkstra(int** graph, int node)
{
    int* distance = new int[_size];

    bool* isvisited = new bool[_size];

    for (int i = 0; i < _size; i++)
        distance[i] = INT8_MAX, isvisited[i] = false;

    distance[node] = 0;

    for (int i = 0; i < _size - 1; i++) {

        int u = findMinDist(distance, isvisited);

        isvisited[u] = true;

        for (int j = 0; j < _size; j++)

            if (!isvisited[j] && distance[u] != INT8_MAX && distance[u] + graph[u][j] < distance[j])

                distance[j] = distance[u] + graph[u][j];
    }
    printPath(distance);
}
#endif
