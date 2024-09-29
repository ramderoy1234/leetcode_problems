
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>node;
        // vertical , level ,values
        queue<pair<TreeNode*,pair<int,int>>>q;
        // root ,{ vertical ,level}
        q.push({root,{0,0}});
        while(!q.empty()){
          TreeNode*temp=q.front().first;
          int vertical=q.front().second.first;
          int level=q.front().second.second;
          q.pop();
          node[vertical][level].insert(temp->val);
          if(temp->left!=nullptr){
            q.push({temp->left,{vertical-1,level+1}});
          }
          if(temp->right!=nullptr){
            q.push({temp->right,{vertical+1,level+1}});
          }
        }
        vector<vector<int>>ans;
        for(auto it:node){
          vector<int>col;
          for(auto c:it.second){
            col.insert(col.end(),c.second.begin(),c.second.end());
          }
          ans.push_back(col);
        }
        return ans;
    }
};