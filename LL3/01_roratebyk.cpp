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

// O(Number of Nodes present in the list*k)

Node* roratedByK(Node* head, int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        Node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        Node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
Node* rotateRight(Node* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
    Node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link last Node to first Node making circular linklist
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last Node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
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
    Node *reversedHead = roratedByK(head,5);

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