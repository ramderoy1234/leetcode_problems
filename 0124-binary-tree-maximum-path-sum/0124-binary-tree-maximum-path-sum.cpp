
class Solution {
  int maxSum(TreeNode*root,int &maxi){
    if(root==nullptr){
      return 0;
    }
    int left=max(  maxSum(root->left,maxi) ,0);
    int right=max( maxSum(root->right,maxi) ,0);
    maxi=max(maxi,left+right+root->val);
    return max(left,right)+root->val;
  }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxSum(root,maxi);
        return maxi;
    }
};