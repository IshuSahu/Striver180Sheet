#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
💡 How It Works:
- Use a stack to remember nodes.
- Push the root, process it immediately (save its value), then push right and left child.
- We push right before left because stack is LIFO, and we want to visit left first.
*/
vector<int> preOrderTraversal(TreeNode* root) {
    vector<int> PreOrder;
    if (root == nullptr) return PreOrder;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();
        PreOrder.push_back(curr->val);

        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }

    return PreOrder;
}

/*
💡 How It Works:
- Keep pushing all left children onto the stack.
- Once there’s no more left, process the node (i.e., visit), then go to its right.
- The stack helps us backtrack to the parent when left is done.
*/
vector<int> inOrderTraversal(TreeNode* root) {
    vector<int> InOrder;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        InOrder.push_back(curr->val);

        curr = curr->right;
    }

    return InOrder;
}
/*
💡 How It Works:
- We keep track of whether the right child has been processed or not using a prev pointer.
- Node is only processed when:
    - There’s no right child or
    - Right child is already processed.
*/
vector<int> postOrderTraversal(TreeNode* root) {
    vector<int> PostOrder;
    stack<TreeNode*> st;
    TreeNode* temp = nullptr;
    TreeNode* curr = root;
    TreeNode* prev = nullptr;
/*
        1
       / \
      2   3
     / \ / \
    4  5 6  7
*/
    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            temp = st.top();
            if (temp->right == nullptr || temp->right == prev) {
                st.pop();
                PostOrder.push_back(temp->val);
                prev = temp;
            } else {
                curr = temp->right;
            }
        }
    }

    return PostOrder;
}

int main() {
    TreeNode* p = new TreeNode(1);
    TreeNode* p1 = new TreeNode(2);
    TreeNode* p2 = new TreeNode(3);
    TreeNode* p3 = new TreeNode(4);
    TreeNode* p4 = new TreeNode(5);
    TreeNode* p5 = new TreeNode(6);
    TreeNode* p6 = new TreeNode(7);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    vector<int> preOrder = preOrderTraversal(p);
    vector<int> postOrder = postOrderTraversal(p);
    vector<int> inOrder = inOrderTraversal(p);

    cout << "Pre-order Traversal: ";
    for (int val : preOrder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Post-order Traversal: ";
    for (int val : postOrder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "In-order Traversal: ";
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
