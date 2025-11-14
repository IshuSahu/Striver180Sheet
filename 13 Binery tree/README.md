# 🌳 **Binary Tree — Pattern Wise Mastery Guide**

---

## 🚀 1️⃣ What Is a Binary Tree?

A **Binary Tree** is a hierarchical data structure where
each node has **at most two children** — `left` and `right`.

**Types:**

| Type                     | Description                            |
| ------------------------ | -------------------------------------- |
| Full Binary Tree         | Every node has 0 or 2 children         |
| Complete Binary Tree     | All levels filled except possibly last |
| Perfect Binary Tree      | All levels completely filled           |
| Balanced Binary Tree     | Height difference ≤ 1 for all subtrees |
| BST (Binary Search Tree) | Left < Root < Right                    |

---

## 🧠 2️⃣ When to Apply Binary Trees

You’ll use trees when:

* The problem involves **hierarchical data**, **recursive structure**, or **relationships** (like parent-child).
* The question asks about **height, depth, diameter, path sum, boundary, or traversal order**.
* You see **recursive** relationships in subproblems.

---

## 🧩 3️⃣ Major Binary Tree Patterns

| #  | Pattern                                       | Core Use                       |
| -- | --------------------------------------------- | ------------------------------ |
| 1  | DFS Traversals (Inorder, Preorder, Postorder) | Visit all nodes                |
| 2  | BFS Traversal / Level Order                   | Visit level by level           |
| 3  | Height / Depth Calculation                    | Measure structure              |
| 4  | Diameter / Longest Path                       | Longest distance between nodes |
| 5  | Root-to-Leaf Path / Path Sum                  | Path-based recursion           |
| 6  | Lowest Common Ancestor (LCA)                  | Find meeting point             |
| 7  | Symmetric / Mirror Tree                       | Structure comparison           |
| 8  | Tree Construction (From Traversals)           | Rebuild tree                   |
| 9  | Boundary / Zigzag / Vertical Traversals       | Specialized BFS variants       |
| 10 | Serialize / Deserialize Tree                  | Store and reconstruct tree     |

---

## 🔍 4️⃣ How to Identify Each Pattern

| Problem Phrase                                  | Likely Pattern        |
| ----------------------------------------------- | --------------------- |
| “Print nodes in inorder / preorder / postorder” | DFS Traversal         |
| “Level by level traversal”                      | BFS / Level Order     |
| “Maximum depth / height”                        | DFS (postorder)       |
| “Longest path between any two nodes”            | Diameter Pattern      |
| “Path with target sum”                          | Root-to-Leaf Path     |
| “Find common ancestor”                          | LCA                   |
| “Check if two trees same/symmetric”             | Recursive comparison  |
| “Build tree from traversal”                     | Construction Pattern  |
| “Boundary / Spiral order”                       | Modified BFS          |
| “Convert to/from string”                        | Serialize/Deserialize |

---

## 🧭 5️⃣ Pattern-Wise Deep Dive

---

### 🧩 **Pattern 1: DFS Traversals**

**When to use:**
For recursive processing (visit all nodes in specific order).

**Types:**

1. **Inorder (L → Root → R)** — BST sorted order
2. **Preorder (Root → L → R)** — Useful for copy/serialization
3. **Postorder (L → R → Root)** — Useful for delete or height calc

**Example (Inorder Traversal):**

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

✅ **Example:**
Input: 1
  / \
 2  3
Output: `2 1 3`

**Practice Problems:**

