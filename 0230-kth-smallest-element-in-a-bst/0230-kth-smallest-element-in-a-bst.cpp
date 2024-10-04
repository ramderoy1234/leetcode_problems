
class Solution {
  void inorder(TreeNode*root,int k,int &ans,int &cnt){
    if(root==nullptr) return ;
    inorder(root->left,k,ans,cnt);
    cnt++;
    if(cnt==k){
      ans=root->val;
      return ;
    }
    inorder(root->right,k,ans,cnt);

  }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        int cnt=0;
        inorder(root,k,ans,cnt);
        return ans;
    }
};