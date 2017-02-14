# ifndef graph_h
# define graph_h

# include <list>
# include <iosfwd>

class Graph {
private: // Structs
    struct Edge {
        int orig, dest, weight;

        bool operator > (const Edge &e) const;
    };

private: // Attributes
    unsigned int v; // Number of vertices
    unsigned int e; // Number of edges

    // An array containing lists of edges. Each element of the array represents
    //a vertex.
    std::list<Edge> *vertices;

public: // Methods
    // Initialize a graph with a given number of vertices
    explicit Graph(const unsigned int n);

    // Links two vertices
    bool addEdge(const int &orig, const int &dest, const int &weight = 0);

    // true if there is an edge linking them
    bool isEdge(const int &orig, const int &dest, const int &weight) const;
    bool isEdge(const int &orig, const int &dest) const;

    // Implements Dijkstra's algotithm to find the shortest path
    // Returns the cost between v1 and v2. Returns by parameter a list
    //with the shortest path between v1 and v2.
    // If it didn't find a path, it will return -1, and path will contain
    //a single element (which is v1)
    int dijkstra(const unsigned int v1, const unsigned int v2,
        std::list<int> &path) const;

    // Function above overloaded in order to don't need a list.
    int dijkstra (const unsigned int v1, const unsigned int v2) const;

    // Return v
    unsigned int getVerNum() const;

    // Return e
    unsigned int getEdgNum() const;

    // Deallocate memory allocated for vertices
    ~Graph();

friend std::ostream& operator << (std::ostream &out, const Graph &g);
};

# endif
