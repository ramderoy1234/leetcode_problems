class Solution {
    // const int mod = 1e9 + 7;
    int recursion(vector<int>& nums, int n, int target, vector<vector<int>>& dp) {
        if (n == -1) return target == 0 ? 1 : 0;
        if (dp[n][target] != -1) return dp[n][target];
        
        int notpick = recursion(nums, n - 1, target, dp);
        int pick = 0;
        if (nums[n] <= target) {
            pick = recursion(nums, n - 1, target - nums[n], dp);
        }
    
        dp[n][target] = (pick + notpick);
        return dp[n][target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum < target || (sum - target) % 2 != 0) return 0;
        int tar = (sum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return recursion(nums, n - 1, tar, dp);
    }
};
