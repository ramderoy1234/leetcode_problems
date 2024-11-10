class Solution {
    const int mod = 1e9 + 7;

    int recursion(int s, int e, int k, vector<vector<int>>& dp) {
        if (k == 0) return s == e ? 1 : 0;
        if (dp[s + 1000][k] != -1) return dp[s + 1000][k];
        
        int right = recursion(s + 1, e, k - 1, dp);
        int left = recursion(s - 1, e, k - 1, dp);

        return dp[s + 1000][k] = (right + left) % mod;
    }
public:
    int numberOfWays(int s, int e, int k) {
        vector<vector<int>> dp(3000, vector<int>(k + 1, -1)); // Using an offset for negative indices
        return recursion(s, e, k, dp);
    }
};
