# include "curiosity.h"
# include <list>

using namespace std;

Graph::Graph() {
    neighbors == nullptr;
}

void Graph::addNeighbor(Graph &g, int dist) {
    neighbors.push_back(neighbor{&g, dist});
}
