class Solution {
    int recursion(int index, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(index >= prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        
        int notpick=recursion(index+1,buy,prices,dp);
        if(buy){
          int sell=prices[index]+recursion(index+1,0,prices,dp);
          dp[index][buy]=max(notpick,sell);
        }
        else{
          int buyStocks=-prices[index]+recursion(index+1,1,prices,dp);
          dp[index][buy]=max(notpick,buyStocks);
        }
        return dp[index][buy];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return recursion(0, 0, prices, dp);
    }
};
