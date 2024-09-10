class Solution {
  int recursion(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
    if(index >= prices.size()) return 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    int notpick=recursion(index+1,buy ,prices, dp);
    int maxi=0;
    if(buy){
      int buystock=-prices[index]+recursion(index+1,0,prices,dp);
      maxi=max(buystock,notpick);
    }
    else{
      int sell=prices[index]+recursion(index+2,1,prices,dp);
      maxi=max(sell,notpick);
    }
    return dp[index][buy]=maxi;
  }
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      vector<vector<int>>dp(n,vector<int>(2,-1));
      return recursion(0,1,prices,dp);
    }
};