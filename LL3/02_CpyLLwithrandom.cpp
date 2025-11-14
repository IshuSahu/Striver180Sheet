#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *random;

    Node(int d) {
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
        copyNode->next = mpp[temp->next]; //mpp[temp]->next = mpp[temp->next];
        //assign nullptr if temp->next is nullptr
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    
    return mpp[head];
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    head->random = head->next->next;                  // 7 → 21
    head->next->random = head;                        // 14 → 7
    head->next->next->random = head->next->next->next; // 21 → 28
    head->next->next->next->random = head->next;       // 28 → 14

    Node* result = cloneLL(head);

    Node* current = result;
    cout << "Cloned list (data and random->data):\n";
    while (current) {
        cout << "Data: " << current->data
             << ", Random: " << (current->random ? current->random->data : -1) << "\n";
        current = current->next;
    }

    current = result;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
