// This sort applicable on DAGs

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node); // push after visiting all neighbors
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }

    vector<int> topoSortViaBFS(int V, vector<int> adj[]) // via Kahn’s Algorithm
    {
        vector<int> indegree(V, 0);

        // calculate indegree
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        // push nodes with indegree 0
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> " << indegree[i]<<endl;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        int cnt=0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            cnt++;
            // reduce indegree of neighbors
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        cout<<"cnt: V"<<cnt<<V<<endl;
        return topo;
    }
};

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

    Solution obj;
    // vector<int> ans = obj.topoSort(V, adj);
    vector<int> ans = obj.topoSortViaBFS(V, adj);

    for (auto it : ans)
        cout << it << " ";
    return 0;
}
