# 📘 Graph Data Structure – Detailed Notes

## 1. Definition

A **graph** is a data structure that consists of a set of nodes (also called vertices) connected by edges.
It is used to model relationships or connections between pairs of objects.

- **Vertices (nodes):** Fundamental units that hold data (denoted as V).
- **Edges (links):** Connections between pairs of vertices (denoted as E).

Mathematically, a graph is represented as:
\[
G = (V, E)
\]

---

## 2. Graph Terminology

- **Vertex (V):** A point in the graph.
- **Edge (E):** A connection between two vertices.
- **Degree of a Vertex:**
  - **Indegree:** No. of edges incoming to a vertex.
  - **Outdegree:** No. of edges outgoing from a vertex.
- **Path:** Sequence of vertices connected by edges.
- **Cycle:** A path where the first and last vertices are the same.
- **Connected Graph:** Every vertex is reachable from any other vertex.
- **Disconnected Graph:** At least one vertex is not reachable from another.
- **Weighted Graph:** Edges have weights (cost, distance, etc.).
- **Unweighted Graph:** Edges are simple connections, no weights.
- **Directed Graph (Digraph):** Edges have a direction (u → v).
- **Undirected Graph:** Edges have no direction (u — v).

---

## 3. Types of Graphs

1. **Undirected Graph** – Edges have no direction.  
   Example: Social network friendship.

2. **Directed Graph (Digraph)** – Edges have direction.  
   Example: Twitter followers.

3. **Weighted Graph** – Each edge has a weight (distance, cost, time).  
   Example: Google Maps route graph.

4. **Unweighted Graph** – Edges are equal.

5. **Cyclic Graph** – Contains at least one cycle.

6. **Acyclic Graph** – No cycle exists.

7. **Directed Acyclic Graph (DAG)** – Directed graph without cycles.  
   Example: Task scheduling.

8. **Complete Graph (Kn)** – Every pair of vertices has an edge.

9. **Sparse Graph** – Very few edges compared to maximum possible.

10. **Dense Graph** – Number of edges is close to maximum.

11. **Bipartite Graph** – Vertices can be divided into two disjoint sets U and V such that every edge connects a vertex from U to V.

---

## 4. Graph Representation

### 4.1. Adjacency Matrix

- A 2D array `matrix[V][V]`.
- `matrix[i][j] = 1` (or weight) if there is an edge from `i → j`, else `0`.  
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20240424142649/Adjacency-Matrix-for-Undirected-and-Unweighted-graph.webp" alt="Adjacency Matrix Diagram" width="400"/>

✅ Advantages:

- Easy to implement.
- Quick edge lookup `O(1)`.

❌ Disadvantages:

- Uses `O(V^2)` space even if graph is sparse.
  A sparse graph is a type of graph where the number of links or edges is significantly lower than the maximum possible number of links

---

### 4.2. Adjacency List

- Each vertex has a list of its neighbors.
- Example (Linked list or vector of vectors).
- <img src="https://media.geeksforgeeks.org/wp-content/uploads/20241022101636356241/graph-representation-of-directed-graph-to-adjacency-list-4.webp" alt="Adjacency List Diagram" width="400"/>

✅ Advantages:

- Space efficient for sparse graphs: `O(V + E)`.
- Easy to iterate over neighbors.

❌ Disadvantages:

- Edge lookup is slower than matrix (`O(degree(V))`).
---

## 5. Graph Traversal Algorithms

### 5.1. Depth First Search (DFS)

- Depth-First Search (DFS) is a graph/tree traversal algorithm that explores a path as deep as possible before backtracking
- Uses **stack** (or recursion).
- Time Complexity: **O(V + E)**

Applications:

- Detect cycles.
- Topological sorting.
- Connected components.

---

### 5.2. Breadth First Search (BFS)

- Breadth-First Search (BFS) is a graph/tree traversal algorithm that explores all the nodes at the current level before moving to the next level.
- Uses **queue**.
- Time Complexity: **O(V + E)**

Applications:

