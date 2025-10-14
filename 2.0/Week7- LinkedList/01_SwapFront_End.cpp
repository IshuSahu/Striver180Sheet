#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *swapKthNodes(Node *head, int k)
{
    if (!head)
        return head;

    // Step 1: Get length
    int n = 0;
    Node *temp = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }

    if (k > n)
        return head;
    if (2 * k - 1 == n)
        return head; // same node

    // Step 2: Find kth node from start
    Node *x = head;
    for (int i = 1; i < k; i++)
        x = x->next;

    // Step 3: Find kth node from end
    Node *y = head;
    for (int i = 1; i < n - k + 1; i++)
        y = y->next;

    // Step 4: Swap their data
    int tempData = x->data;
    x->data = y->data;
    y->data = tempData;

    return head;
}

//Swapping Actual Nodes (Not Just Data)
Node* swapKthNodes(Node* head, int k) {
    if (!head) return head;

    // Step 1: Get length
    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }

    if (k > n) return head;
    if (2 * k - 1 == n) return head; // same node from start and end

    // Step 2: Find kth from start and its prev
    Node* prevX = nullptr;
    Node* currX = head;
    for (int i = 1; i < k; i++) {
        prevX = currX;
        currX = currX->next;
    }

    // Step 3: Find kth from end and its prev
    Node* prevY = nullptr;
    Node* currY = head;
    for (int i = 1; i < n - k + 1; i++) {
        prevY = currY;
        currY = currY->next;
    }

    // Step 4: Handle previous pointers
    if (prevX) prevX->next = currY;
    else head = currY;

    if (prevY) prevY->next = currX;
    else head = currX;

    // Step 5: Swap next pointers
    Node* tempNext = currX->next;
    currX->next = currY->next;
    currY->next = tempNext;

    return head;
}
void printList(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 1;

    cout << "Original list: ";
    printList(head);

    head = swapKthNodes(head, k);

    cout << "After swapping kth nodes: ";
    printList(head);

    return 0;
}
