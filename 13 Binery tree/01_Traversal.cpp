#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *n = new Node();
    n->data = data;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void preOrder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *p = createNode(1);
    Node *p1 = createNode(2);
    Node *p2 = createNode(3);
    Node *p3 = createNode(4);
    Node *p4 = createNode(5);
    Node *p5 = createNode(6);
    Node *p6 = createNode(7);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    cout << "Pre-order Traversal: ";
    preOrder(p);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(p);
    cout << endl;

    cout << "In-order Traversal: ";
    inOrder(p);
    cout << endl;

    return 0;
}
