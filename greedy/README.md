## 🚀 1️⃣ What Is the Greedy Algorithm?

**Definition:**
A **Greedy algorithm** builds up a solution step by step,
**always choosing the locally optimal choice at each step** —
hoping that these choices lead to a globally optimal solution.

**Key Idea:**

> “At each step, do what looks best right now.”

**Time Complexity:** Usually `O(n log n)` (due to sorting or heap operations).

---

## 🧠 2️⃣ When to Apply Greedy

A problem is solvable by Greedy if it satisfies:

1. **Greedy Choice Property:**
   A global optimum can be arrived at by choosing a local optimum.
2. **Optimal Substructure:**
   A global solution can be built from optimal solutions of subproblems.

**Common Signs:**

* You’re asked to **maximize/minimize** something (profit, distance, cost).
* There’s **sorting involved** based on ratio, value, or finishing time.
* A **“pick or skip”** decision occurs at each step.

---

## 📚 3️⃣ Major Greedy Algorithm Patterns

| #  | Pattern                                    | Core Idea                                   |
| -- | ------------------------------------------ | ------------------------------------------- |
| 1  | Interval Scheduling                        | Select maximum compatible intervals         |
| 2  | Minimum Platforms / Merge Intervals        | Handle overlapping intervals                |
| 3  | Fractional Knapsack                        | Choose max profit per weight ratio          |
| 4  | Huffman Coding / File Merge                | Merge smallest two elements iteratively     |
| 5  | Job Sequencing                             | Assign jobs for max profit within deadlines |
| 6  | Minimum Spanning Tree (Prim’s / Kruskal’s) | Choose smallest edge safely                 |
| 7  | Dijkstra’s Shortest Path                   | Always pick nearest node                    |
| 8  | Coin Change / Activity Selection           | Pick highest value that fits                |
| 9  | Gas Station / Jump Game / Candy            | Local forward optimization problems         |
| 10 | Scheduling / CPU Allocation                | Optimize based on time, deadlines, etc.     |

---

## 🧩 4️⃣ Pattern-Wise Deep Dive

---

### 🧩 **Pattern 1: Interval Scheduling (Non-overlapping Intervals)**

**When to use:**
Select maximum number of non-overlapping activities/meetings.

**Steps:**

1. Sort intervals by **ending time**.
2. Always pick the interval that **ends earliest** and doesn’t overlap with the last picked one.
3. Count total picked.

**Example:**

```cpp
int maxMeetings(vector<pair<int,int>>& meetings) {
    sort(meetings.begin(), meetings.end(), [](auto& a, auto& b){ return a.second < b.second; });
    int count = 1, end = meetings[0].second;
    for (int i = 1; i < meetings.size(); i++) {
        if (meetings[i].first > end) {
            count++;
            end = meetings[i].second;
        }
    }
    return count;
}
```

✅ Example:
Meetings = `[(1,2),(3,4),(0,6),(5,7),(8,9),(5,9)]`
→ Output: `4` (Meetings: (1,2), (3,4), (5,7), (8,9))

**Practice Problems:**

* [N Meetings in One Room (GFG)](https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/)
* [Leetcode 435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

---

### 🧩 **Pattern 2: Merge Intervals / Minimum Platforms**

**When to use:**
Intervals overlap and you must find merged or maximum overlaps.

**Steps:**

1. Sort intervals by start time.
2. Merge if overlapping, else add new interval.

**Example:**

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (auto& it : intervals) {
        if (merged.empty() || merged.back()[1] < it[0])
            merged.push_back(it);
        else
            merged.back()[1] = max(merged.back()[1], it[1]);
    }
    return merged;
}
```

✅ Example: `[[1,3],[2,6],[8,10],[15,18]] → [[1,6],[8,10],[15,18]]`

**Practice Problems:**

* [Leetcode 56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)
* [GFG. Minimum Number of Platforms](https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/)

---

### 🧩 **Pattern 3: Fractional Knapsack Problem**

**When to use:**
Maximize total value with weight capacity constraint.
You can take fractions of items.

**Steps:**

1. Compute value/weight ratio.
2. Sort items by this ratio (descending).
3. Pick full items until capacity is full.
4. Take fraction if not enough capacity left.

**Example:**

```cpp
struct Item { int value, weight; };

double fractionalKnapsack(int W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), [](Item a, Item b){
        return (double)a.value/a.weight > (double)b.value/b.weight;
    });
    double totalValue = 0.0;
    for (auto& it : arr) {
        if (W >= it.weight) {
            totalValue += it.value;
            W -= it.weight;
        } else {
            totalValue += it.value * ((double)W / it.weight);
            break;
        }
    }
    return totalValue;
}
```

✅ Example:
Weights = `[10,20,30]`, Values = `[60,100,120]`, W=50 → `240`

**Practice Problems:**

* [GFG. Fractional Knapsack](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/)

---

### 🧩 **Pattern 4: Huffman Coding / File Merge Cost**

**When to use:**
Combine elements (like merging files or building prefix codes) with minimal cost.

**Steps:**

1. Use a **min-heap** to store frequencies.
2. Repeatedly take two smallest, merge them, and push back their sum.
3. Total cost = sum of all merges.

**Example:**

```cpp
int minCost(vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> pq(files.begin(), files.end());
    int cost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}
