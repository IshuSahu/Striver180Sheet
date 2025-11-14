# 🌀 **Recursion & Backtracking — Pattern Wise Mastery Guide**

## 🚀 1️⃣ What Is Recursion?

**Definition:**
Recursion is when a function calls itself to solve smaller subproblems.
Each recursive call reduces the problem size until a **base condition** stops further calls.

**3 Pillars of Recursion:**

1. **Base Case:** Stops recursion
2. **Recursive Case:** Defines smaller subproblem
3. **Progress:** Moves toward base case

**Example:**

```cpp
int factorial(int n) {
    if (n == 0) return 1;       // Base Case
    return n * factorial(n-1);  // Recursive Case
}
```

---

## 🧠 2️⃣ What Is Backtracking?

**Definition:**
Backtracking = *Recursion + Undo (Backtrack)*
Used when you must **explore all possible solutions** (like paths, combinations, boards)
and **revert** to previous state after trying one option.

**Steps:**

1. Choose (make a move)
2. Explore (recursive call)
3. Unchoose (undo the move)

---

## 📚 3️⃣ Common Recursion & Backtracking Patterns

| #  | Pattern                     | Core Concept                   | Example                   |
| -- | --------------------------- | ------------------------------ | ------------------------- |
| 1  | Subset / Power Set          | Choose or skip each element    | Subsets, Subsequences     |
| 2  | Permutations                | Fix one position and swap      | All arrangements          |
| 3  | Combination Sum             | Pick elements with constraints | Sum/Target generation     |
| 4  | N-Queens / Sudoku           | Place items under constraints  | Board-based recursion     |
| 5  | Rat in a Maze / Paths       | Explore all valid directions   | Pathfinding               |
| 6  | String Recursion            | Build substrings recursively   | Palindrome, Letter Case   |
| 7  | Recursion on Trees          | Divide by subproblems          | Traversals                |
| 8  | Recursion on Numbers        | Mathematical recursion         | Tower of Hanoi, Fibonacci |
| 9  | Decision Tree / State Space | Backtrack based on state       | Word Search, Knight Tour  |
| 10 | Constraint Backtracking     | Pruning invalid paths          | N-Queens, Sudoku          |

---

## 🧩 4️⃣ Pattern-Wise Deep Dive

---

### 🧩 **Pattern 1: Subset / Power Set Generation**

**When to use:**
You must generate all combinations by either **including or excluding** each element.

**Steps:**

1. Start from index 0.
2. At each step — either **include** or **exclude** the current element.
3. Add the subset when index == n.

**Example:**

```cpp
void solve(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& ans) {
    if (i == nums.size()) { ans.push_back(cur); return; }
    // include
    cur.push_back(nums[i]);
    solve(nums, i+1, cur, ans);
    // exclude
    cur.pop_back();
    solve(nums, i+1, cur, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans; vector<int> cur;
    solve(nums, 0, cur, ans);
    return ans;
}
```

✅ Example: `[1,2,3] → [[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]`

**Practice Problems:**

