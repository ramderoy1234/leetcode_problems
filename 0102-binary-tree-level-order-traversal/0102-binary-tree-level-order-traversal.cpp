
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==nullptr){
          return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int n=q.size();
          vector<int>level;
          for(int i=0;i<n;i++){
            TreeNode*temp=q.front();
            q.pop();
            if(temp->left!=nullptr){
              q.push(temp->left);
            }
            if(temp->right!=nullptr){
              q.push(temp->right);
            }
            level.push_back(temp->val);
          }
          ans.push_back(level);
        }
        return ans;
    }
};