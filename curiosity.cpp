# include "curiosity.h"
# include "graph.h"
# include <iostream>
# include <list>    // std::list

// Must be compiled using C++11 standard or later

using namespace std;

CurUESPI::CurUESPI(const double &tcapacity, const double &fuel, Graph* const g,
unsigned const int &init) {
    this->tcapacity = (tcapacity < 0) ? 100 : tcapacity;
    this->fuel = (tcapacity < 0) ? 0 : fuel;
    this->g = g;
    this->vertex = (init > g->getVerNum() || init < 0) ? 0 : init;
}

bool CurUESPI::move(const int &dest) {
    list<int> path;
    int dist = g->dijkstra(vertex, dest, path);
    if (dist != -1 && dist * CONSUMPTION <= fuel) {
        for (int &i : path) {
            cout << "Moving from " << vertex << " to " << i << "\n";
            vertex = i;
        }
        fuel -= dist * CONSUMPTION;
        return true;
    }

    if (dist == -1)
        cout << "A path from " << vertex << " to " << dest << " doesn't exist.\n";

    if (dist * CONSUMPTION > fuel)
        cout << "Not enough fuel.\n";

    return false;
}

void CurUESPI::setFuel(const double &fuel) {
    if (fuel < 0 || fuel + this->fuel > tcapacity)
        return;
    this->fuel += fuel;
}

int CurUESPI::getFuel() const {
    return fuel;
}

void CurUESPI::setGraph(Graph* const g, const unsigned int &init) {
    this->g = g;
    this->vertex = (init < 0 || init > g->getVerNum()) ? 0 : init;
}

Graph* const CurUESPI::getGraph() const {
    return g;
}

int CurUESPI::getVertex() const {
    return vertex;
}
