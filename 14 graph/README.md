Perfect ⚡ Ishu — let’s do the same *pattern-wise mastery* for **Graph Algorithms**, exactly in the **structured, clean, and interview-ready format** like the one you loved for Greedy.

---

# 🌉 **Graph Algorithms — Pattern Wise Mastery Guide**

Graph problems are among the **most diverse and high-yield** topics in interviews.
After reading this, you’ll clearly know:

✅ What is a Graph
✅ When to Apply Graphs
✅ Major Graph Patterns (like traversal, shortest path, union-find, topo sort, etc.)
✅ How to identify each pattern
✅ Step-by-step problem-solving method
✅ 1 solved example + key practice problems for each

---

## 🚀 1️⃣ What Is a Graph?

A **Graph** is a collection of:

* **Vertices (nodes)** → represent entities
* **Edges (links)** → represent connections between them

### Types:

| Type                     | Example                     | Description                 |
| ------------------------ | --------------------------- | --------------------------- |
| Undirected               | Roads between cities        | Edge has no direction       |
| Directed (Digraph)       | Dependencies, prerequisites | Edge has direction          |
| Weighted                 | Flight distance, cost       | Each edge has a weight      |
| Unweighted               | Social network              | Edges have equal weight     |
| Cyclic / Acyclic         | Loop detection              | Cycle presence matters      |
| Connected / Disconnected | Network                     | Whether all nodes reachable |

### Common Representations

* **Adjacency List** → `vector<vector<int>> adj;`
* **Adjacency Matrix** → `n x n matrix`
* **Edge List** → list of `(u,v,w)`

---

## 🧠 2️⃣ When to Apply Graph Algorithms

Use graphs when:

* Elements are **connected by relationships**
* You’re asked for **reachability, connectivity, shortest path, cycle detection**, etc.
* Problems involve **networks, grids, or dependencies**

Common problem signs:

> “Find if A is connected to B”,
> “Minimum steps / shortest path”,
> “Detect cycle / dependency order”,
> “Minimum cost to connect”, etc.

---

## 🧩 3️⃣ Major Graph Algorithm Patterns

| #  | Pattern                                         | Core Purpose                                              |
| -- | ----------------------------------------------- | --------------------------------------------------------- |
| 1  | DFS Traversal                                   | Explore all connected nodes deeply                        |
| 2  | BFS Traversal                                   | Level-wise traversal / shortest path in unweighted graphs |
| 3  | Cycle Detection (Directed/Undirected)           | Detect loops                                              |
| 4  | Topological Sort                                | Linear order of directed acyclic graph                    |
| 5  | Union-Find / Disjoint Set                       | Detect connected components or cycles efficiently         |
| 6  | Dijkstra’s Algorithm                            | Shortest path in weighted graphs (no negatives)           |
| 7  | Bellman-Ford                                    | Shortest path with negative edges                         |
| 8  | Floyd-Warshall                                  | All-pairs shortest paths                                  |
| 9  | Minimum Spanning Tree (Kruskal’s / Prim’s)      | Connect all nodes with minimum cost                       |
| 10 | BFS/DFS on Grids                                | Island problems, flood fill                               |
| 11 | Strongly Connected Components (Kosaraju/Tarjan) | Find groups of mutually reachable nodes                   |

---

## 🔍 4️⃣ How to Identify Each Pattern

| Problem Phrase             | Likely Pattern          |
| -------------------------- | ----------------------- |
| “Reachable / Connected”    | DFS / BFS               |
| “Minimum steps / levels”   | BFS                     |
| “Detect loop / cycle”      | DFS / Union-Find        |
| “Dependency / order”       | Topological Sort        |
| “Shortest path weighted”   | Dijkstra / Bellman-Ford |
| “Minimum cost connect”     | MST (Kruskal / Prim)    |
| “Find all components”      | DFS / Union-Find        |
| “Grid or matrix traversal” | BFS / DFS on grids      |

---

## 🧭 5️⃣ Pattern-Wise Deep Dive

---

### 🧩 **Pattern 1: DFS (Depth-First Search)**

**When to use:**
Explore all paths or connected regions (recursively or using stack).
Used in: Connected components, detecting cycles, topological sort prep.

**Steps:**

1. Build adjacency list
2. Keep `visited[]`
3. Call recursive DFS(node): mark visited, explore unvisited neighbors
4. Use postorder logic if needed (for topo sort, etc.)

