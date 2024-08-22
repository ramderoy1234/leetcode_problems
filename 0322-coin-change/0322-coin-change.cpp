class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                // Do not take the coin
                dp[i][j] = dp[i - 1][j];

                //  Take the coin if possible
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