- Shortest path in **unweighted graphs**.
- Minimum spanning trees.
- Network broadcasting.

---

## 6. Graph Algorithms

1. **Shortest Path Algorithms**

   - **Dijkstra’s Algorithm:** Single-source shortest path (non-negative weights).
   - **Bellman-Ford Algorithm:** Works with negative weights.
   - **Floyd-Warshall Algorithm:** All-pairs shortest path.

2. **Minimum Spanning Tree (MST)**

   - **Prim’s Algorithm**
   - **Kruskal’s Algorithm**

3. **Topological Sort**

   - Ordering of vertices in a DAG.
   - Implemented using DFS or Kahn’s Algorithm (BFS).

4. **Cycle Detection**

   - In **Directed Graph:** DFS + Recursion Stack or Kahn’s Algorithm.
   - In **Undirected Graph:** DFS with parent check or Union-Find.

5. **Disjoint Set Union (DSU/Union-Find)**
   - Efficient structure for handling connectivity queries.
   - Used in Kruskal’s algorithm.

---

## 7. Time & Space Complexity

- **Adjacency Matrix:**
  - Space: `O(V^2)`
  - Traversal: `O(V^2)`
- **Adjacency List:**
  - Space: `O(V + E)`
  - Traversal: `O(V + E)`

---

## 8. Applications of Graphs

- **Social Networks:** Users = nodes, relationships = edges.
- **Maps & Navigation:** Cities = nodes, routes = weighted edges.
- **Computer Networks:** Routers/switches = nodes, connections = edges.
- **Scheduling:** DAG + Topological Sort.
- **Recommendation Systems:** Graph-based similarity.
- **Web Crawling:** Pages = nodes, links = edges.
- **Electric Circuits & Neural Networks:** Graph models.

---

✅ **Quick Summary**

- Graph = (Vertices + Edges).
- Types: Directed, Undirected, Weighted, Unweighted, DAG, Bipartite.
- Representation: Adjacency Matrix, List, Edge List.
- Traversal: BFS, DFS.
- Algorithms: Dijkstra, Bellman-Ford, Floyd-Warshall, Prim, Kruskal, Topological Sort.
- Applications: Social networks, Maps, Scheduling, Networks.


| Feature                       | **Tree**                                                                           | **Graph**                                                          |
| ----------------------------- | ---------------------------------------------------------------------------------- | ------------------------------------------------------------------ |
| **Definition**                | A hierarchical data structure with nodes connected in a parent-child relationship. | A general data structure consisting of nodes (vertices) and edges. |
| **Connectivity**              | Always **connected** (all nodes are reachable).                                    | Can be **connected or disconnected**.                              |
| **Cycles**                    | **No cycles** allowed (acyclic).                                                   | **May contain cycles**.                                            |
| **Direction**                 | Typically a **directed** structure (from parent to child).                         | Can be **directed or undirected**.                                 |
| **Edges**                     | If there are `n` nodes, there are exactly `n - 1` edges.                           | Can have any number of edges (≤ n(n-1)/2 for undirected).          |
| **Parent-Child Relationship** | Every node (except root) has **exactly one parent**.                               | Nodes can have **multiple parents or none**.                       |
| **Root Node**                 | Has a unique **root** node.                                                        | No concept of a root node in general.                              |
| **Traversal Methods**         | BFS, DFS, Preorder, Inorder, Postorder.                                            | BFS and DFS (pre/in/post don’t apply generally).                   |
| **Used in**                   | Hierarchical data (file systems, DOM, org charts).                                 | Networks, maps, web links, social graphs, etc.                     |


### 📌 Summary:

* **All trees are graphs**, but **not all graphs are trees**.
* A **tree is a special kind of graph** that is:

  * Connected,
  * Acyclic,
  * Has exactly `n-1` edges for `n` nodes.

---

### 🧠 Example Analogy:

* **Tree**: Like a **family tree** — each person has one parent (except the root ancestor).
* **Graph**: Like a **social network** — people can be connected in any way, cycles and multiple paths allowed.

---

Let me know if you’d like code comparisons or visual diagrams!