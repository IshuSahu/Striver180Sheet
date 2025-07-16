#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minS;

public:
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top()) {
            minS.push(x);
        } else {
            minS.push(minS.top());
        }
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
            minS.pop();
        }
    }

    int top() {
        return s.empty() ? -1 : s.top();
    }

    int getMin() {
        return minS.empty() ? -1 : minS.top();
    }
};

int main() {
    MinStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    cout << "Min: " << st.getMin() << endl; // 3
    st.pop();
    cout << "Min: " << st.getMin() << endl; // 3
    st.pop();
    cout << "Min: " << st.getMin() << endl; // 5
}
