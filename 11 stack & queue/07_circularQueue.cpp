#include <bits/stdc++.h>
using namespace std;

class BruteCircularQueue {
    queue<int> q;
    int capacity;

public:
    BruteCircularQueue(int k) : capacity(k) {}

    bool enQueue(int value) {
        if (q.size() == capacity) return false;
        q.push(value);
        return true;
    }

    bool deQueue() {
        if (q.empty()) return false;
        q.pop();
        return true;
    }

    int Front() {
        return q.empty() ? -1 : q.front();
    }

    int Rear() {
        return q.empty() ? -1 : q.back();
    }

    bool isEmpty() {
        return q.empty();
    }

    bool isFull() {
        return q.size() == capacity;
    }
};

#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    vector<int> q;
    int front, rear, size, capacity;

public:
    CircularQueue(int k) {
        capacity = k;
        q.resize(k);
        front = -1;
        rear = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) front = 0;
        rear = (rear + 1) % capacity;
        q[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : q[front];
    }

    int Rear() {
        return isEmpty() ? -1 : q[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    BruteCircularQueue q(3);
    cout << q.enQueue(1) << endl;
    cout << q.enQueue(2) << endl;
    cout << q.enQueue(3) << endl;
    cout << q.enQueue(4) << endl; 
    cout << q.Rear() << endl;
}
