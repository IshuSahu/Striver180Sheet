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
        curr->next = prev;
        prev = curr;
        curr = temp;
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
            if (prevLast)
            {
                prevLast->next = temp;
            }

            break;
        }

        Node *nextNode = kThNode->next;

        kThNode->next = NULL;

        reverseList(temp);
        // after reverse if this is first group we're reversing? assign head with kthNode as this will be our head else subsequent k-groups, we just connect the previous group's last node
        if (temp == head)
        {
            head = kThNode;
        }
        else
        {
            prevLast->next = kThNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{
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