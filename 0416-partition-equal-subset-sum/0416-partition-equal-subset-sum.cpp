class Solution {
    bool recursion(vector<int>& nums, int sum, int n,vector<vector<int>>&dp) {
        if (sum == 0) return true; 
        if (n == 0 || sum < 0) return false; 
        if(dp[n][sum]!=-1) return dp[n][sum];
        return dp[n][sum]=recursion(nums, sum - nums[n - 1], n - 1,dp) || recursion(nums, sum, n - 1,dp);
    }
    
public:
    bool canPartition(vector<int>& nums) {
      int n=nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        if (sum % 2 != 0) return false;
        int sum_tar = sum / 2;

        return recursion(nums, sum_tar, nums.size(),dp);
    }
};
