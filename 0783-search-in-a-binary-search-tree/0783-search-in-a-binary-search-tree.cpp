class Solution {
public:
 
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        }

        if(root->val==val){
           return root;
        }

        if(root->val>val){           // val is greater then root-val then search in left part
           return searchBST(root->left,val);
        }

        else if(root->val<val){      // val is lesser then root-val then search in right part
          return searchBST(root->right,val);
        }
        
       return nullptr;
    }
};
