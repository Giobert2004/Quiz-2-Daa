#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> Pair;

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<Pair>>& graph, int source) {
    int n = graph.size();
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    vector<int> dist(n, INT_MAX);

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}

int main() {
    int n, e;

    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<Pair>> graph(n);

    cout << "Enter edges (format: src dest weight):\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // If the graph is undirected
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}
