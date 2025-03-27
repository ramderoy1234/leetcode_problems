class Solution {
  void dfs(TreeNode* root, int &sum) {
    if (!root) return;

    // If current node is even, add grandchildren values
    if (root->val % 2 == 0) {
        if (root->left!=nullptr) {
            if (root->left->left) sum += root->left->left->val;
            if (root->left->right) sum += root->left->right->val;
        }
        if (root->right!=nullptr) {
            if (root->right->left) sum += root->right->left->val;
            if (root->right->right) sum += root->right->right->val;
        }
    }

    dfs(root->left, sum);
    dfs(root->right, sum);
  }

public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};
