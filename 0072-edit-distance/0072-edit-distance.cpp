class Solution {
  int recursion(int n,int m,string &s,string &x,vector<vector<int>>&dp){
    if(n==0) return m;
    if(m==0) return n;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==x[m-1]){
      dp[n][m]=recursion(n-1,m-1,s,x,dp);
    }
    else{
      dp[n][m]=1+min({
        recursion(n-1,m,s,x,dp),
        recursion(n,m-1,s,x,dp),
        recursion(n-1,m-1,s,x,dp)
      });
    }
    return dp[n][m];
  }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return recursion(n,m,word1,word2,dp);
    }
};