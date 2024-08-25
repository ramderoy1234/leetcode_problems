class Solution {
  int lcs(string &s,string &x,int n,int m,vector<vector<int>>&dp){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n-1]==x[m-1]){
      dp[n][m]=lcs(s,x,n-1,m-1,dp)+1;
    }
    else{
      dp[n][m]=max(lcs(s,x,n-1,m,dp),lcs(s,x,n,m-1,dp));
    }
    return dp[n][m];
  }
public:
    int minInsertions(string s) {
        string x=s;
        reverse(x.begin(),x.end());
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int lenght=lcs(s,x,n,n,dp);

        return n-lenght;
    }
};