class Solution {
  void dfs(int node,vector<int>&vist,vector<vector<int>>&isConnected){
    vist[node]=1;
    for(int i=0;i<isConnected.size();i++){
      if(!vist[i]&& isConnected[node][i]){
        dfs(i,vist,isConnected);
      }
    }
  }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n=isConnected.size();
        vector<int>vist(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
          if(!vist[i]){
            cnt++;
            dfs(i,vist,isConnected);
          }
        }
        return cnt;
    }
};