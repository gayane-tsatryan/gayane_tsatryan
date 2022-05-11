#include <iostream>
#include "graph.hpp"

using namespace std;
int main()
{
    Graph graph(6);
    graph.print();
    graph.addEdge(0, 3, 2);
    graph.addEdge(1, 4, 9);
    graph.addEdge(2, 3, 7);
    graph.addEdge(1, 2, 6);
    graph.addEdge(2, 4, 5);
    graph.addNode();
    graph.print();
    graph.removeEdge(2,3);
    graph.dijkstra(graph.matrix, 0);
    graph.print();
    graph.removeNode(2);
    graph.print();

    return 0;
}
