/*

🧠 Intuition
We want to count the number of leaf pairs (leaf1, leaf2) such that the distance between them is ≤ distance.
❓ How to find distance between two leaf nodes?
- The path between two leaf nodes always goes up to their Lowest Common Ancestor (LCA) and back down. So we can solve this recursively bottom-up:
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int count = 0;

    vector<int> dfs(TreeNode* root, int distance) {
        if (!root) return {};

        // If it's a leaf node, return distance = 0
        if (!root->left && !root->right) return {0};

        vector<int> leftDistances = dfs(root->left, distance);
        vector<int> rightDistances = dfs(root->right, distance);

        // Check all pairs from left and right
        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r + 2 <= distance) {
                    count++;
                }
            }
        }

        vector<int> newDistances;
        for (int d : leftDistances) {
            if (d + 1 < distance) newDistances.push_back(d + 1);
        }
        for (int d : rightDistances) {
            if (d + 1 < distance) newDistances.push_back(d + 1);
        }

        return newDistances;
    }

    int countPairs(TreeNode* root, int distance) {
        count = 0;
        dfs(root, distance);
        return count;
    }
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    int distance = 3;
    cout << "Good leaf pairs: " << sol.countPairs(root, distance) << endl;

    return 0;
}
