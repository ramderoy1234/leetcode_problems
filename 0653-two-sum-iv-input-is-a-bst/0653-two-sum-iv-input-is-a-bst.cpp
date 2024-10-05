
class Solution {
  bool check(TreeNode*root,int k,unordered_set<int>&mp){
    if(root==nullptr) return false;
    if(mp.count(k-root->val)){
       return true;
    }
    mp.insert(root->val);
    return check(root->left,k,mp)|| check(root->right,k,mp);
  }
public:
    bool findTarget(TreeNode* root, int k) {
      unordered_set<int>mp;
        return check(root,k,mp);
    }
};