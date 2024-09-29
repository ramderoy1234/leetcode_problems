
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;
        TreeNode*curr=root;
        while(curr!=nullptr){
          if(curr->left==nullptr){
            preorder.push_back(curr->val);
            curr=curr->right;
          }
          else{
            TreeNode*prev=curr->left;
            while(prev->right!=nullptr && prev->right!=curr){
              prev=prev->right;
            }
            if(prev->right==nullptr){
              prev->right=curr;
              preorder.push_back(curr->val);
              curr=curr->left;
            }
            else{
              prev->right=nullptr;
              curr=curr->right;
            }
          }
        }
        return preorder;
    }
};