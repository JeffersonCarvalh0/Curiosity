# ifndef graph_h
# define graph_h

# include <list>

class Graph {
private: // Structs
    struct Edge {
        int orig, dest, weight;
    };

private: // Attributes
    unsigned int v; // Number of vertices

    // An array containing lists of edges. Each element of the array represents
    // a vertex.
    std::list<Edge> *vertices;

public: // Methods
    Graph(unsigned int n); // Initialize a graph with a given number of vertices

    void addEdge(const int &orig, const int &dest, const int &weight); // Links two vertices
    bool isEdge(const int &v1, const int &v2); // true if there is an edge linking them
    int getSize();
    ~Graph();
};

# endif