class Solution {
  void dfs(TreeNode*root, int level, int &maxi,vector<int>&ans){
     if(root==nullptr) return ;
     if(maxi<level){
      ans.push_back(root->val);
      maxi=level;
     }
     dfs(root->right,level+1,maxi,ans);
     dfs(root->left,level+1,maxi,ans);
  }
public:
    vector<int> rightSideView(TreeNode* root) {
        int maxi=INT_MIN;
        int level=0;
        vector<int>ans;
        dfs(root,level,maxi,ans);
        return ans;
    }
};