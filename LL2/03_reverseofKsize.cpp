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

// this wil reverse all the K even if it is also Perfectly kth
Node *reverseLLKsize(Node *head1, int k)
{
    Node *prev = nullptr;
    Node *curr = head1;
    Node *nextptr = nullptr;
    int count = 0;
    Node *temp = head1;
    int length = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        length++;
    }
    while (curr != nullptr && count < k)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        count++;
    }
    length = length - count;

    // if (head1 != nullptr)
    // {
    //     head1->next = curr; // This will ensure the last node of reversed part connects to the remaining nodes
    // }

    // Recursively call for the remaining nodes, and connect the end of reversed part to the next reversed part
    if (nextptr != nullptr && (length / k > 0))
    {
        head1->next = reverseLLKsize(nextptr, k);
    }
    // nextptr = curr;
    // prev is now the new head of the reversed list
    return prev;
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

Node *getKthNode(Node *temp, int k)
{
    k -= 1;

    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }

    return temp;
}

Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    Node *prevLast = NULL;
    while (temp != NULL)
    {
        Node *kThNode = getKthNode(temp, k);
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

        Node *nextNode = kThNode->next;

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