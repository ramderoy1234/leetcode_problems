class Solution {
int lcs(int n,int m,string &s,string &x,vector<vector<int>>&dp){
  if(n==0|| m==0) return 0;
  if(dp[n][m]!=-1) return dp[n][m];
  if(s[n-1]==x[m-1]){
    dp[n][m]=lcs(n-1,m-1,s,x,dp)+1;
  }
  else{
    dp[n][m]=max(lcs(n-1,m,s,x,dp),lcs(n,m-1,s,x,dp));
  }
  return dp[n][m];
}  
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int lenght=lcs(n,m,word1,word2,dp);
        return (n-lenght)+(m-lenght);
    }
};