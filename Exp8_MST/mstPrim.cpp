//Dhhruv Goyal 25/DA/021

#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[100][100];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    bool selected[100] = {false};

    selected[0] = true;

    int totalWeight = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int edge = 0; edge < n - 1; edge++) {
        int minWeight = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] != 0) {
                        if (graph[i][j] < minWeight) {
                            minWeight = graph[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        cout << u << " - " << v << " = " << minWeight << endl;

        totalWeight += minWeight;
        selected[v] = true;
    }

    cout << "Minimum Cost = " << totalWeight << endl;

    return 0;
}
