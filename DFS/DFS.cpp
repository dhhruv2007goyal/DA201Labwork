//Dhhruv Goyal, 25/DA/021

#include <iostream>
#include <vector>
using namespace std;


void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int n : adj[node]) {
        if (!visited[n]) {
            DFS(n, adj, visited);
        }
    }
}

int main() {
    int vert = 5;
    vector<vector<int>> adj(vert);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    vector<bool> visited(vert, false);
    cout << "DFS Traversal: ";
    DFS(0, adj, visited);
    return 0;
}
