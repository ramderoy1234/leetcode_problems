class Solution {
  int recursion(int index,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee){
    if(index>=prices.size()) return 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    int notpick=recursion(index+1,buy,prices,dp,fee);
    int maxi=0;
    if(buy){
      int buystock=-prices[index]+recursion(index+1,0,prices,dp,fee);
      maxi=max(buystock,notpick);
    }
    else{
      int sell=prices[index]-fee+recursion(index+1,1,prices,dp,fee);
      maxi=max(sell,notpick);
    }
    return dp[index][buy]=maxi;
  }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
      return recursion(0,1,prices,dp,fee);
    }
};