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

// O(1)

Node* interceptnode(Node* head1, Node* head2) {
    while (head2 != nullptr) {
        Node* temp = head1;
        while (temp != nullptr) {
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return nullptr;
}

// Time Complexity: O(m*n)

Node *interceptPresend(Node *head1, Node *head2)
{
    unordered_set<Node *> st;
    while (head1 != NULL)
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }
    return NULL;
}
////Time Complexity: O(m + n)
// Space Complexity: O(n)

/*
Take two dummy nodes for each list. Point each to the head of the lists.
Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.
*/

Node *intersectionPresent2(Node *head1, Node *head2)
{
    Node *d1 = head1;
    Node *d2 = head2;

    while (d1 != d2)
    {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }

    return d1;
}

int main() {
    // Create the shared list
    Node* shared = new Node(1);
    shared->next = new Node(3);
    shared->next->next = new Node(1);
    shared->next->next->next = new Node(2);
    shared->next->next->next->next = new Node(4);

    // Create the second list and link it to the shared list
    Node* head2 = new Node(3);
    head2->next = new Node(2);
    head2->next->next = shared->next->next->next; // Intersection happens here

    // Print List 1
    cout << "List1: ";
    Node* current = shared;
    while (current) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "null" << endl;

    // Print List 2
    current = head2;
    cout << "List2: ";
    while (current) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "null" << endl;

    // Find the intersection node
    // Node* answerNode = interceptnode(shared, head2);
    Node* answerNode = interceptPresend(shared, head2);
    if (answerNode == nullptr)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->data << endl;

    return 0;
}
// https://youtu.be/hax-YgdqaGk?si=_w6l7_Jdjqn2X7PL