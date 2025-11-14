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
# ⚙️ HEAP (Priority Queue) — Pattern Wise Mastery Guide

---

## 🚀 1️⃣ What Is a Heap?

**Definition:**
A **Heap** is a **complete binary tree** where:

* In a **Min-Heap**, each parent ≤ its children
* In a **Max-Heap**, each parent ≥ its children

It’s efficiently implemented using an **array**, and allows:

* Insert: `O(log n)`
* Delete top (min/max): `O(log n)`
* Access top: `O(1)`

**C++ STL:**

```cpp
priority_queue<int> maxHeap; // default max-heap
priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap
```

---

## 🧠 2️⃣ Why Use a Heap?

| Use Case                      | Example                           |
| ----------------------------- | --------------------------------- |
| Find Kth largest/smallest     | Top K problems                    |
| Efficiently merge sorted data | Merge K sorted lists              |
| Scheduling / median stream    | Median of stream, Meeting rooms   |
| Frequency-based tasks         | Reorganize string, Task scheduler |
| Graph algorithms              | Dijkstra’s shortest path          |

---

## 📚 3️⃣ Core Heap Operations

| Operation | Complexity | Description        |
| --------- | ---------- | ------------------ |
| push()    | O(log n)   | Insert element     |
| pop()     | O(log n)   | Remove top element |
| top()     | O(1)       | Get top element    |
| size()    | O(1)       | Number of elements |

---

## 🧩 4️⃣ Heap Patterns Overview

| # | Pattern Name                   | Use Case                     |
| - | ------------------------------ | ---------------------------- |
| 1 | Kth Largest / Smallest Element | Rank-based problems          |
| 2 | Top K Frequent Elements        | Frequency counting           |
| 3 | Merge K Sorted Lists / Arrays  | Multi-list merging           |
| 4 | Sliding Window                 | Maintain max/min over window |
| 5 | Heap + Greedy (Scheduling)     | Job/task allocation          |
| 6 | Heap + Two Heaps (Median)      | Stream median problems       |
| 7 | Custom Comparator Heaps        | Complex sorting logic        |

---

## 🧩 5️⃣ Pattern-Wise Deep Dive

---

### 🧩 **Pattern 1: Kth Largest / Smallest Element**

**When to use:**
Find the Kth smallest/largest number efficiently (better than sorting).

**Approach:**

* **Kth largest** → use *min-heap* of size K
* **Kth smallest** → use *max-heap* of size K

**Steps:**

1. Traverse array
2. Push element to heap
3. If heap size > K → pop()
4. Final heap top = answer

**Example:**

```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int n : nums) {
        minHeap.push(n);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}
```

✅ Example: `[3,2,1,5,6,4], k=2 → 5`

**Practice Problems:**

* [Leetcode 215. Kth Largest Element in Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
* [Kth Smallest Element (GFG)](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/)
* [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

---

### 🧩 **Pattern 2: Top K Frequent Elements**

**When to use:**
You need to find the K most (or least) frequent items.

**Approach:**

* Use hash map to count frequencies
* Use **min-heap** of size K
* Push pairs (freq, element), pop smallest when > K

**Example:**

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int n : nums) freq[n]++;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    for (auto& [num, count] : freq) {
        minHeap.push({count, num});
        if (minHeap.size() > k) minHeap.pop();
    }

    vector<int> ans;
    while (!minHeap.empty()) {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;
}
```

✅ Example: `[1,1,1,2,2,3], k=2 → [1,2]`

**Practice Problems:**

* [Leetcode 347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
* [Leetcode 692. Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)

---

### 🧩 **Pattern 3: Merge K Sorted Lists**

**When to use:**
You have multiple sorted arrays/lists — merge into one sorted output efficiently.

**Approach:**

* Use a **min-heap** to store the smallest current element from each list
* Pop top, push next from same list

**Example:**

```cpp
ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* a, ListNode* b){ return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (auto node : lists) if (node) pq.push(node);

    ListNode dummy(0), *tail = &dummy;
    while (!pq.empty()) {
        auto node = pq.top(); pq.pop();
        tail->next = node; tail = tail->next;
        if (node->next) pq.push(node->next);
    }
    return dummy.next;
}
```

✅ Time: `O(N log k)`, N = total elements

**Practice Problems:**

* [Leetcode 23. Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
* [Merge K Sorted Arrays (GFG)](https://www.geeksforgeeks.org/merge-k-sorted-arrays/)

---

### 🧩 **Pattern 4: Sliding Window with Heap**

**When to use:**
Need the max/min element within every subarray (window) of size K.

**Approach:**

* Use a **max-heap** storing `{value, index}`
* For each element:

  * Push (val, index)
  * Pop until top is within window range
  * Top gives current max

**Example:**

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> pq;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        pq.push({nums[i], i});
        while (pq.top().second <= i - k) pq.pop();
        if (i >= k - 1) res.push_back(pq.top().first);
    }
    return res;
}
```

