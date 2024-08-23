class Solution {
  int recursion(int n,int m, string &s,string &x,vector<vector<int>>&dp){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==x[m-1]){
      dp[n][m]=1+recursion(n-1,m-1,s,x,dp);
    }
    else{
      dp[n][m]=max(recursion(n-1,m,s,x,dp),recursion(n,m-1,s,x,dp));
    }
    return dp[n][m];
  }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return recursion(n,m,text1,text2,dp);
    }
};