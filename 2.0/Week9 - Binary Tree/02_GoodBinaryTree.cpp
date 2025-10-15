#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countGoodNodes(TreeNode* root, int maxSoFar) {
    if (!root) return 0;

    int count = 0;
    if (root->val >= maxSoFar) {
        count = 1;
        maxSoFar = root->val;
    }

    count += countGoodNodes(root->left, maxSoFar);
    count += countGoodNodes(root->right, maxSoFar);

    return count;
}

int goodNodes(TreeNode* root) {
    return countGoodNodes(root, root->val);
}

int main() {
    // Example tree: [3,1,4,3,null,1,5]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << "Number of good nodes: " << goodNodes(root) << endl;

    return 0;
}
