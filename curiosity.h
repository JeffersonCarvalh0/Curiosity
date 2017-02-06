# ifndef curiosity_h
# define curiosity_h

# include <list>

class Graph {
private:
    struct neighbor {
        Graph *n;
        int distance;
    };
    std::list <neighbor*> neighbors;

public:
    Graph();
    void addNeighbor(Graph &g, int dist);

};

class CurUESPI {
private:
    double tcapacity;
    double fuel;

public:
    CurUESPI(double tcapacity = 10, double fuel);
    int move(Graph &g);
    void putFuel(double fuel);
};

# endif
