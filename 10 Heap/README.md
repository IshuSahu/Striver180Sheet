# Heap Data Structures

## 📘 Introduction

Heaps are a specialized type of **binary tree** used primarily in **priority queues** and **sorting algorithms**. They follow a specific structure and order property but are **not necessarily balanced**.

---

## 🧠 Basic Concepts

- A **Heap** is a complete binary tree.
- It satisfies the **heap property**:
  - In a **Max-Heap**, the parent is greater than its children.
  - In a **Min-Heap**, the parent is smaller than its children.

---

## 🔺 Max-Heap

- The **root element** is greater than all its descendants.
- The heap property must hold for **every node**.

### ✅ Example:

    6
   / \
  3   2

    5
   / \
  4   1

---

## 🔻 Min-Heap

- The **root element** is smaller than all its descendants.
- The heap property must hold for **every node**.

### ✅ Example:

    1
   / \
  3   2

    3
   / \
  4   5

---

## 🔄 Converting Arrays to Heaps

- Insert elements one by one and maintain the heap property via **heapify**.
- **Max-Heapify**: If a child is greater than the parent, swap.
- **Min-Heapify**: If a child is smaller than the parent, swap.

---

## ⚙️ Heap Operations

### 🔹 Insertion

1. Insert at the end of the heap.
2. Compare with the parent.
3. Swap if the heap property is violated.
4. Repeat until the heap is restored.

### 🔹 Deletion

1. Remove the root element.
2. Replace the root with the last element.
3. Perform heapify:
   - Compare with children.
   - Swap with the larger (Max-Heap) or smaller (Min-Heap) child.
   - Repeat until the heap is valid.

---

## 🧪 Example: Heap Operations

### Insertions:
    Insert elements: [5, 10, 3, 2, 7]

---

## 🔹 1. What is a Heap?

A **Heap** is a **complete binary tree** that satisfies the **heap property**.

### ➤ Heap Property

* **Max-Heap** → Every parent node is **greater than or equal to** its children.
  `arr[parent] >= arr[left]` and `arr[parent] >= arr[right]`
* **Min-Heap** → Every parent node is **less than or equal to** its children.
  `arr[parent] <= arr[left]` and `arr[parent] <= arr[right]`

---

## 🔹 2. Representation of Heap

A Heap is **not a separate data structure** like a tree or graph;
it’s **implemented using an array** because of its **complete binary tree** nature.

### ➤ Array Representation Rules

For a node at index `i` (0-based index):

| Node        | Formula       | Explanation          |
| ----------- | ------------- | -------------------- |
| Left Child  | `2*i + 1`     | index of left child  |
| Right Child | `2*i + 2`     | index of right child |
| Parent      | `(i - 1) / 2` | index of parent node |

---

## 🔹 3. Types of Heaps

| Type         | Property                         | Used For                        |
| ------------ | -------------------------------- | ------------------------------- |
| **Max Heap** | Root element is the **largest**  | Priority Queue (default in C++) |
| **Min Heap** | Root element is the **smallest** | Dijkstra, Kth smallest, etc.    |

---

## 🔹 4. Basic Heap Operations (Concept + Time)

| Operation             | Description                         | Time Complexity |
| --------------------- | ----------------------------------- | --------------- |
| **Insertion (push)**  | Add element and heapify up          | `O(log N)`      |
| **Delete root (pop)** | Remove top element and heapify down | `O(log N)`      |
| **Get top**           | Return min or max element           | `O(1)`          |
| **Build heap**        | Convert array into heap             | `O(N)`          |

---

## 🔹 5. Building a Heap (from array)

To build a heap from an array efficiently:

```cpp
for (int i = n/2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
}
```

* **heapify()** ensures subtree rooted at `i` follows heap property.
* Start from the last non-leaf node.

---

## 🔹 6. Heapify — The Core Operation

### 👉 For Max-Heap:

```cpp
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2*i + 1;
    int right = 2*i + 2;

    // If left child > root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child > largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify affected subtree
    }
}
```

Same logic applies for **Min-Heap** (just reverse comparison sign).

---

## 🔹 7. Heap Sort (Using Max-Heap)

**Algorithm:**

1. Build max-heap.
2. Swap root (max) with last element.
3. Reduce heap size by 1.
4. Heapify the root again.

### Example Code:

```cpp
void heapSort(vector<int>& arr, int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Heapify reduced heap
    }
}
```

**Time Complexity:** `O(N log N)`
**Space Complexity:** `O(1)` (in-place)

---

## 🔹 8. C++ STL — Priority Queue

In C++, the **heap** is implemented as a **priority queue**.

---

### ✅ Max-Heap (default behavior)

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);

    cout << maxHeap.top(); // 20

    maxHeap.pop(); // removes 20
}
```

---

### ✅ Min-Heap (using greater comparator)

```cpp
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    cout << minHeap.top(); // 5

    minHeap.pop(); // removes 5
}
```

---

### ✅ Min-Heap for custom objects

Suppose we have a pair `{distance, node}` (like in Dijkstra):

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
```
---

## 🔹 10. Common Syntax You Must Know in C++

| Operation | Max-Heap                  | Min-Heap                                             |
| --------- | ------------------------- | ---------------------------------------------------- |
| Declare   | `priority_queue<int> pq;` | `priority_queue<int, vector<int>, greater<int>> pq;` |
| Push      | `pq.push(x);`             | `pq.push(x);`                                        |
| Pop       | `pq.pop();`               | `pq.pop();`                                          |
| Top       | `pq.top();`               | `pq.top();`                                          |
| Size      | `pq.size();`              | `pq.size();`                                         |
| Empty     | `pq.empty();`             | `pq.empty();`                                        |

---

## 🔹 11. Custom Comparator (For Objects / Pair Sorting)

### Example:

Suppose we have a pair `{val, freq}` and want **max freq first**.

```cpp
struct Compare {
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.second < b.second; // max heap by frequency
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
```

---

## 🔹 12. Internal Working (for Interview)

* Heaps are implemented using **arrays**.
* `push()` → inserts element at the end → performs **heapify up** (log N).
* `pop()` → swaps root with last → deletes → performs **heapify down** (log N).
* In STL, `priority_queue` internally uses `std::make_heap`, `std::push_heap`, and `std::pop_heap`.

---

## 🔹 13. Time Complexities Summary

| Operation       | Average  | Worst    | Notes |
| --------------- | -------- | -------- | ----- |
| Insert          | O(log N) | O(log N) |       |
| Extract Max/Min | O(log N) | O(log N) |       |
| Peek (Top)      | O(1)     | O(1)     |       |
| Build Heap      | O(N)     | O(N)     |       |

---

## 🔹 14. Key Interview Notes

1. **Heap is not sorted**, only the root satisfies order property.
2. **Heaps vs BST**:

   * BST can give sorted order traversal → `O(N)`
   * Heap gives **top element quickly**, not sorted order.
3. **STL Tip:** For large datasets or when sorting is not needed, heaps are faster than sorting for top-k problems.

---
