
class Solution {
  int height(TreeNode*root, int &maxi){
    if(root==nullptr) return 0;
    int left=max( height(root->left,maxi),0 );
    int right=max( height(root->right,maxi), 0);
    maxi=max(maxi,left+right+root->val);
    return max(left,right)+root->val;
  }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        height(root,maxi);
        return maxi;
    }
};