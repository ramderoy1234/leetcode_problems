
class Solution {
    bool check(TreeNode*root, unordered_set<int>&mp, int k){
        if(root==nullptr) return false;
        if(mp.count(k-root->val)){
            return true;
        }
        mp.insert(root->val);
        return check(root->left,mp,k) || check(root->right,mp,k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>mp;
        return check(root,mp,k);
    }
};