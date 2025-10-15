/*
        Build this tree:
                1
               / \
              2   3
             / \ / \
            4  5 6  7
              / \
             8   9
output: [1, 2, 4, 8, 9, 6, 7, 3]

Add root's value to boundary result.
- Traverse left boundary (excluding leaves and root).
- Traverse all leaf nodes (including those on the left and right subtree).
- Traverse right boundary (excluding leaves and root), then reverse them before adding.
*/
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isLeaf(Node *node)
    {
        return !node->left && !node->right;
    }

    void addLeftBoundary(Node *root, vector<int> &res)
    {
        Node *cur = root->left;
        while (cur)
        {
            if (!isLeaf(cur)) // if is not leaf
                res.push_back(cur->data);
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
        // for (int i = 0; i < res.size(); i++)
        // {
        //     cout << res[i] << " ";
        // }
        // cout << endl;
    }

    void addRightBoundary(Node *root, vector<int> &res)
    {
        Node *cur = root->right;
        vector<int> tmp;
        while (cur)
        {
            if (!isLeaf(cur))
                tmp.push_back(cur->data);
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        for (int i = (int)tmp.size() - 1; i >= 0; i--) //  in reverse order
        {
            res.push_back(tmp[i]);
        }
        // for (int i = 0; i < res.size(); i++)
        // {
        //     cout << res[i] << " ";
        // }
        // cout << endl;
    }

    void addLeaves(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    Solution sol;
    vector<int> boundaryTraversal = sol.boundary(root);

    cout << "Boundary Traversal: ";
    for (int val : boundaryTraversal)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
