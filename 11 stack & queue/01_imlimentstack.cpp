#include <iostream>
using namespace std;

class Stack {
    int arr[1000], top = -1;
public:
    void push(int x) { arr[++top] = x; }
    void pop() { if (top >= 0) top--; }
    int peek() { return (top >= 0) ? arr[top] : -1; }
    bool isEmpty() { return top == -1; }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    cout << "After one pop, top element: " << st.peek() << endl;

    st.pop();
    st.pop();
    if (st.isEmpty())
        cout << "Stack is empty now." << endl;
    else
        cout << "Top element: " << st.peek() << endl;

    return 0;
}
