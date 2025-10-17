#include <iostream>
#include <vector>
using namespace std;

// Tree node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Build BST from unsorted array
TreeNode* buildBSTFromArray(const vector<int>& arr) {
    TreeNode* root = nullptr;
    for (int val : arr) {
        root = insertBST(root, val);
    }
    return root;
}

// In-order traversal (for checking)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Main
int main() {
    vector<int> arr = {10, 5, 15, 2, 7, 12, 20};
    
    TreeNode* root = buildBSTFromArray(arr);
    
    cout << "In-order Traversal of BST: ";
    inorder(root);  // Should print sorted values
    cout << endl;

    return 0;
}
