#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[])
{
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;
    // o(v + e)
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        // node is in your topo sort
        // so please remove it from the indegree
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    if (cnt == V)
        return false;
    return true;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 6;
    vector<int> adj[V];

    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 1, 5);

    bool ans = isCyclic(V, adj);
    if (ans)
        cout << "True";
    else
        cout << "Flase";
    cout << endl;

    return 0;
}
