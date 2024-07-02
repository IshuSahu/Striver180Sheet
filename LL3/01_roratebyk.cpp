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

//O(1)

Node * roratedByK(Node * head, int k){
    Node * temp = head;
    Node * pt;
    int i=0;
    while (temp->next!=nullptr)
    {
        if(i == k){
            pt = temp;
        }
        i++;
        temp = temp->next;
    }
    cout<<temp->data<<" "<<endl;
    temp->next = head;
    cout<<temp->next->data<<" "<<endl;
    head = pt->next;
    cout<<head->data<<" "<<endl;
    pt->next = nullptr;
    // cout<<pt->next->data<<" "<<endl;
    return head;
}


int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Node* reversedHead =reverseList(head);
    Node *reversedHead = roratedByK(head,2);

    Node *current = reversedHead;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    current = reversedHead;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

// https://youtu.be/hax-YgdqaGk?si=_w6l7_Jdjqn2X7PL