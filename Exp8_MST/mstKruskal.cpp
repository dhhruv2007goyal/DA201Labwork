#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int parent[100];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[100];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Initialize parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges according to weight
    sort(edges, edges + e, [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    int totalWeight = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            cout << u << " - " << v << " = " << edges[i].weight << endl;

            totalWeight += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    cout << "Minimum Cost = " << totalWeight << endl;

    return 0;
}