```

✅ Example: `[4,3,2,6] → 29`

**Practice Problems:**

* [GFG. Minimum Cost of Connecting Ropes](https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/)
* Huffman Encoding (GFG)

---

### 🧩 **Pattern 5: Job Sequencing with Deadlines**

**When to use:**
Each job has a profit and a deadline. You can do 1 job per day before its deadline → maximize profit.

**Steps:**

1. Sort jobs by profit (descending).
2. Use an array to track available slots.
3. For each job, schedule it in latest free slot before deadline.

**Example:**

```cpp
struct Job { int id, deadline, profit; };

int jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), [](auto& a, auto& b){ return a.profit > b.profit; });
    int maxD = 0; for (auto& j : jobs) maxD = max(maxD, j.deadline);
    vector<int> slot(maxD + 1, -1);
    int totalProfit = 0;
    for (auto& j : jobs) {
        for (int d = j.deadline; d > 0; d--) {
            if (slot[d] == -1) { slot[d] = j.id; totalProfit += j.profit; break; }
        }
    }
    return totalProfit;
}
```

✅ Example: Jobs = `{(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,3,15)} → Profit=142`

**Practice Problems:**

* [GFG. Job Sequencing Problem](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/)

---

### 🧩 **Pattern 6: Minimum Spanning Tree (Kruskal’s / Prim’s)**

**When to use:**
Connect all vertices with **minimum total edge cost**.

* **Kruskal’s:** Sort edges by weight, use Disjoint Set (Union-Find).
* **Prim’s:** Use min-heap, expand from a node.

**Example (Kruskal):**

```cpp
int find(int x, vector<int>& parent){ return parent[x]==x ? x : parent[x]=find(parent[x],parent); }

int kruskal(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a[2] < b[2]; });
    vector<int> parent(n); iota(parent.begin(), parent.end(), 0);
    int cost = 0, count = 0;
    for (auto& e : edges) {
        int u=find(e[0],parent), v=find(e[1],parent);
        if(u!=v){ cost += e[2]; parent[u]=v; count++; }
        if(count==n-1) break;
    }
    return cost;
}
```

**Practice Problems:**

* [GFG. Kruskal’s MST](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1)
* [Leetcode 1135. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)

---

### 🧩 **Pattern 7: Dijkstra’s Algorithm (Shortest Path)**

**When to use:**
Find the **minimum distance** from a source to all other nodes (non-negative weights).

**Steps:**

1. Use a **min-heap** for `(distance, node)`.
2. Keep relaxing edges with smallest distance first.

**Example:**

```cpp
vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, 1e9); dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        for (auto [v,w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

**Practice Problems:**

* [GFG. Dijkstra’s Algorithm](https://practice.geeksforgeeks.org/problems/dijkstra-algorithm/1)
* [Leetcode 743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)

---

### 🧩 **Pattern 8: Coin Change (Greedy Variant)**

**When to use:**
Currency denominations follow a canonical system (e.g., Indian coins 1,2,5,10,20,50,...).

**Steps:**

1. Sort denominations descending.
2. Pick largest coin ≤ remaining amount.
3. Repeat until total reached.

**Example:**

```cpp
int minCoins(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;
    for (int c : coins) {
        count += amount / c;
        amount %= c;
    }
    return count;
}
```

✅ Example: Amount = 49, Coins = `[25,10,5,1] → 7 (25+10+10+1+1+1+1)`

**Practice Problems:**

* [GFG. Minimum Coins to Make Value](https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/)
* [Leetcode 860. Lemonade Change](https://leetcode.com/problems/lemonade-change/)

---

### 🧩 **Pattern 9: Jump Game / Gas Station / Candy**

**When to use:**
Array traversal problems where you must make local optimal jumps or allocations.

**Example: Jump Game II**

```cpp
int jump(vector<int>& nums) {
    int jumps = 0, end = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == end) {
            jumps++;
            end = farthest;
        }
    }
    return jumps;
}
```

✅ Example: `[2,3,1,1,4] → 2`

**Practice Problems:**

* [Leetcode 55. Jump Game](https://leetcode.com/problems/jump-game/)
* [Leetcode 134. Gas Station](https://leetcode.com/problems/gas-station/)
* [Leetcode 135. Candy](https://leetcode.com/problems/candy/)

---

## 🧭 5️⃣ Greedy Pattern Summary Table

| Pattern              | Core Technique       | Problem Type          |
| -------------------- | -------------------- | --------------------- |
| Interval Scheduling  | Sort by end time     | Maximize tasks        |
| Merge Intervals      | Sort by start        | Overlap merge         |
| Fractional Knapsack  | Sort by ratio        | Maximize profit       |
| Huffman / Rope Merge | Min-heap             | Min cost              |
| Job Sequencing       | Sort by profit       | Max profit scheduling |
| MST (Kruskal/Prim)   | Union-Find / Heap    | Min edge connection   |
| Dijkstra             | Relax shortest       | Min distance          |
| Coin Change          | Largest-first pick   | Min coins             |
| Jump / Gas Station   | Local forward choice | Min steps, min gas    |

---

## 🧩 6️⃣ Practice Roadmap

**🟢 Beginner**

* Activity Selection Problem (GFG)
* Fractional Knapsack (GFG)
* Minimum Coins (GFG)

**🟡 Intermediate**

* Merge Intervals (LC 56)
* Non-overlapping Intervals (LC 435)
* Lemonade Change (LC 860)
* Jump Game II (LC 45)

**🔴 Advanced**

* Job Sequencing Problem (GFG)
* Minimum Cost to Connect Ropes (GFG)
* Dijkstra / Kruskal MST
* Gas Station (LC 134)
* Candy Distribution (LC 135)

---

## 🧠 Key Insight:

> Greedy = “Sort + Pick Best Feasible Option at Each Step”
> Always think: *Can the local best lead to the global best?*

---
