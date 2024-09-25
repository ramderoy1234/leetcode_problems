class Solution {
  int recursion(int index,int buy, vector<int>&prices,vector<vector<int>>&dp){
    if(index>=prices.size()) return 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    int maxi=0;
    int notpick=recursion(index+1,buy,prices,dp);
    if(buy){
      int buy_stock=-prices[index]+recursion(index+1,0,prices,dp);
      maxi=max(notpick,buy_stock);
    }
    else{
      int sell=prices[index]+recursion(index+1,1,prices,dp);
      maxi=max(notpick,sell);
    }
    return dp[index][buy]=maxi;
  }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return recursion(0,1,prices,dp);
    }
};