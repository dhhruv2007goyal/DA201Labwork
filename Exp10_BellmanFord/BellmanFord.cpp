//Dhhruv Goyal 25/A07/019

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter source, destination and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<long long> dist(V, LLONG_MAX);
    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        bool updated = false;

        for (const Edge &e : edges) {
            if (dist[e.u] != LLONG_MAX &&
                dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    // Check for a reachable negative-weight cycle
    for (const Edge &e : edges) {
        if (dist[e.u] != LLONG_MAX &&
            dist[e.u] + e.weight < dist[e.v]) {
            cout << "Negative-weight cycle detected.\n";
            return 0;
        }
    }

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";

        if (dist[i] == LLONG_MAX)
            cout << "Unreachable";
        else
            cout << dist[i];

        cout << '\n';
    }

    return 0;
}