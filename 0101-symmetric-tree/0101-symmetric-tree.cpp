
class Solution {
  bool solve(TreeNode*leftNode,TreeNode*rightNode){
     if(!leftNode && !rightNode) return true;
     if(!leftNode || !rightNode) return false;
     return (leftNode->val==rightNode->val)&& solve(leftNode->left,rightNode->right)&&solve(leftNode->right,rightNode->left);
  }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};