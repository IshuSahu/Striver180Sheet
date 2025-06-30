# B-Tree

A **B-tree** is a self-balancing tree data structure that maintains sorted data and allows for efficient searching, insertion, and deletion. It is widely used in database systems, file systems, and storage systems due to its ability to handle large data efficiently.

## Key Concepts

- **Balanced Structure**: All leaf nodes are at the same level, ensuring that the tree remains balanced and operations are fast.
- **Multi-way Tree**: Each node can have multiple children, which allows for faster operations with large datasets.
- **Order of B-tree**: A B-tree of order *m* allows each node to have at most *m* children and *m-1* keys.

## B-Tree Properties

- **Root Node**: The root node can have fewer children, but it must have at least two if it’s not a leaf.
- **Node Capacity**: Each node can have between *⌈m/2⌉* and *m* children.
- **Balanced Height**: All leaf nodes are at the same level, which ensures that the height of the tree is minimal, making search operations efficient.

## Operations

### 1. Search Operation
- Time Complexity: **O(log n)**
- Search proceeds by comparing the target key with the keys in the current node and traversing down the appropriate child node.

### 2. Insertion Operation
- Time Complexity: **O(log n)**
- Insertion starts at the root. If a node exceeds its capacity after insertion, it splits into two nodes, and the middle key is pushed to the parent. This process may propagate up to the root.

### 3. Deletion Operation
- Time Complexity: **O(log n)**
- Deletion involves finding and removing a key. If a node underflows (i.e., has fewer than the minimum number of keys), it may borrow a key from a sibling or merge with a sibling.

## B+ Tree

A **B+ Tree** is a variation of the B-tree where all values are stored in the leaf nodes, and the internal nodes only store keys. This allows for efficient range queries, making it useful in databases and file systems.

## Advantages of B-Trees

- **Efficient Search**: With a height of O(log n), search operations are fast, even for large datasets.
- **Efficient Disk I/O**: Due to the multi-way nature, fewer disk accesses are required when reading large blocks of data from storage.
- **Self-Balancing**: The tree remains balanced after every operation, ensuring optimal performance.

## Applications

- **Databases**: B-trees are commonly used in databases (e.g., MySQL, PostgreSQL) for indexing.
- **File Systems**: File systems like NTFS and HFS use B-trees to organize files and directories efficiently.
