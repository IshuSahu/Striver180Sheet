#include<bits/stdc++.h>

using namespace std;
class Node{
public:
    int data;
    Node * next;
    Node *child;
    Node(int d){
        data = d;
        next =nullptr;
        child = nullptr;
    }

};
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}
Node * flattenLinkedList(Node * head){
    Node * temp =head;
    vector<int> arr;
    while (temp!=nullptr)
    {
        Node * temp2 = temp;
        while (temp2!=nullptr)
        {
            arr.push_back(temp2->data);
            temp2 = temp2->child;
        }
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    Node *dummyNode = new Node(-1);
    temp = dummyNode;

    for (int i = 0; i < arr.size(); i++)
    {

        temp->child = new Node(arr[i]);
        temp = temp->child;
    }

    return dummyNode->child;
    
}
int main()
{
    // Create a linked list with child pointers
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // cout << "Original linked list:" << endl;
    // printOriginalLinkedList(head, 0);

    Node *flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
