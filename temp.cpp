#include<bits/stdc++.h>

using namespace std;
class Node {
    public:
        int val;
        Node * next;
        Node * random;
        Node(int d){
            val=d;
            next = nullptr;
            random= nullptr;
        }
};
Node * cloneLL(Node * head){
    Node * temp = head;
    unordered_map<Node* , Node*> mp;
    while (temp!=nullptr)
    {
        Node * NewNode = new Node(temp->val);
        mp[temp] = NewNode;
        temp = temp->next;
    }

    temp = head;
    while (temp!=nullptr)
    {
        Node * cpynode = mp[temp];
        cpynode->next = mp[temp->next];
        cpynode->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
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
        cout << current->val << " ";
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
