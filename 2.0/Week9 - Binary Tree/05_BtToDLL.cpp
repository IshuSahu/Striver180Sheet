#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
        : data(0), left(NULL), right(NULL) {}

    Node(int x)
        : data(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    Node *prev = nullptr; // previously processed node
    Node *head = nullptr; // head of DLL

    void inorder(Node *root)
    {
        if (!root)
            return;

        // Process left subtree
        inorder(root->left);

        // Processing current node
        if (prev == nullptr)
        {
            // This is the leftmost node
            head = root;
        }
        else
        {
            // Link prev and current node
            prev->right = root;
            root->left = prev;
        }
        prev = root; // update prev

        // Process right subtree
        inorder(root->right);
    }

    Node *bToDLL(Node *root)
    {
        prev = nullptr;
        head = nullptr;
        inorder(root);
        return head;
    }
};

int main()
{

    return 0;
}