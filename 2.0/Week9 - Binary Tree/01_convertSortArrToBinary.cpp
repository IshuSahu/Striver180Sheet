#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*
Use Divide and Conquer (recursion):
- The middle element of the array becomes the root.
- The left half becomes the left subtree.
- The right half becomes the right subtree.
*/
TreeNode* buildBST(const vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;

    int mid = left + (right - left) / 2;
    TreeNode* node = new TreeNode(nums[mid]);

    node->left = buildBST(nums, left, mid - 1);
    node->right = buildBST(nums, mid + 1, right);

    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildBST(nums, 0, nums.size() - 1);
}
