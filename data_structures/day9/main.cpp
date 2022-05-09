#include <iostream>
#include "graph.hpp"

using namespace std;

int main()
{

    Graph graph(4);
    graph.addEdge(1, 2);
    graph.addEdge(0, 1);
    graph.addEdge(3, 1);
    graph.addEdge(2, 3);
    graph.removeEdge(1, 2);
    graph.addNode();
    graph.removeNode(3);
    graph.print();
    cout << graph.isPathExists(3, 2) << endl;
    graph.NodeConnections(3);

    return 0;
}
