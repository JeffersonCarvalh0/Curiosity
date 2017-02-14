# include "graph.h"
# include <iostream>
# include <list>        // std::list
# include <vector>      // std::vector
# include <queue>       // std::priority_queue
# include <functional>  // std::greater

# define INFINITE 10000000

// Must be compiled with C++11 standard or later

using namespace std;

Graph::Graph(unsigned int n) : v(n) {
    vertices = new list<Edge>[n];
    e = 0;
}

bool Graph::addEdge(unsigned const int &orig, unsigned const int &dest,
    const int &weight) {
    // Adds a new edge at the end of the edge's list of a vertex.
    // Return true if the operation was successful
    if ((orig >= 0 && orig < v) && (dest >= 0 && dest < v)) {
        vertices[orig].push_back(Edge{orig, dest, weight});
        ++e;
        return true;
    }
    return false;
}

bool Graph::isEdge(const int &orig, const int &dest, const int &weight) const {
    for(Edge &li : vertices[orig]) {
        if (li.orig == orig && li.dest == dest && li.weight == weight)
            return true;
    }
    return false;
}

bool Graph::isEdge(const int &orig, const int &dest) const {
    for (Edge &li : vertices[orig]) {
        if (li.orig == orig && li.dest == dest)
            return true;
    }
    return false;
}

bool Graph::Edge::operator > (const Edge &e) const {
    return (weight > e.weight);
}

int Graph::dijkstra(const unsigned int v1, const unsigned int v2,
    list<int> &path) const {
    // Contains the weights from v1 to the other vertices
    vector<int> weights(v, INFINITE);
    // List of visited vertices
    vector<bool> visited(v, false);
    // Priority queue for minimal distance
    priority_queue<Edge, vector<Edge>, greater<Edge>> queue;

    // The weight on an edge between a vertex and itself is zero
    weights[v1] = 0;

    // Add v1 in the priority queue
    queue.push(Edge{v1, v1, 0});

    unsigned int tempVertex;
    bool found = false;
    // Main loop
    while(!found && !queue.empty()) {
        // Recieves the destiny vertex of the next edge in queue
        tempVertex = queue.top().dest;
        // Remove it from the queue
        queue.pop();
        // Check if it was already visited
        if (!visited[tempVertex]) {
            // Check if there is and edge between the last vertex in path and
            //the one that will be added
            while (tempVertex != v1 && !isEdge(path.back(), tempVertex))
                path.pop_back();
            // Add it to shortest path
            path.push_back(tempVertex);
            // If true...
            // Set its respective value in visited vector to true
            visited[tempVertex] = true;
            // Iterate over the adjacency list of tempVertex
            for (Edge &e : vertices[tempVertex]) {
                // Compares the weight from each edge that goes from
                //tempVertex to its respective weight in weights vector
                //plus itself. (i.e "Relaxing" the edge)
                if (weights[e.dest] > weights[tempVertex] + e.weight) {
                    // If true, this is a cheaper way, so refresh
                    //its weight in weights vector.
                    weights[e.dest] = weights[tempVertex] + e.weight;
                    // Verify if the target vertex was reached
                    if (tempVertex == v2) {
                        found = true;
                        break;
                    }
                    // Makes a new "edge" to e.dest with the new value
                    queue.push(Edge{tempVertex, e.dest, weights[e.dest]});
                }
            }
        }
    }
    // If the algorithm didint find a path
    if (weights[v2] == INFINITE) {
        path = list<int> (1, v1);
        return -1;
    }
    return weights[v2];
}

int Graph::dijkstra(const unsigned int v1, const unsigned int v2) const {
    list<int> path(0);
    int r = dijkstra(v1, v2, path);
    return r;
}

unsigned int Graph::getVerNum() const {
    return v;
}

unsigned int Graph::getEdgNum() const {
    return e;
}

ostream& operator << (ostream &out, const Graph &g) {
    for (unsigned int i = 0; i < g.v; ++i) {
        cout << "\nVertex " << i << ": \n";
        for (Graph::Edge &e : g.vertices[i])
            cout << "(" << e.orig << ", " << e.dest << ", " << e.weight << ")";
    }
    return out;
}

Graph::~Graph() {
    delete[] vertices;
}
