// Mohnish Dhankar
// 25/DA/044

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] = findParent(parent[vertex], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u == v)
        return;

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalCost = 0;
    int edgesUsed = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (Edge edge : edges) {

        int u = edge.u;
        int v = edge.v;

        if (findParent(u, parent) != findParent(v, parent)) {

            cout << u << " - " << v
                 << " : " << edge.weight << endl;

            totalCost += edge.weight;

            unionSet(u, v, parent, rank);

            edgesUsed++;

            if (edgesUsed == V - 1)
                break;
        }
    }

    cout << "Total weight of MST = " << totalCost << endl;

    return 0;
}
