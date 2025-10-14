#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* addTwoNumbers(Node* l1, Node* l2) {
    stack<int> s1, s2;

    // Step 1: Push all digits into stacks
    while (l1) {
        s1.push(l1->data);
        l1 = l1->next;
    }

    while (l2) {
        s2.push(l2->data);
        l2 = l2->next;
    }

    Node* result = nullptr;
    int carry = 0;

    // Step 2: Add digits from both stacks
    while (!s1.empty() || !s2.empty() || carry) {
        int sum = carry;

        if (!s1.empty()) {
            sum += s1.top(); s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top(); s2.pop();
        }

        carry = sum / 10;
        int digit = sum % 10;

        // Step 3: Insert at head (build list backwards)
        Node* newNode = new Node(digit);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head1 = new Node(7);
    head1->next = new Node(2);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(3);
    Node *head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    // Node* reversedHead =reverseList(head);
    Node *reversedHead = addTwoNumbers(head1, head2);

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

