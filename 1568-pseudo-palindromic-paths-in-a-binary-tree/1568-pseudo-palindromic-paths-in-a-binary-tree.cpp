
class Solution {
    int dfs(TreeNode*root,int path){
        if(root==nullptr) return 0;

        path^=(1<<root->val);
        if(root->left==nullptr && root->right==nullptr){
            return (path&(path-1))==0?1:0;
        }
      int leftNode=dfs(root->left,path);
      int rightNode=dfs(root->right,path);
        return leftNode+rightNode;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root,0);
    }
};