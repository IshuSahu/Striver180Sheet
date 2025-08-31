# 🚀 Dynamic Programming (DP)

---

## 1. **What is Dynamic Programming?**

Dynamic Programming is a **method to solve problems by breaking them into smaller overlapping subproblems, solving each subproblem once, and storing its result (memoization or tabulation) to avoid recomputation.**

* It’s a mix of **Divide & Conquer** + **Memoization**.
* Commonly used when:

  * **Overlapping Subproblems** exist (same problem solved multiple times).
  * **Optimal Substructure** exists (solution can be built using solutions of subproblems).

Example intuition:

* Fibonacci recursion `F(n) = F(n-1) + F(n-2)` recalculates the same subproblems.
* With DP, you compute each Fibonacci once and reuse results → saves exponential time.

---

## 2. **Two Main Approaches**

1. **Top-Down (Memoization)**

   * Start with the big problem → recursively solve subproblems → cache results.
   * Uses recursion + hashmap/array.

   ```cpp
   int fib(int n, vector<int> &dp) {
       if(n <= 1) return n;
       if(dp[n] != -1) return dp[n];
       return dp[n] = fib(n-1, dp) + fib(n-2, dp);
   }
   ```

2. **Bottom-Up (Tabulation)**

   * Iteratively solve small subproblems first → build up to bigger problems.
   * Usually uses a loop with a DP table.

   ```cpp
   int fib(int n) {
       vector<int> dp(n+1, 0);
       dp[0] = 0, dp[1] = 1;
       for(int i=2; i<=n; i++)
           dp[i] = dp[i-1] + dp[i-2];
       return dp[n];
   }
   ```
| Feature              | Top-Down (Memoization)  | Bottom-Up (Tabulation)       |
| -------------------- | ----------------------- | ---------------------------- |
| Style                | Recursive               | Iterative                    |
| Memory usage         | Can be less (if sparse) | Can be optimized (1D arrays) |
| Speed                | Slightly slower         | Often faster                 |
| Easy to write?       | Yes                     | Sometimes no                 |
| Stack overflow risk? | Yes                     | No                           |
| Best when            | Sparse states needed    | All states are needed        |

---

## 3. **When to Use DP?**

Ask yourself:

1. Can the problem be **broken into subproblems**?
2. Do subproblems **overlap** (same smaller problem appears again and again)?
3. Is the problem asking for **min/max/count/ways**? (Typical DP indicators)

Examples of DP problems:

* Fibonacci numbers, climbing stairs, coin change, knapsack, edit distance, longest subsequence problems, matrix path problems.

---

## 4. **Types of DP Problems (Common Patterns)**

💡 Master these patterns, and you’ll crack 90% of DP interview problems.

---

### 4.1 **1D DP (Linear DP)**

Problems where the answer for `i` depends on smaller indices.

* **Climbing Stairs**
* **House Robber**
* **Minimum Cost to Reach End**

---

### 4.2 **2D DP (Grid / Matrix DP)**

Problems where state depends on row/col.

* **Unique Paths**
* **Minimum Path Sum**
* **Knight Moves, Chessboard problems**
* **DP on grids with obstacles**

---

### 4.3 **Knapsack DP (Subset/Partition problems)**

* **0/1 Knapsack** → pick or not pick
* **Unbounded Knapsack** → items can be reused
* **Subset Sum**
* **Partition Equal Subset Sum**
* **Coin Change (min coins or number of ways)**

---

### 4.4 **DP on Subsequences / Strings**

* **Longest Common Subsequence (LCS)**
* **Longest Increasing Subsequence (LIS)**
* **Edit Distance**
* **Palindrome Partitioning**

---

### 4.5 **DP on Intervals**

* When problems depend on **subarrays/substrings**.
* Examples: Matrix Chain Multiplication, Burst Balloons, Palindrome Partitioning II.

---

### 4.6 **DP on Trees/Graphs**

* Tree DP: rerooting techniques, count ways on subtrees.
* Graph DP: shortest path with DP (Bellman-Ford), DAG DP (longest path in DAG).

---

### 4.7 **Bitmask DP**

* Used when subsets of elements are involved.
* Examples: Traveling Salesman Problem (TSP), Assignments problem.

---

## 5. **Steps to Solve Any DP Problem (Template)**

1. **Identify the state:**

   * Define parameters representing the problem.
   * Example: `dp[i] = min cost to reach i`.

2. **Define recurrence relation:**

   * How to compute current state from previous states?
   * Example: `dp[i] = cost[i] + min(dp[i-1], dp[i-2])`.

3. **Base cases:**

   * Handle smallest inputs.

4. **Implementation choice:**

   * Top-down (memoization) or bottom-up (tabulation).

5. **Optimization:**

   * Space optimization: Often `dp[i]` depends only on last 1–2 states → use variables instead of array.

---

## 6. **Classic Examples You Must Master**

1. **Fibonacci (basic DP)**
2. **Climbing Stairs (ways to climb n steps with 1/2 jumps)**
3. **House Robber (cannot rob adjacent houses)**
4. **Coin Change (min coins / number of ways)**
5. **0/1 Knapsack**
6. **Longest Increasing Subsequence (LIS)**
7. **Longest Common Subsequence (LCS)**
8. **Edit Distance (string transformation)**
9. **Matrix Path (min cost / unique paths)**
10. **Partition Equal Subset Sum**
11. **Word Break Problem**

---

## 7. **Common Pitfalls in DP**

* Forgetting base cases.
* Wrong recurrence relation.
* Mixing memoization and tabulation incorrectly.
* High memory usage (optimize space if possible).

---


## 8. **DP Time & Space Complexity**

* Most DP problems are **O(n), O(n^2), O(n\*W), O(2^n \* n)** depending on state size.
* Space often reducible with optimization.

---

## 🔑 Key Takeaway

Dynamic Programming = **Breaking a problem into smaller overlapping subproblems + storing results**.
The real trick: **Identify the state + recurrence relation.** Once you can do that, implementation is mechanical.

---
