// https://www.gatevidyalay.com/wp-content/uploads/2018/06/Example-of-Bipartite-Graph.png
//  A bipartite graph is one where you can split nodes into two groups so that every edge goes between the groups, never inside.

#include <bits/stdc++.h>
using namespace std;

bool isBipartiteBFS(int V, vector<int> adj[])
{
    vector<int> color(V, -1); // -1 = uncolored, 0 = Red, 1 = Blue

    for (int start = 0; start < V; start++)
    {
        if (color[start] == -1)
        {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto it : adj[node])
                {
                    if (color[it] == -1)
                    {
                        color[it] = 1 - color[node]; // opposite color
                        q.push(it);
                    }
                    else if (color[it] == color[node])
                    {
                        return false; // same color → not bipartite
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int V = 4;
    vector<int> adj[V];

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);

    cout << (isBipartiteBFS(V, adj) ? "Bipartite" : "Not Bipartite");
    return 0;
}