✅ Example: `[1,3,-1,-3,5,3,6,7], k=3 → [3,3,5,5,6,7]`

**Practice Problems:**

* [Leetcode 239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
* [Leetcode 480. Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)

---

### 🧩 **Pattern 5: Heap + Greedy (Scheduling / Allocation)**

**When to use:**
You need to pick or schedule jobs efficiently based on deadlines or durations.

**Approach:**

* Sort by one parameter (e.g. deadline/start time)
* Use a **min-heap** or **max-heap** to manage active tasks

**Example:**
**Meeting Rooms II**

```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (auto& meeting : intervals) {
        if (!minHeap.empty() && minHeap.top() <= meeting[0])
            minHeap.pop();
        minHeap.push(meeting[1]);
    }
    return minHeap.size();
}
```

✅ Example: `[[0,30],[5,10],[15,20]] → 2`

**Practice Problems:**

* [Leetcode 253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)
* [Leetcode 621. Task Scheduler](https://leetcode.com/problems/task-scheduler/)
* [IPO Problem (Leetcode 502)](https://leetcode.com/problems/ipo/)

---

### 🧩 **Pattern 6: Two Heaps (Median of Stream)**

**When to use:**
Maintain dynamic median in a stream of numbers.

**Approach:**

* Use two heaps:

  * **Max-heap** for left half
  * **Min-heap** for right half
* Balance sizes so difference ≤ 1

**Example:**

```cpp
class MedianFinder {
    priority_queue<int> left; // max-heap
    priority_queue<int, vector<int>, greater<int>> right; // min-heap

public:
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        return left.top();
    }
};
```

✅ **Time:** `O(log n)` per insertion

**Practice Problems:**

* [Leetcode 295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
* [Sliding Window Median (LC 480)](https://leetcode.com/problems/sliding-window-median/)

---

### 🧩 **Pattern 7: Custom Comparator Heap**

**When to use:**
When comparison is **not numeric**, e.g., sort by frequency, string length, distance.

**Example:**
K Closest Points to Origin

```cpp
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto cmp = [](auto& a, auto& b) {
        return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    for (auto& p : points) {
        pq.push(p);
        if (pq.size() > k) pq.pop();
    }
    vector<vector<int>> ans;
    while (!pq.empty()) { ans.push_back(pq.top()); pq.pop(); }
    return ans;
}
```

✅ Example: `[[3,3],[5,-1],[-2,4]], k=2 → [[3,3],[-2,4]]`

**Practice Problems:**

* [Leetcode 973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)
* [Leetcode 451. Sort Characters by Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)

---

## 🧭 6️⃣ Heap Pattern Summary Table

| Pattern           | Heap Type    | Common Use             |
| ----------------- | ------------ | ---------------------- |
| Kth Element       | Min/Max Heap | Rank queries           |
| Top K Frequent    | Min Heap     | Frequency              |
| Merge K Lists     | Min Heap     | Merging streams        |
| Sliding Window    | Max Heap     | Dynamic window stats   |
| Scheduling        | Min Heap     | Allocations            |
| Two Heaps         | Both         | Medians                |
| Custom Comparator | Custom       | Distance/Score sorting |

---

## 🧠 Key Insight:

> Heap ≠ just for sorting.
> It’s for *“always keep track of top K or minimum-cost subset dynamically.”*

---
