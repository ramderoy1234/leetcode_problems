class Solution {
    int recursion(int amount, vector<int>& coins, int n, vector<vector<int>>& dp) {
        if (amount == 0) return 1;
        if (n == 0) return 0;
  
        if (dp[n][amount] != -1) return dp[n][amount];
        int notpick = recursion(amount, coins, n - 1, dp);
        int pick = 0;
        if (coins[n - 1] <= amount) {
            pick = recursion(amount - coins[n - 1], coins, n, dp);
        }
        return dp[n][amount] = notpick + pick;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return recursion(amount, coins, n, dp);
    }
};
