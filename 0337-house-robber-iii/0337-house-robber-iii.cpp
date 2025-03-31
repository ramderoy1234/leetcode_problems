class Solution {
  unordered_map<TreeNode*,int>dp;
  int dfs(TreeNode*root){
    if(root==nullptr) return 0;
    if(dp.find(root)!=dp.end()) return dp[root];

    int add=root->val;
    if(root->left) add+=dfs(root->left->left)+dfs(root->left->right);
    if(root->right) add+=dfs(root->right->right)+dfs(root->right->left);

    int skip=dfs(root->left)+dfs(root->right);
    return dp[root]=max(skip,add);

  }
public:
    int rob(TreeNode* root) {
       return dfs(root);
    }
};