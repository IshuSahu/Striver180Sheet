/*
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4 Output: 2 Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Intuition
- Given two nodes p and q:
- If both p and q are smaller than the current node → LCA must be in the left subtree
- If both p and q are greater than the current node → LCA must be in the right subtree
- Otherwise, the current node is the split point → it's the Lowest Common Ancestor
*/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    // If both p and q are less than root, LCA is in the left subtree
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // If both p and q are greater than root, LCA is in the right subtree
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // Otherwise, root is the split point and hence the LCA
    return root;
}

int main() {
    // Construct the BST
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;             // Node with value 2
    TreeNode* q = root->right;            // Node with value 8

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    }

    return 0;
}
