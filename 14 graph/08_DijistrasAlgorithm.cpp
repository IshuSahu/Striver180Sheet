// finds the shortest path from a given source node to every other node
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Min-heap priority queue: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second; // node/vertex
        int d = pq.top().first; // distance
        pq.pop();

        // If current distance is greater than recorded, skip
        if (d > dist[u])
            continue;

        // Explore neighbors
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) //  this is called realxation
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

//Without Priority Queue:
vector<int> dijkstraWP(int V, vector<pair<int,int>> adj[], int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;
        // Pick the unvisited node with the smallest distance
        for (int j = 0; j < V; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == INT_MAX) break; // remaining nodes are unreachable
        visited[u] = true;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    return dist;
}

/*
Time: O(V^2 + E)
Space: O(V)
*/
int main()
{
    int V = 5; // number of vertices
    vector<pair<int, int>> adj[V];

    // Add edges: adj[u].push_back({v, weight});
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int src = 0;
    vector<int> distances = dijkstra(V, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " -> " << distances[i] << endl;
    }
}
