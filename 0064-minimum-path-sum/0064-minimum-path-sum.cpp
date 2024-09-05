class Solution {
int recursion(int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
  if(n==0 &&m==0) return grid[0][0];
  if(n<0 || m<0) return INT_MAX;
  if(dp[n][m]!=-1) return dp[n][m];
  int down =recursion(n-1,m,grid,dp);
  int right=recursion(n,m-1,grid,dp);
  return dp[n][m]=grid[n][m]+min(down,right);
}  
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return recursion(n-1,m-1,grid,dp);
    }
};