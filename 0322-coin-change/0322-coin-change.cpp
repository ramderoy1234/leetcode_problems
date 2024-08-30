class Solution {
  // int recursion(int n,int amount,vector<int>&nums,vector<vector<int>>&dp){
  //   if(n==0) return INT_MAX-1;
  //   if(amount==0) return 0;
  //   if(dp[n][amount]!=-1) return dp[n][amount];
  //   int exclude=recursion(n-1,amount,nums,dp);
  //   int include=INT_MAX;
  //   if(nums[n-1]<=amount){
  //     include=recursion(n,amount-nums[n-1],nums,dp);
  //     if(include!=INT_MAX-1) include+=1;
  //   }
  //   int mini=min(include,exclude);
  //  return  dp[n][amount]=mini;
  // }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
      //   vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
      //  int ans=recursion(n,amount,coins,dp);
      //  return ans==INT_MAX-1?-1:ans; 

        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
     for (int i = 0; i <= n; i++) {
           dp[i][0] = 0; 
       }

for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= amount; j++) {
        dp[i][j] = dp[i - 1][j]; 
        if (coins[i - 1] <= j) { 
            int include = dp[i][j - coins[i - 1]]; 
            if (include != INT_MAX) { 
                dp[i][j] = min(dp[i][j], include + 1);
            }
        }
    }
}

      return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};