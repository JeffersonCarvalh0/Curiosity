# include "graph.h"
# include <list>

using namespace std;

Graph::Graph(unsigned int n) {
    vertices = new list<Edge>[n]; // Creates n lists of edges
    v = n;
}

void Graph::addEdge(const int &orig, const int &dest, const int &weight) {
    // Adds a new edge at the end of the edge's list of a vertex
    vertices[orig].push_back(Edge{orig, dest, weight});
}

bool Graph::isEdge(const int &orig, const int &dest) {
    for(Edge &li : vertices[orig]) {
        if (li.dest == dest)
            return true;
    }
    return false;
}

int Graph::getSize() {
    return v;
}

Graph::~Graph() {
    delete[] vertices;
}