* [LC 94. Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [LC 144. Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
* [LC 145. Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

---

### 🧩 **Pattern 2: BFS / Level Order Traversal**

**When to use:**
Level-by-level processing (e.g., sum at each level, find depth).

**Steps:**

1. Use a queue
2. Push root, process all nodes of same level before next

**Example:**

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        vector<int> level;
        for(int i=0;i<sz;i++){
            auto node = q.front(); q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}
```

✅ **Example:**
Input: `[3,9,20,null,null,15,7]`
Output: `[[3],[9,20],[15,7]]`

**Practice Problems:**

* [LC 102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [LC 107. Bottom-Up Level Order](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

---

### 🧩 **Pattern 3: Height / Depth of Tree**

**When to use:**
Measure how deep or tall the tree is.

**Recursive Formula:**
`height = 1 + max(leftHeight, rightHeight)`

```cpp
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

✅ **Example:**
Input: `[3,9,20,null,null,15,7]` → Output: `3`

**Practice Problems:**

* [LC 104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
* [LC 110. Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

---

### 🧩 **Pattern 4: Diameter / Longest Path**

**When to use:**
Find the longest distance between any two nodes.

**Steps:**

1. Use postorder recursion
2. Track height of each subtree
3. `diameter = max(leftHeight + rightHeight)`

```cpp
int dfs(TreeNode* root, int& dia) {
    if(!root) return 0;
    int l = dfs(root->left, dia);
    int r = dfs(root->right, dia);
    dia = max(dia, l+r);
    return 1 + max(l,r);
}

int diameterOfBinaryTree(TreeNode* root) {
    int dia=0;
    dfs(root, dia);
    return dia;
}
```

✅ **Example:**
Input: `[1,2,3,4,5]` → Output: `3`

**Practice Problems:**

* [LC 543. Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

---

### 🧩 **Pattern 5: Root-to-Leaf Path / Path Sum**

**When to use:**
Find paths or sums from root to leaf.

**Steps:**

1. DFS down the tree
2. Maintain running sum or path
3. Backtrack when reaching a leaf

```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root) return false;
    if(!root->left && !root->right) return root->val == targetSum;
    return hasPathSum(root->left, targetSum - root->val)
        || hasPathSum(root->right, targetSum - root->val);
}
```

✅ **Example:**
Tree: `[5,4,8,11,null,13,4,7,2,null,null,null,1]`, target = 22 → `true`

**Practice Problems:**

* [LC 112. Path Sum](https://leetcode.com/problems/path-sum/)
* [LC 113. Path Sum II](https://leetcode.com/problems/path-sum-ii/)
* [LC 257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)

---

### 🧩 **Pattern 6: Lowest Common Ancestor (LCA)**

**When to use:**
Find first common node where two nodes meet.

**Recursive Rule:**
If one node is in left subtree and the other in right → current is LCA.

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root==p || root==q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    return left ? left : right;
}
```

✅ **Example:**
LCA of 5 and 1 in `[3,5,1,6,2,0,8]` → `3`

**Practice Problems:**

* [LC 236. Lowest Common Ancestor](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

---

### 🧩 **Pattern 7: Symmetric / Mirror Tree**

```cpp
bool isMirror(TreeNode* a, TreeNode* b) {
    if(!a || !b) return a==b;
    return (a->val==b->val)
        && isMirror(a->left,b->right)
        && isMirror(a->right,b->left);
}

bool isSymmetric(TreeNode* root) {
    return isMirror(root->left, root->right);
}
```

✅ Example: `[1,2,2,3,4,4,3]` → `true`

**Practice Problems:**

* [LC 101. Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)
* [LC 100. Same Tree](https://leetcode.com/problems/same-tree/)

---

### 🧩 **Pattern 8: Tree Construction (From Traversals)**

**When to use:**
You’re given two traversal arrays — rebuild the tree.

**Steps:**

1. Preorder’s first element = root
2. Split inorder into left/right subtrees
3. Recursively build

```cpp
TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int l, int r, unordered_map<int,int>& pos) {
    if(l>r) return nullptr;
    int rootVal = preorder[idx++];
    TreeNode* root = new TreeNode(rootVal);
    root->left = build(preorder, inorder, idx, l, pos[rootVal]-1, pos);
    root->right = build(preorder, inorder, idx, pos[rootVal]+1, r, pos);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> pos;
    for(int i=0;i<inorder.size();i++) pos[inorder[i]]=i;
    int idx=0;
    return build(preorder,inorder,idx,0,inorder.size()-1,pos);
}
```

**Practice Problems:**

* [LC 105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

---

### 🧩 **Pattern 9: Boundary / Zigzag / Vertical Traversal**

**When to use:**
Print nodes in special traversal orders.

**Examples:**

* Boundary Traversal → left boundary + leaves + right boundary
* Zigzag Level Order → alternate direction per level
* Vertical Order → column-based BFS

**Practice Problems:**

* [LC 103. Zigzag Level Order](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
* [LC 987. Vertical Order Traversal](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)

---

### 🧩 **Pattern 10: Serialize / Deserialize Tree**

**When to use:**
Convert tree to string or rebuild from string (used in file transfer / cloning).

```cpp
string serialize(TreeNode* root) {
    if(!root) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

TreeNode* deserialize(queue<string>& q) {
    string val=q.front(); q.pop();
    if(val=="#") return nullptr;
    TreeNode* root = new TreeNode(stoi(val));
    root->left = deserialize(q);
    root->right = deserialize(q);
    return root;
}
```

**Practice Problems:**

* [LC 297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

---

## 🧾 6️⃣ Binary Tree Pattern Summary

| Pattern           | Core Idea             | Typical Use            |
| ----------------- | --------------------- | ---------------------- |
| DFS Traversal     | Recursive Visit       | Inorder, Pre, Post     |
| BFS Traversal     | Queue-based           | Level order            |
| Height            | Depth calc            | Balanced check         |
| Diameter          | Longest path          | Distance measure       |
| Path Sum          | Root to leaf sum      | Sum checks             |
| LCA               | Subtree recursion     | Ancestor               |
| Symmetric         | Mirror recursion      | Structure check        |
| Construction      | Build from traversals | Rebuild tree           |
| Boundary / Zigzag | Specialized BFS       | Custom traversal       |
| Serialize         | Stringify             | Transfer or store tree |

---

## 🧩 7️⃣ Practice Roadmap

**🟢 Beginner**

* Inorder / Preorder / Postorder Traversal
* Max Depth of Binary Tree
* Symmetric Tree

**🟡 Intermediate**

* Level Order Traversal
* Path Sum
* Diameter of Binary Tree
* LCA

**🔴 Advanced**

* Construct Tree from Traversals
* Serialize / Deserialize Binary Tree
* Vertical Order Traversal
* Boundary Traversal

---

## 💡 Key Insight

> Every tree problem reduces to **“what do I return to the parent?”**
>
> 🔹 Use **DFS recursion** for most problems
> 🔹 Use **BFS queue** for level-based logic
> 🔹 Track **postorder results** for global properties (height, diameter, etc.)

---