 
class Solution {
    void dfs(TreeNode*root,int &maxi,int depth,int &ans){
        if(root==nullptr) return ;
        if(depth>maxi){
            maxi=depth;
            ans=root->val;
        }
        dfs(root->left,maxi,depth+1,ans);
        dfs(root->right,maxi,depth+1,ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxi=INT_MIN;
        int depth=0;
        int ans=0;
        dfs(root,maxi,depth,ans);
        return ans;
    }
};