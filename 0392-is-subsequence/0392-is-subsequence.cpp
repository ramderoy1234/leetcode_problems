#include<bits/stdc++.h>
class Solution {
  // int lcs(string &s,string &x,int n,int m,vector<vector<int>>&dp){
  //   if(n==0 ||m==0) return 0;
  //   if(dp[n][m]!=-1) return dp[n][m];

  //   if(s[n-1]==x[m-1]){
  //     dp[n][m]=lcs(s,x,n-1,m-1,dp)+1;
  //   }
  //   else{
  //     dp[n][m]=max(lcs(s,x,n,m-1,dp),lcs(s,x,n-1,m,dp));
  //   }
  //   return dp[n][m];
  // }
public:
    bool isSubsequence(string s, string t) {
       int n=s.size();
       int m=t.size();
      //  vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      //  int lenght=lcs(s,t,n,m,dp);
      //  if(n<=lenght){
      //   return true;
      //  }
      //  return false;
      vector<vector<int>>dp(n+1,vector<int>(m+1,0));

      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          if(s[i-1]==t[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
          }else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
        }
      }
      int lenght=dp[n][m];
      return n<=lenght?true:false;
    }
};