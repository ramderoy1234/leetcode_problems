class Solution {
  int recursion(int n,int m, vector<vector<int>>&triangle,vector<vector<int>>&dp){
    if(n==triangle.size()-1) return triangle[n][m];
    if(dp[n][m]!=-1) return dp[n][m];
    int down=recursion(n+1,m,triangle,dp);
    int downright=recursion(n+1,m+1,triangle,dp);
    return dp[n][m]=triangle[n][m]+min(down,downright);
  }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recursion(0,0,triangle,dp);
    }
};