# 📘 Stacks & Queues in C++ – Explained with Notes

> Quick but clear explanations of all key concepts, with short code examples and reasoning.

---

## 🧠 What is a Stack?

- **Definition**: A linear data structure that follows **LIFO** – Last In, First Out.
- **Real Life**: Like a pile of plates. Add/remove from top.
- **Key Operations**:
  - `push(x)` → Add to top.
  - `pop()` → Remove from top.
  - `top()` / `peek()` → See top element.
  - `isEmpty()` → Check if stack is empty.

### ✅ Use Cases

- Function call stack (recursion)
- Undo operations in editors
- Expression parsing (infix/postfix)
- Backtracking (e.g., maze/DFS)

### 🧰 STL Stack in C++

```cpp
#include <stack>
std::stack<int> st;
st.push(10);
st.pop();
int top = st.top();
```

---

## 🧠 What is a Queue?

- **Definition**: A linear structure that follows **FIFO** – First In, First Out.
- **Real Life**: Like people in a queue. First person in goes out first.
- **Key Operations**:
  - `enqueue(x)` / `push(x)` → Add at rear.
  - `dequeue()` / `pop()` → Remove from front.
  - `front()` → See front element.
  - `isEmpty()`

### ✅ Use Cases

- Job/Process scheduling (OS)
- Buffers (IO, data streams)
- Breadth-first Search (BFS in trees/graphs)

### 🧰 STL Queue in C++

```cpp
#include <queue>
std::queue<int> q;
q.push(1);
q.pop();
int front = q.front();
```

---

## 📘 Difference Table

| Feature    | Stack             | Queue           |
| ---------- | ----------------- | --------------- |
| Order      | LIFO              | FIFO            |
| Main Ops   | push/pop/top      | push/pop/front  |
| Real Use   | Backtracking, DFS | BFS, Scheduling |
| STL Header | `<stack>`         | `<queue>`       |

---

## 🔁 Stack Implementation (Array Based)

```cpp
class Stack {
    int arr[1000], top = -1;
public:
    void push(int x) { arr[++top] = x; }
    void pop() { if (top >= 0) top--; }
    int peek() { return arr[top]; }
};
```

---

## 🔁 Queue Implementation (Array Based)

```cpp
class Queue {
    int arr[1000], front = 0, rear = 0;
public:
    void enqueue(int x) { arr[rear++] = x; }
    void dequeue() { if (front < rear) front++; }
    int peek() { return arr[front]; }
};
```

---

## 🚀 Common Interview Problems

| Problem                          | Approach          |
| -------------------------------- | ----------------- |
| Valid Parentheses                | Stack             |
| Min Stack (getMin in O(1))       | Two stacks        |
| Implement Queue with Stack       | Two stacks        |
| Implement Stack with Queue       | Two queues        |
| Next Greater Element             | Stack (monotonic) |
| Sliding Window Maximum (Fixed K) | Deque             |
| Reverse First K Queue Elements   | Stack + Queue     |
| Circular Queue                   | Array + Modulo    |
| LRU Cache                        | List + Hashmap    |

---

## 💡 Quick Tips

- For balanced brackets: Push on `(` and match on `)`.
- For Monotonic Stack: Keep stack increasing or decreasing to solve NGE, etc.
- Use `deque` for sliding window max/min problems in O(n).
- Always check for underflow (e.g., pop on empty).
- STL stack/queue is sufficient unless custom logic needed.

---

## 🧠 Patterns to Know

- **Backtracking = Stack**
- **BFS = Queue**
- **Next Greater/Smaller = Stack (Reverse Thinking)**

---

## ✅ Summary

- Understand operations + their time complexity.
- Prefer STL unless building low-level system.
- Practice 10–15 classic problems to master these.

Happy Coding!
