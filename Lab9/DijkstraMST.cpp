// Mohnish Dhankar
// 25/DA/044

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[source] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] &&
                (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << source << " -> " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "Unreachable";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}
