class Solution {
int recursion(int n,int m,vector<vector<int>>&tri,vector<vector<int>>&dp){
  if(n==tri.size()-1) return tri[n][m];
  if(dp[n][m]!=-1) return dp[n][m];
  int right=recursion(n+1,m,tri,dp);
  int down=recursion(n+1,m+1,tri,dp);
  return dp[n][m]=tri[n][m]+min(right,down);
}  
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return recursion(0,0,triangle,dp);
    }
};