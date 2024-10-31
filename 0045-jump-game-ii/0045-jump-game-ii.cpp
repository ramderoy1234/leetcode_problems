class Solution {
    int recursion(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size() - 1) return 0; 
        if (dp[i] != -1) return dp[i];
        
        int minJumps = INT_MAX;
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < nums.size()) {
                int jumps = recursion(i + j, nums, dp);
                if (jumps != INT_MAX) {
                    minJumps = min(minJumps, jumps + 1); 
                }
            }
        }
        
        return dp[i] = minJumps;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recursion(0, nums, dp);
    }
};
