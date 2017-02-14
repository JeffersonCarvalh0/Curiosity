# ifndef curiosity_h
# define curiosity_h

# define CONSUMPTION 10

class Graph; // Forward declaration

class CurUESPI {
private:
    // Maximium amount of fuel CurUESPI can hold
    double tcapacity;
    // Current amount of fuel
    double fuel;
    // A pointer to the graph CurUESPI is moving through
    Graph *g;
    // Current vertex in graph g
    int vertex;


public:
    // Initializes CurUESPI.
    // Recieves a tank capacity, initial fuel, a graph to go through and
    //a initial position in the graph.
    CurUESPI(const double &tcapacity, const double &fuel, Graph* const g,
    unsigned const int &init);

    // Check if it's possible to move from current position to dest.
    // If it's possible, it will return true and move. Otherwise, return false.
    bool move(const int &dest);

    // Put more gas in CurUESPI's tank.
    void setFuel(const double &fuel);
    // Return the current amount of fuel.
    int getFuel() const;

    // Set a new graph to CurUESPI
    void setGraph(Graph* const g, const unsigned int &init);
    // Return a pointer to CurUESPI's current graph
    Graph* const getGraph() const;

    int getVertex() const;
};

# endif
