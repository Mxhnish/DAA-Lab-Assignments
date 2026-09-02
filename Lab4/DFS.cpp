
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);
    vector<bool> visited(V, false);

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "\nConnected Components:\n";

    int component = 1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            cout << "Component " << component << ": ";
            DFS(i, graph, visited);
            cout << endl;

            component++;
        }
    }

    return 0;
}

