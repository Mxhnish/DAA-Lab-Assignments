//Name:- Mohnish Dhankar
//Roll No.:- 25/DA/044


#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    vector<int> disc, low, parent;
    vector<bool> ap;
    int timer;

    void DFS(int u) {
        disc[u] = low[u] = ++timer;

        int children = 0;

        for (int v : adj[u]) {

            if (disc[v] == -1) {
                children++;
                parent[v] = u;

                DFS(v);

                low[u] = min(low[u], low[v]);

                if (parent[u] == -1 && children > 1)
                    ap[u] = true;

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
            }

            else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);

        disc.assign(V, -1);
        low.assign(V, -1);
        parent.assign(V, -1);
        ap.assign(V, false);

        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findArticulationPoints() {

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1)
                DFS(i);
        }

        cout << "Articulation Points: ";

        bool found = false;

        for (int i = 0; i < V; i++) {
            if (ap[i]) {
                cout << i << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << endl;
    }
};

int main() {

    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges:\n";

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.findArticulationPoints();

    return 0;
}