class Solution {
  vector<TreeNode*>solve(int start,int end){
    if(start>end) return {nullptr};
    if(start==end){
      TreeNode*root=new TreeNode(start);
      return {root};
    }
    vector<TreeNode*>ans;
    for(int i=start;i<=end;i++){
      vector<TreeNode*>left=solve(start,i-1);
      vector<TreeNode*>right=solve(i+1,end);
      for(auto &leftBT:left){
        for(auto &rightBT:right){
          TreeNode*root=new TreeNode(i);
          root->left=leftBT;
          root->right=rightBT;
          ans.push_back(root);
        }
      }
    }
    return ans;
  }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return solve(1,n);
    }
};