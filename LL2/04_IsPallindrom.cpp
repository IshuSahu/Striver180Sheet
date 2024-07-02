// Find intersection of Two Linked Lists

/*
Example 1:
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2

Example 2:
Input:
 List1 = [1,2,7], List 2 = [2,8,1]
Output:
 Null
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = nullptr;
    }
};

bool IsPallindrome(Node *head)
{
    stack<int> st;

    Node *temp = head;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Node *current = head;
    // cout << "List1" << ": ";
    // while (current)
    // {
    //     cout << current->data << "->";
    //     current = current->next;
    // }
    // cout << "null" << endl;

    cout << IsPallindrome(head) << endl;

    return 0;
}

// https://youtu.be/hax-YgdqaGk?si=_w6l7_Jdjqn2X7PL