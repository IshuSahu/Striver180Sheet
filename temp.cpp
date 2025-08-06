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
Node *Merge2sorted1(Node *head1, Node *head2)
{
    Node *temp;
    vector<int> arr;
    temp = head1;
    while (temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp != nullptr)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    Node *_Dummy = new Node(-1);
    temp = _Dummy;
    for (int i = 0; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return _Dummy->next;
}
int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(13);
    head1->next->next = new Node(22);
    head1->next->next->next = new Node(24);

    Node *head2 = new Node(2);
    head2->next = new Node(4);
    // head2->next->next = new Node(13);
    // head2->next->next->next = new Node(14);
    // head2->next->next->next->next = new Node(15);

    // Merge the two sorted linked lists
    Node *head = Merge2sorted1(head1, head2);
    Node *current = head;

    // Print the merged linked list
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Clean up the memory
    current = head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}