# include "graph.h"
# include <list>

// Must be compiled with C++11 standard or later

using namespace std;

Graph::Graph(unsigned int n) {
    vertices = new list<Edge>[n]; // Creates n lists of edges
    v = n;
}

bool Graph::addEdge(const int &orig, const int &dest, const int &weight) {
    // Adds a new edge at the end of the edge's list of a vertex.
    // Return true if the operation was successful
    if ((orig >= 0 && orig < v) && (dest >= 0 && dest < v)) {
        vertices[orig].push_back(Edge{orig, dest, weight});
        return true;
    }
    return false;
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
