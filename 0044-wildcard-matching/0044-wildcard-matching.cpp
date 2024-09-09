class Solution {
  int recursion(int n,int m, string &s, string &p,vector<vector<int>>&dp){
    if(m==0) return n==0;
    if(n==0){
      for(int i=0;i<m;i++){
        if(p[i]!='*') return 0;
      }
      return 1;
    }
    if(dp[n][m]!=-1) return dp[n][m];
    if(p[m-1]==s[n-1] || p[m-1]=='?'){
      dp[n][m]=recursion(n-1,m-1,s,p,dp);
    }
    else if(p[m-1]=='*'){
      dp[n][m]=recursion(n-1,m,s,p,dp) || recursion(n,m-1,s,p,dp);
    }
    else{
      dp[n][m]=0;
    }
    return dp[n][m];

  }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return recursion(n,m,s,p,dp);
    }
};