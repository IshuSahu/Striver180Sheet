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

// this wil rever all the K even if it is also Perfectly kth
Node *reverseLLKsize(Node *head1, int k)
{
    Node *prev = nullptr;
    Node *curr = head1;
    Node *nextptr = nullptr;
    int count = 0;

    // This will reverse the first k nodes of the linked list
    while (curr != nullptr && count < k)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }

    // Now nextptr is pointing to (k+1)th node
    // head1 is the last node in the reversed list and needs to be connected to the result of the next reverse operation
    if (head1 != nullptr)
    {
        head1->next = curr; // This will ensure the last node of reversed part connects to the remaining nodes
    }

    // Recursively call for the remaining nodes, and connect the end of reversed part to the next reversed part
    if (nextptr != nullptr)
    {
        head1->next = reverseLLKsize(nextptr, k);
    }

    // prev is now the new head of the reversed list
    return prev;
}
// a given position in the linked list
Node *getKthNode(Node *temp, int k)
{
    // Decrement K as we already
    // start from the 1st node
    k -= 1;

    // Decrement K until it reaches
    // the desired position
    while (temp != NULL && k > 0)
    {
        // Decrement k as temp progresses
        k--;

        // Move to the next node
        temp = temp->next;
    }

    // Return the Kth node
    return temp;
}
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr->next;
        curr->next = prev; // here we change the direction
        prev = curr;       // Move 'prev' to the current
        curr = temp;       // Move 'curr' to the 'next element' node
    }
    return prev;
}
// Function to reverse nodes in groups of K
Node *kReverse(Node *head, int k)
{
    // Initialize a temporary node to traverse the list
    Node *temp = head;

    // Initialize a pointer to track the ;ast node of the previous group
    Node *prevLast = NULL;

    // Traverse through the linked list
    while (temp != NULL)
    {
        // Get the Kth node of the current group
        Node *kThNode = getKthNode(temp, k);

        // If the Kth node is NULL(not a complete group)
        if (kThNode == NULL)
        {
            // If there was a previous group, link the last node to the current node
            if (prevLast)
            {
                prevLast->next = temp;
            }

            // Exit the loop
            break;
        }

        // Store the next node after the Kth node
        Node *nextNode = kThNode->next;

        // Disconnect the Kth node to prepare for reversal
        kThNode->next = NULL;

        // Reverse the nodes from temp to the Kth node
        reverseList(temp);

        // Adjust the head if the reversal starts from the head
        if (temp == head)
        {
            head = kThNode;
        }
        else
        {
            // Link the last node of the previous group to the reversed group
            prevLast->next = kThNode;
        }

        // Update the pointer to the last node of the previous group
        prevLast = temp;

        // Move to the next group
        temp = nextNode;
    }

    // Return the head of the modified linked list
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
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    // Node* reversedHead =reverseList(head);
    // Node *reversedHead = reverseLLKsize(head, 3);
    Node *reversedHead = kReverse(head, 3);

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