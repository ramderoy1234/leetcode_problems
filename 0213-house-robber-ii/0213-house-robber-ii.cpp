class Solution {
    int recursion(vector<int>& nums, int index, int start, vector<int>& dp) {
        if (index < start) return 0;
        if (index == start) return nums[start];
        if (dp[index] != -1) return dp[index];
        
        int add = nums[index] + recursion(nums, index - 2, start, dp);
        int no = recursion(nums, index - 1, start, dp);
        return dp[index] = max(no, add);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        
        int no = recursion(nums, n - 2, 0, dp1);
        int add = recursion(nums, n - 1, 1, dp2);
        
        return max(no, add);
    }
};