* [Leetcode 78. Subsets](https://leetcode.com/problems/subsets/)
* [Leetcode 90. Subsets II](https://leetcode.com/problems/subsets-ii/)

---

### 🧩 **Pattern 2: Permutations**

**When to use:**
You need **all possible orderings** of elements.

**Steps:**

1. Fix one element at a time (swap).
2. Recursively permute the rest.
3. Swap back (backtrack).

**Example:**

```cpp
void permuteRec(vector<int>& nums, int i, vector<vector<int>>& ans) {
    if (i == nums.size()) { ans.push_back(nums); return; }
    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        permuteRec(nums, i+1, ans);
        swap(nums[i], nums[j]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    permuteRec(nums, 0, ans);
    return ans;
}
```

✅ Example: `[1,2,3] → [123,132,213,231,312,321]`

**Practice Problems:**

* [Leetcode 46. Permutations](https://leetcode.com/problems/permutations/)
* [Leetcode 47. Permutations II](https://leetcode.com/problems/permutations-ii/)

---

### 🧩 **Pattern 3: Combination Sum**

**When to use:**
You must find all combinations of elements that **sum to a target** (with/without repetition).

**Steps:**

1. Use recursion with index and remaining target.
2. At each step — pick current number (can reuse) or move to next.
3. Stop when target == 0 (valid combination).

**Example:**

```cpp
void solve(int i, int target, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
    if (target == 0) { ans.push_back(cur); return; }
    if (i == nums.size() || target < 0) return;
    // pick
    cur.push_back(nums[i]);
    solve(i, target - nums[i], nums, cur, ans);
    cur.pop_back();
    // skip
    solve(i+1, target, nums, cur, ans);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> ans; vector<int> cur;
    solve(0, target, nums, cur, ans);
    return ans;
}
```

✅ Example: `[2,3,6,7], target=7 → [[2,2,3],[7]]`

**Practice Problems:**

* [Leetcode 39. Combination Sum](https://leetcode.com/problems/combination-sum/)
* [Leetcode 40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

---

### 🧩 **Pattern 4: N-Queens Problem**

**When to use:**
You need to place N queens on a board so that no two attack each other.

**Steps:**

1. Place one queen per row.
2. Before placing, check if the column/diagonal is safe.
3. If valid → recurse for next row.
4. Backtrack if no placement possible.

**Example:**

```cpp
bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i=0; i<row; i++) if (board[i][col]=='Q') return false;
    for (int i=row-1,j=col-1;i>=0&&j>=0;i--,j--) if (board[i][j]=='Q') return false;
    for (int i=row-1,j=col+1;i>=0&&j<n;i--,j++) if (board[i][j]=='Q') return false;
    return true;
}

void solve(int row, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (row == n) { ans.push_back(board); return; }
    for (int col=0; col<n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row+1, board, ans, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}
```

✅ Example: `n=4` → 2 valid configurations

**Practice Problems:**

* [Leetcode 51. N-Queens](https://leetcode.com/problems/n-queens/)
* [Leetcode 52. N-Queens II](https://leetcode.com/problems/n-queens-ii/)

---

### 🧩 **Pattern 5: Rat in a Maze / Pathfinding**

**When to use:**
Find all valid paths from source → destination by moving in allowed directions.

**Steps:**

1. Move only if next cell is safe (within bounds and not visited).
2. Mark cell visited → recurse → unmark.

**Example:**

```cpp
void dfs(int i, int j, vector<vector<int>>& maze, int n, string path, vector<string>& ans) {
    if (i==n-1 && j==n-1) { ans.push_back(path); return; }
    string dir = "DLRU";
    vector<int> di = {1,0,0,-1}, dj = {0,-1,1,0};
    for (int k=0;k<4;k++) {
        int ni=i+di[k], nj=j+dj[k];
        if (ni>=0 && nj>=0 && ni<n && nj<n && maze[ni][nj]==1) {
            maze[ni][nj]=0;
            dfs(ni,nj,maze,n,path+dir[k],ans);
            maze[ni][nj]=1; // backtrack
        }
    }
}

vector<string> findPath(vector<vector<int>>& maze, int n) {
    vector<string> ans;
    if(maze[0][0]==0) return ans;
    maze[0][0]=0;
    dfs(0,0,maze,n,"",ans);
    return ans;
}
```

✅ Example: All paths from `(0,0)` → `(n-1,n-1)`

**Practice Problems:**

* [GFG. Rat in a Maze](https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)
* [Leetcode 79. Word Search](https://leetcode.com/problems/word-search/)

---

### 🧩 **Pattern 6: String / Subsequence Recursion**

**When to use:**
Generate all subsequences or modify strings recursively.

**Example:**

```cpp
void generate(string s, int i, string cur, vector<string>& ans) {
    if (i == s.size()) { ans.push_back(cur); return; }
    // exclude
    generate(s, i+1, cur, ans);
    // include
    generate(s, i+1, cur + s[i], ans);
}
```

✅ Example: `"abc" → ["", "a", "b", "c", "ab", "ac", "bc", "abc"]`

**Practice Problems:**

* [Leetcode 22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
* [Leetcode 17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

---

### 🧩 **Pattern 7: Backtracking with Pruning**

**When to use:**
You can eliminate impossible branches early.

**Example:** *Sudoku Solver*

```cpp
bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
    for(int i=0;i<9;i++) if(board[i][c]==ch||board[r][i]==ch) return false;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++)
        if(board[r/3*3+i][c/3*3+j]==ch) return false;
    return true;
}

bool solve(vector<vector<char>>& board) {
    for(int i=0;i<9;i++) for(int j=0;j<9;j++)
        if(board[i][j]=='.'){
            for(char ch='1';ch<='9';ch++){
                if(isValid(board,i,j,ch)){
                    board[i][j]=ch;
                    if(solve(board)) return true;
                    board[i][j]='.';
                }
            }
            return false;
        }
    return true;
}
```

✅ Example: Sudoku grid solved fully

**Practice Problems:**

* [Leetcode 37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)

---

## 🧭 5️⃣ Recursion & Backtracking Pattern Summary

| Pattern              | Core Concept        | Common Questions |
| -------------------- | ------------------- | ---------------- |
| Subset / Power Set   | Choose/Skip         | LC 78, 90        |
| Permutations         | Swap elements       | LC 46, 47        |
| Combination Sum      | Include/Exclude     | LC 39, 40        |
| N-Queens             | Place safely        | LC 51            |
| Maze / Paths         | Explore + Backtrack | GFG Maze, LC 79  |
| String / Subsequence | Build substrings    | LC 22, 17        |
| Sudoku / Constraints | Backtrack + prune   | LC 37            |

---

## 🧩 6️⃣ Practice Roadmap

**🟢 Beginner**

* LC 509: Fibonacci (Recursion)
* LC 78: Subsets
* LC 46: Permutations

**🟡 Intermediate**

* LC 39: Combination Sum
* LC 22: Generate Parentheses
* LC 79: Word Search
* GFG: Rat in a Maze

**🔴 Advanced**

* LC 51: N-Queens
* LC 37: Sudoku Solver
* LC 212: Word Search II
* LC 93: Restore IP Addresses

---

## 🧠 Key Insight:

> **Recursion explores all possibilities.**
> **Backtracking cuts off impossible ones.**

🧩 Think of recursion as a **tree** —
each node is a decision,
and backtracking is the **path reversal** after exploring a branch.

---

Would you like me to move next to **Dynamic Programming Patterns** (DP Roadmap)?
It’s the *next natural step* after recursion — since DP = optimized recursion.
