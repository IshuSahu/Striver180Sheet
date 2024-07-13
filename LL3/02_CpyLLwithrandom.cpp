#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int d)
    {
        data = d;
        next = nullptr;
        random = nullptr;
    }
};
Node *cloneLL(Node *head)
{
    Node *temp = head;
    map<Node *, Node *> mpp;
    while (temp != nullptr)
    {
        Node *newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    
    return mpp[head];
}

int main()
{
    Node *head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    Node *result = cloneLL(head);

    Node *current = result;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    current = result;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
