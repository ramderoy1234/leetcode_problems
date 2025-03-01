class Solution {
  int recursion(int n,int m,vector<vector<int>>&dp){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    int left=recursion(n-1,m,dp);
    int right=recursion(n,m-1,dp);
    return dp[n][m]=(left+right);
  }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        return recursion(n-1,m-1,dp);
    }
};