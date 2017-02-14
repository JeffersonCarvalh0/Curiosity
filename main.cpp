# include "graph.h"
# include "curiosity.h"
# include <iostream>
# include <cstdio>
# include <vector>

// Must be compiled using C++11 standard or later

using namespace std;

int main() {
    Graph g1(5), g2(5), g3(5); // Initializes the graph

    int op, vertex;
    double tcapacity, fuel;

    // Setting edges for g1
    g1.addEdge(0, 1, 1);
    g1.addEdge(0, 3, 3);
    g1.addEdge(0, 4, 10);
    g1.addEdge(1, 2, 5);
    g1.addEdge(2, 4, 1);
    g1.addEdge(3, 2, 2);
    g1.addEdge(3, 4, 6);

    // Setting edges for g2
    g2.addEdge(0, 1, 16);
    g2.addEdge(0, 3, 2);
    g2.addEdge(0, 4, 3);
    g2.addEdge(1, 2, 5);
    g2.addEdge(3, 1, 12);
    g2.addEdge(3, 4, 7);
    g2.addEdge(4, 2, 4);

    // Setting edges for g3
    g3.addEdge(0, 1, 5);
    g3.addEdge(0, 2, 3);
    g3.addEdge(1, 3, 3);
    g3.addEdge(2, 1, 2);
    g3.addEdge(2, 3, 5);
    g3.addEdge(2, 4, 6);
    g3.addEdge(4, 3, 1);

    // Showing the graphs
    cout << "Graph 1:" << g1 << "\n";
    cout << "Graph 2:" << g2 << "\n";
    cout << "Graph 3:" << g3 << "\n";

    // Main loop
    while (true) {
        cout << "\nChoose a graph (1, 2, or 3):\n";
        if (scanf("%d", &op) != 1) {
            cout << "Invalid input.\n";
            while (getchar() != '\n');
            continue;
        }

        while (true) {
            cout << "Enter the tank capacity of CurUESPI:\n";
            if (scanf("%lf", &tcapacity) != 1) {
                cout << "Invalid input.\n";
                while (getchar() != '\n');
                continue;
            } else
                break;
        }

        while (true) {
            cout << "Enter the initial amount of fuel:\n";
            if (scanf("%lf", &fuel) != 1) {
                cout << "Invalid input.\n";
                while (getchar() != '\n');
                continue;
            } else
                break;
        }

        while (true) {
            cout << "Enter the initial vertex of the graph:\n";
            if (scanf("%d", &vertex) != 1) {
                cout << "Invalid input.\n";
                while (getchar() != '\n');
                continue;
            } else
                break;
        }

        Graph *g;
        if (op == 1)
            g = &g1;
        if (op == 2)
            g = &g2;
        if (op == 3)
            g = &g3;

        CurUESPI robot = CurUESPI(tcapacity, fuel, g, vertex);

        cout << "The robot is now operational.\n";

        int dest;
        char o;
        while (true) {
            cout << "Current position: " << robot.getVertex() << "\n";
            cout << "Current fuel: " << robot.getFuel() << " of "
            << tcapacity << "\n";

            cout << "Do you want to refuel? (y/n):\n";
            while (getchar() != '\n');
            scanf("%c", &o);
            if (o != 'y' && o != 'n') {
                cout << "Invalid input.\n";
                while (getchar() != '\n');
                continue;
            }

            if (o == 'y') {
                cout << "Enter the amount of fuel:\n";
                if (scanf("%lf", &fuel) != 1) {
                    cout << "Invalid input.\n";
                    while (getchar() != '\n');
                    continue;
                }
                robot.setFuel(fuel);
            }

            cout << "Enter a vertex to move:\n";
            if (scanf("%d", &dest) != 1) {
                cout << "Invalid input.\n";
                while (getchar() != '\n');
                continue;
            }
            robot.move(dest);
        }
    }

    return 0;
}
