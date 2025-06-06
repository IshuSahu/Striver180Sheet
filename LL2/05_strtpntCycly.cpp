

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

int StartingpointOfLoop(Node *head)
{
    Node *hare = head;
    Node *tortoise = head;

    do
    {
        hare = hare->next->next;
        tortoise = tortoise->next;
    } while (hare != tortoise);

    hare = head; // retrun back  any one to the head then start poining next next

    while (hare->next != tortoise->next)
    {
        hare = hare->next;
        tortoise = tortoise->next;
    }
    return tortoise->next->data;
}

Node *detectCyclePnt(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
    // If no loop is found, return NULL
    return NULL;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;

    // Node *current = head;
    // cout << "List1" << ": ";
    // while (current)
    // {
    //     cout << current->data << "->";
    //     current = current->next;
    // }
    // cout << "null" << endl;

    // cout << StartingpointOfLoop(head) << endl;
    cout << detectCyclePnt(head) << endl;

    return 0;
}

// https://youtu.be/hax-YgdqaGk?si=_w6l7_Jdjqn2X7PL