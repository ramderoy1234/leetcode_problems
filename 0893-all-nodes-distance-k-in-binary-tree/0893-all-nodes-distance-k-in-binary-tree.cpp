class Solution {
  void buildGraph(TreeNode*root,TreeNode*target,unordered_map<int,vector<int>>&adj){
    if(root){
      if(target){
        adj[root->val].push_back(target->val);
        adj[target->val].push_back(root->val);
      }
      buildGraph(root->left,root,adj);
      buildGraph(root->right,root,adj);
    }
  }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>adj;
        buildGraph(root,nullptr,adj);

        vector<int>ans;
        unordered_set<int>visited;
        queue<pair<int,int>>q;
        q.push({target->val,0}); // target node and k distance
        visited.insert(target->val);
        while(!q.empty()){
          int node=q.front().first;
          int dist=q.front().second;
          q.pop();
          if(dist==k){
             ans.push_back(node);
             continue;
          }
          for(auto it:adj[node]){
            if(!visited.count(it)){
              visited.insert(it);
              q.push({it,dist+1});
            }
          }
        }
        return ans;
    }
};