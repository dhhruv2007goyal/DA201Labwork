//Dhhruv Goyal, 25/DA/021

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int u, int parent,
         vector<vector<int>>& graph,
         vector<int>& discovery,
         vector<int>& low,
         vector<bool>& visited,
         vector<bool>& articulation,
         int& timer) {
    visited[u] = true;
    discovery[u] = low[u] = timer++;
    int children = 0;
    for (int v : graph[u]) {
        if (v == parent)
            continue;
        if (visited[v]) {
            low[u] = min(low[u], discovery[v]);
        }
        else {
            children++;
            DFS(v, u, graph, discovery, low,
                visited, articulation, timer);
            low[u] = min(low[u], low[v]);
            if (parent != -1 &&
                low[v] >= discovery[u]) {
                articulation[u] = true;
            }
        }
    }
    if (parent == -1 && children > 1) {
        articulation[u] = true;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    vector<vector<int>> graph(V);
    cout << "Enter edges:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> discovery(V, -1);
    vector<int> low(V, -1);
    vector<bool> visited(V, false);
    vector<bool> articulation(V, false);
    int timer = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, -1, graph, discovery,
                low, visited, articulation, timer);
        }
    }
    cout << "\nArticulation Points: ";
    bool found = false;
    for (int i = 0; i < V; i++) {
        if (articulation[i]) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None";
    }
    return 0;
}