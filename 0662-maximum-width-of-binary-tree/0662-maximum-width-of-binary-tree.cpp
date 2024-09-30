
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int maxiwidth=INT_MIN;
        while(!q.empty()){
          int start=q.front().second;
          int end=q.back().second;
          maxiwidth=max(maxiwidth,end-start+1);
          int size=q.size();
          while(size--){
            int idx=q.front().second-end;
            TreeNode*temp=q.front().first;
            q.pop();
            if(temp->left!=nullptr) q.push({temp->left,idx*2+1});
            if(temp->right!=nullptr) q.push({temp->right,idx*2+2});
          }
        }
        return maxiwidth;
    }
};