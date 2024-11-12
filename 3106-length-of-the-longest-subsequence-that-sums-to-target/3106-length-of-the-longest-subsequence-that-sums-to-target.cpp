class Solution {
int recursion(vector<int>& nums, int n, int target, vector<vector<int>>& dp) {
        if (target==0) return 0;
        if(n==-1) return INT_MIN;
        if (dp[n][target] != -1) return dp[n][target];
        int notpick=recursion(nums,n-1,target,dp);
        int pick = INT_MIN;
        if (nums[n]<=target) {
            pick = recursion(nums,n-1,target-nums[n],dp);
            if(pick!=INT_MIN) pick+=1;
        }
        dp[n][target] = max(pick,notpick);
        return dp[n][target];
    }

public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans=recursion(nums,n-1,target,dp);
        return ans==INT_MIN?-1:ans;
    }
};