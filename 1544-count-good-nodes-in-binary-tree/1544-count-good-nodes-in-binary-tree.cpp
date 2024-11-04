
class Solution {
    void dfs(TreeNode*root,int x,int &cnt){
        if(root==nullptr) return ;
        if(root->val>=x){
            cnt++;
        }
        x=max(x,root->val);
        dfs(root->left,x,cnt);
        dfs(root->right,x,cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt=0;
        dfs(root,root->val,cnt);
        return cnt;
    }
};