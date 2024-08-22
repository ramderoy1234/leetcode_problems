class Solution {
    int recursion(const vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (n == 0) return INT_MAX - 1;
        if (dp[n][amount] != -1) return dp[n][amount];
        int exclude = recursion(coins, amount, n-1, dp);
        int include = INT_MAX;
        if (coins[n-1] <= amount) {
            include = recursion(coins, amount - coins[n-1], n, dp);
            if (include != INT_MAX) include += 1;
        }

        dp[n][amount] = min(exclude, include);
        return dp[n][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int result = recursion(coins, amount, n, dp);
        return result == INT_MAX - 1 ? -1 : result;
    }
};
