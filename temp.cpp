#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge from u to v
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

// Function to calculate the in-degree of each vertex
void calculateInDegree(vector<int> adj[], int V) {
    vector<int> indegree(V, 0);  // Initialize in-degree of all vertices to 0

    // Calculate in-degree for each node
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;  // Increment in-degree of node 'it'
        }
    }

    // Output the in-degree of each node
    for (int i = 0; i < V; i++) {
        cout << "In-degree of node " << i << " is: " << indegree[i] << endl;
    }
}

int main() {
    int V = 6;  // Number of vertices
    vector<int> adj[V];  // Adjacency list to represent the graph

    // Add edges to the graph (as given in the problem)
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    // Calculate and print in-degrees
    calculateInDegree(adj, V);

    return 0;
}
