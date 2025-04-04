
class Solution {
    void buildGraph(TreeNode*root,unordered_map<int,vector<int>>&adj){
        if(!root) return ;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            buildGraph(root->left,adj);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
            buildGraph(root->right,adj);
        }

    }
    int dfs(int node,unordered_map<int,vector<int>>&adj,unordered_set<int>&visited){
        visited.insert(node);
        int maxi=0;
        for(auto it:adj[node]){
            if(!visited.count(it)){
                maxi=max(maxi,1+dfs(it,adj,visited));
            }
        }
        return maxi;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        buildGraph(root,adj);

        unordered_set<int>visited;
        
        return dfs(start,adj,visited);
        
    }
};