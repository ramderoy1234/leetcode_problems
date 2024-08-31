class Solution {
    int recursion(int index, int buy, int cnt, vector<int>& prices, vector<vector<vector<int>>>& dp, int k) {
        if (index >= prices.size() || cnt == k) return 0;
        if (dp[index][cnt][buy] != -1) return dp[index][cnt][buy];
        int notpick = recursion(index + 1, buy, cnt, prices, dp, k);

        if (buy) {
            int buyStock = -prices[index] + recursion(index + 1, 0, cnt, prices, dp, k);
            dp[index][cnt][buy] = max(buyStock, notpick);
        } else {
            int sellStock = prices[index] + recursion(index + 1, 1, cnt + 1, prices, dp, k);
            dp[index][cnt][buy] = max(sellStock, notpick);
        }
        return dp[index][cnt][buy];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1))); 
        return recursion(0, 1, 0, prices, dp, k);
    }
};
