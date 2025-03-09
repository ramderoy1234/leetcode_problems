
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode*curr=root;
        while(curr!=nullptr){
          if(curr->left==nullptr){
            ans.push_back(curr->val);
            curr=curr->right;
          }
          else{
            TreeNode*prev=curr->left;
            while(prev->right!=nullptr && prev->right!=curr){
              prev=prev->right;
            }
            if(prev->right==nullptr){
              prev->right=curr;
              curr=curr->left;
            }
            else{
              prev->right=nullptr;
              ans.push_back(curr->val);
              curr=curr->right;
            }
          }
        }
        return ans;
    }
};