# ifndef curiosity_h
# define curiosity_h

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
