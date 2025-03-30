class Solution {
public:
    int minDiff = INT_MAX, prev = -1;
    void inordered(TreeNode*root){
        if(root==nullptr) return ;
        inordered(root->left);
        if(prev!=-1){
            minDiff=min(minDiff,root->val-prev);
        }
        prev=root->val;
        inordered(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inordered(root);
        return minDiff;
    }
};