**Example (Connected Components in Undirected Graph)**

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
    vis[node] = 1;
    for (int nbr : adj[node])
        if (!vis[nbr]) dfs(nbr, adj, vis);
}

int countComponents(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i]) { count++; dfs(i, adj, vis); }
    return count;
}
```

✅ **Example:**
Graph: 0—1, 2—3 → Output: 2 components

**Practice Problems:**

* [Leetcode 323. Number of Connected Components](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
* [GFG. DFS of Graph](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

---

### 🧩 **Pattern 2: BFS (Breadth-First Search)**

**When to use:**
Shortest path in unweighted graph, level-order traversal, minimum steps.

**Steps:**

1. Initialize queue with source(s)
2. Pop node → explore neighbors
3. Mark visited & push to queue
4. Track `distance[]` or `level[]`

**Example (Shortest Path in Unweighted Graph)**

```cpp
int shortestPath(int n, vector<vector<int>>& adj, int src, int dest) {
    vector<int> dist(n, -1);
    queue<int> q; q.push(src); dist[src] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[dest];
}
```

✅ **Example:**
Graph: 0—1, 1—2, 0—3, 3—2
Shortest path 0 → 2 = 2 edges

**Practice Problems:**

* [Leetcode 1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/)
* [Leetcode 1091. Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

---

### 🧩 **Pattern 3: Cycle Detection**

#### 🔸 Undirected Graph (DFS)

Use parent tracking — if neighbor visited but not parent → cycle.

#### 🔸 Directed Graph (DFS with Recursion Stack)

Use 2 arrays: `visited[]` and `pathVisited[]`.

**Example (Directed Cycle Detection):**

```cpp
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
    vis[node] = pathVis[node] = 1;
    for (int nbr : adj[node]) {
        if (!vis[nbr] && dfs(nbr, adj, vis, pathVis)) return true;
        else if (pathVis[nbr]) return true;
    }
    pathVis[node] = 0;
    return false;
}
bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<int> vis(n,0), pathVis(n,0);
    for (int i=0;i<n;i++) if(!vis[i] && dfs(i,adj,vis,pathVis)) return true;
    return false;
}
```

✅ **Example:**
Graph: 0→1→2→0 → cycle found

**Practice Problems:**

* [GFG. Detect cycle in a directed graph](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)
* [Leetcode 207. Course Schedule](https://leetcode.com/problems/course-schedule/)

---

### 🧩 **Pattern 4: Topological Sort**

**When to use:**
DAG problems — dependency resolution, task scheduling.

**Steps (Kahn’s BFS):**

1. Compute `inDegree[]` for each node
2. Push all nodes with indegree 0 to queue
3. Pop, append to topo list, decrease indegree of neighbors
4. Repeat until queue empty

**Example:**

```cpp
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indeg(n, 0);
    for (int u=0;u<n;u++) for (int v:adj[u]) indeg[v]++;
    queue<int> q;
    for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
    vector<int> res;
    while(!q.empty()){
        int u=q.front(); q.pop();
        res.push_back(u);
        for(int v:adj[u]) if(--indeg[v]==0) q.push(v);
    }
    return res;
}
```

✅ **Example:**
Edges: 0→1, 1→2 → Topo order = [0,1,2]

**Practice Problems:**

* [Leetcode 210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
* [GFG. Topological Sort](https://www.geeksforgeeks.org/problems/topological-sort/1)

---

### 🧩 **Pattern 5: Union-Find / Disjoint Set**

**When to use:**
Detect cycle in undirected graph, count connected components, MST (Kruskal).

**Steps:**

1. Each node → parent of itself
2. Find function (with path compression)
3. Union by rank/size
4. Detect if two nodes already have same parent → cycle.

**Example (Cycle detection Undirected):**

```cpp
int find(int x, vector<int>& par){ return par[x]==x ? x : par[x]=find(par[x], par); }

