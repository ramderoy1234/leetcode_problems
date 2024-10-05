
class Solution {
  bool BST(TreeNode*root,TreeNode*minNode,TreeNode*maxNode){
    if(root==nullptr) return true;
    if((minNode!=nullptr && root->val <= minNode->val) || maxNode!=nullptr && root->val>= maxNode->val ){
       return false;
    }
    return BST(root->left,minNode,root) && BST(root->right,root,maxNode);
  }
public:
    bool isValidBST(TreeNode* root) {
        return BST(root,nullptr,nullptr);
    }
};