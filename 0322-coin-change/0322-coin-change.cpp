class Solution {
  int recursion(int n,int amount,vector<int>&nums,vector<vector<int>>&dp){
    if(n==0) return INT_MAX-1;
    if(amount==0) return 0;
    if(dp[n][amount]!=-1) return dp[n][amount];
    int exclude=recursion(n-1,amount,nums,dp);
    int include=INT_MAX;
    if(nums[n-1]<=amount){
      include=recursion(n,amount-nums[n-1],nums,dp);
      if(include!=INT_MAX-1) include+=1;
    }
    int mini=min(include,exclude);
   return  dp[n][amount]=mini;
  }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
       int ans=recursion(n,amount,coins,dp);
       return ans==INT_MAX-1?-1:ans; 

    }
};