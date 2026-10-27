// Mohnish Dhankar
// 25/DA/044

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, weight;
};

void bellmanFord(int V, vector<Edge>& edges, int source)
{
    vector<int> dist(V, INT_MAX);

    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        bool updated = false;

        for (auto edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if (dist[u] != INT_MAX &&
                dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    for (auto edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        if (dist[u] != INT_MAX &&
            dist[u] + weight < dist[v])
        {
            cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << source << " -> " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    bellmanFord(V, edges, source);

    return 0;
}