// Mohnish Dhankar
// 25/DA/044

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the weighted adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(V, false);

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    visited[0] = true;

    for (int count = 0; count < V - 1; count++) {

        int minWeight = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j] != 0 &&
                        graph[i][j] < minWeight) {

                        minWeight = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = true;

        cout << u << " - " << v
             << " : " << minWeight << endl;

        totalCost += minWeight;
    }

    cout << "Total weight of MST = " << totalCost << endl;

    return 0;
}
