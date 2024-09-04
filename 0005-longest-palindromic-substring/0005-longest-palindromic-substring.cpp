class Solution {
 bool Palindrome(int i,int j,string &s,vector<vector<int>>&dp){
   if(i>=j) return true;
   if(dp[i][j]!=-1) return dp[i][j];
   if(s[i]==s[j]){
     dp[i][j]=Palindrome(i+1,j-1,s,dp);
   }
   else{
    dp[i][j]=false;
   }
   return dp[i][j];
 } 
public:
    string longestPalindrome(string s) {
      int n=s.size();
      vector<vector<int>>dp(n,vector<int>(n,-1));
      int maxLen=1;
      int start=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
          if(Palindrome(j,i,s,dp)){
            if(i-j+1>maxLen){
              maxLen=i-j+1;
              start=j;
            }
          }
        }
      }

      return s.substr(start,maxLen);
    }
};