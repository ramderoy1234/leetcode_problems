
class Solution {
    bool dfs(TreeNode*leftNode,TreeNode*rightNode){
        if(leftNode==nullptr && rightNode==nullptr) return true;
        if(leftNode!=nullptr && rightNode==nullptr) return false;
        if(leftNode==nullptr && rightNode!=nullptr) return false;
        return (leftNode->val==rightNode->val)&& dfs(leftNode->left,rightNode->right)&& dfs(leftNode->right,rightNode->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};