
class Solution {
  void dfs(TreeNode*root,int level,int &maxi,vector<int>&ans){
    if(root==nullptr) return ;
    if(maxi<level){
      maxi=level;
      ans.push_back(root->val);
    }
    dfs(root->right,level+1,maxi,ans);
    dfs(root->left,level+1,maxi,ans);
    
  }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr) return ans;
        int maxi=INT_MIN;
        int level=0;
        dfs(root,level,maxi,ans);
        return ans;
    }
};