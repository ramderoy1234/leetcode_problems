class Solution {
    int recursion(int n,vector<int>& coins, int amount,vector<vector<int>>&dp){
        if(n==0) return INT_MAX-1;
        if(amount==0) return 0;
        if(dp[n][amount]!=-1) return dp[n][amount];
        int notpick=recursion(n-1,coins,amount,dp);
        int pick=INT_MAX;
        if(coins[n-1]<=amount){
            pick=recursion(n,coins,amount-coins[n-1],dp);
            if(pick!=INT_MAX) pick+=1;
        }
        dp[n][amount]=min(pick,notpick);
        return dp[n][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= recursion(n,coins,amount,dp);
        return ans==INT_MAX-1?-1:ans;
    }
};