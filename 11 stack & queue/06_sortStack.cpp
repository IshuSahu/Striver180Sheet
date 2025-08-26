#include <bits/stdc++.h>
using namespace std;

void insertInSortedOrder(stack<int> &st, int x)
{
    // Base case: if stack is empty or top >= x (since descending order)
    if (st.empty() || st.top() >= x)
    {
        st.push(x);
        return;
    }

    // Otherwise, pop and recurse
    int temp = st.top();
    st.pop();
    insertInSortedOrder(st, x);

    // Push the popped element back
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    // Base case: stack of size 0 or 1 is already sorted
    if (st.empty() || st.size() == 1)
        return;

    // Pop the top element
    int topElem = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortStack(st);

    // Insert the popped element in sorted order
    insertInSortedOrder(st, topElem);
}

int main()
{
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original Stack (top to bottom): ";
    stack<int> tempSt = st;
    while (!tempSt.empty())
    {
        cout << tempSt.top() << " ";
        tempSt.pop();
    }
    cout << endl;

    // Sort the stack
    sortStack(st);

    cout << "Sorted Stack (Descending, top to bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

/*
Steps:
sortStack: pop 2, recurse on [4,1,3].
Sort [4,1,3] → pop 4, recurse on [1,3].
Sort [1,3] → pop 1, recurse on [3].
Sort [3] → base case.
Insert 1 into [3] → [3,1].
Insert 4 into [3,1] → [4,3,1].
Insert 2 into [4,3,1] → [4,3,2,1].
*/