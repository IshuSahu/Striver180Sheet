// Undirected Cycle
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool detectBFS(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // go to all adjacent nodes
            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // if adjacent node is visited and is not it's own parent node
                else if (parent != adjacentNode)
                {
                    // yes it is a cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool detectViaDFS(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                if (detectViaDFS(adjacentNode, node, vis, adj))
                    return true;
            }
            else if (adjacentNode != parent)
                return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // if (detectBFS(i, adj, vis))
                //     return true;
                if (detectViaDFS(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2, 1}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}