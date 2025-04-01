
class Solution {
  void buildGraph(TreeNode*root,unordered_map<int,vector<int>>&graph){
     if(!root) return ;
     if(root->left){
       graph[root->val].push_back(root->left->val);
       graph[root->left->val].push_back(root->val);
       buildGraph(root->left,graph);
     }
     if(root->right){
       graph[root->val].push_back(root->right->val);
       graph[root->right->val].push_back(root->val);
       buildGraph(root->right,graph);
     }
  }

  int dfs(int node,unordered_map<int,vector<int>>&adj,unordered_set<int>&visited){
     visited.insert(node);
     int maxTime=0;
     for(auto it:adj[node]){
       if(!visited.count(it)){
         maxTime=max(maxTime,1+dfs(it,adj,visited));
       }
     }
     return maxTime;
  }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>graph;    // convert tree into graph
        buildGraph(root,graph);
        unordered_set<int>visited;          // then traverse graph
        return dfs(start,graph,visited);
    }
};