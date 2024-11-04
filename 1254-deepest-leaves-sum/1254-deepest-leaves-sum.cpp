 
class Solution {
    void dfs(TreeNode*root,int &sum,int &maxi,int depth){
        if(root==nullptr) return ;
        if(depth>maxi){
            maxi=depth;
            sum=root->val;
        }
        else if(depth==maxi){
            sum+=root->val;
        }
        dfs(root->left,sum,maxi,depth+1);
        dfs(root->right,sum,maxi,depth+1);
  }
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int maxi=-1;
        int depth=0;
        dfs(root,sum,maxi,depth);
        return sum;
    }
};