class Solution {
  void dfs(int node,vector<int>&visited,vector<vector<int>>&adj){
    visited[node]=1;
    for(auto it:adj[node]){
      if(!visited[it]){
        dfs(it,visited,adj);
      }
    }
  }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
              adj[i].push_back(j);
            }
           }
        }
        for(int i=0;i<n;i++){
          if(!visited[i]){
            dfs(i,visited,adj);
            cnt++;
          }
        }
        return cnt;
    }
};