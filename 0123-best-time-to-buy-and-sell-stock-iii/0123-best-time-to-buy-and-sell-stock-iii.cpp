class Solution {
    int recursion(int index, int buy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (index >= prices.size() || cnt==2) return 0;
        if (dp[index][cnt][buy] !=-1) return dp[index][cnt][buy]; 
        int notpick = recursion(index + 1, buy, cnt, prices, dp);
        if (buy) {
            int buyStock = -prices[index] + recursion(index + 1, 0, cnt, prices, dp);
            dp[index][cnt][buy] = max(notpick, buyStock);
        } else {
            int sellStock = prices[index] + recursion(index + 1, 1, cnt + 1, prices, dp);
            dp[index][cnt][buy] = max(notpick, sellStock);
        }
        return dp[index][cnt][buy];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1))); 
        return recursion(0, 1, 0, prices, dp); 
    }
};
