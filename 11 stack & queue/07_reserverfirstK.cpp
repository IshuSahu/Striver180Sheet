#include <bits/stdc++.h>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    vector<int> temp;
    for (int i = 0; i < k && !q.empty(); ++i) {
        temp.push_back(q.front());
        q.pop();
    }

    reverse(temp.begin(), temp.end());

    for (int val : temp)
        q.push(val);

    int size = q.size() - temp.size();
    while (size--) { //rotating the indexes
        q.push(q.front());
        q.pop();
    }
    return q;
}

queue<int> reverseK(queue<int> q, int k) {
    stack<int> s;
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    int t = q.size() - k;
    while (t--) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 5; ++i) q.push(i); // 1 2 3 4 5

    queue<int> res = reverseFirstK(q, 3);
    while (!res.empty()) {
        cout << res.front() << " ";
        res.pop();
    }
}
