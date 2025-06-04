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