bool unionGraph(int u, int v, vector<int>& par){
    int pu=find(u,par), pv=find(v,par);
    if(pu==pv) return true;
    par[pu]=pv;
    return false;
}
```

✅ **Example:**
Edges: (0,1), (1,2), (2,0) → cycle exists

**Practice Problems:**

* [Leetcode 684. Redundant Connection](https://leetcode.com/problems/redundant-connection/)
* [GFG. Disjoint Set Union](https://www.geeksforgeeks.org/disjoint-set-data-structures/)

---

### 🧩 **Pattern 6: Dijkstra’s Algorithm**

**When to use:**
Find shortest distance in **weighted graph (no negative weights)**.

**Steps:**

1. Use min-heap `(dist, node)`
2. Pop smallest distance node, relax neighbors
3. Update distances & push if smaller found

**Example:**

```cpp
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, 1e9);
    dist[src]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        for(auto [v,w]:adj[u]){
            if(dist[v]>d+w){
                dist[v]=d+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}
```

✅ **Example:**
Weighted graph:
0→1(4), 0→2(1), 2→1(2) → Shortest 0→1=3

**Practice Problems:**

* [Leetcode 743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)
* [GFG. Dijkstra Algorithm](https://practice.geeksforgeeks.org/problems/dijkstra-algorithm/1)

---

### 🧩 **Pattern 7: Minimum Spanning Tree (Kruskal / Prim)**

**When to use:**
Connect all vertices with **minimum total weight**.

**Kruskal’s Steps:**

1. Sort edges by weight
2. Use Union-Find
3. Add smallest edges avoiding cycles

✅ **Example:**

```cpp
int mst(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](auto&a, auto&b){return a[2]<b[2];});
    vector<int> par(n); iota(par.begin(), par.end(), 0);
    int cost=0, count=0;
    for(auto &e:edges){
        int u=e[0],v=e[1],w=e[2];
        int pu=find(u,par),pv=find(v,par);
        if(pu!=pv){ par[pu]=pv; cost+=w; count++; }
        if(count==n-1) break;
    }
    return cost;
}
```

**Practice Problems:**

* [GFG. Minimum Spanning Tree](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)
* [Leetcode 1135. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)

---

### 🧩 **Pattern 8: Graph on Grids (2D BFS/DFS)**

**When to use:**
“Number of islands”, “flood fill”, “shortest path in matrix”.

**Steps:**

1. Treat grid cells as graph nodes
2. 4/8-direction moves
3. DFS/BFS until boundary or invalid cell

**Example (Number of Islands):**

```cpp
void dfs(int i,int j,vector<vector<char>>& grid){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0') return;
    grid[i][j]='0';
    dfs(i+1,j,grid); dfs(i-1,j,grid); dfs(i,j+1,grid); dfs(i,j-1,grid);
}
int numIslands(vector<vector<char>>& grid){
    int count=0;
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
            if(grid[i][j]=='1'){ count++; dfs(i,j,grid); }
    return count;
}
```

**Practice Problems:**

* [Leetcode 200. Number of Islands](https://leetcode.com/problems/number-of-islands/)
* [Leetcode 695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/)

---

## 🧾 6️⃣ Graph Pattern Summary

| Pattern         | Core Technique       | Typical Problem                    |
| --------------- | -------------------- | ---------------------------------- |
| DFS             | Recursion / Stack    | Connectivity, cycle detection      |
| BFS             | Queue                | Shortest path (unweighted), levels |
| Cycle Detection | DFS / Union-Find     | Loop detection                     |
| Topo Sort       | Kahn / DFS Postorder | Task ordering                      |
| Union-Find      | Disjoint Set         | Components, Kruskal                |
| Dijkstra        | Heap                 | Shortest path weighted             |
| MST             | Kruskal/Prim         | Minimum connection cost            |
| Grid Graph      | BFS/DFS              | Islands, flood fill                |

---

## 🧩 7️⃣ Practice Roadmap

**🟢 Beginner:**

* DFS of Graph (GFG)
* BFS of Graph (GFG)
* Number of Islands (LC 200)

**🟡 Intermediate:**

* Course Schedule (LC 207)
* Detect Cycle in Directed Graph (GFG)
* Shortest Path in Binary Matrix (LC 1091)

**🔴 Advanced:**

* Dijkstra / Kruskal MST
* Strongly Connected Components (Kosaraju)
* Network Delay Time (LC 743)
* Redundant Connection (LC 684)

---

## 💡 Key Insight

> Every graph problem reduces to **exploring**, **connecting**, or **optimizing** over nodes and edges.
>
> 🔹 Use **DFS/BFS** for reachability
> 🔹 Use **Union-Find** for components
> 🔹 Use **Topo Sort** for order
> 🔹 Use **Dijkstra / MST** for optimal cost

---