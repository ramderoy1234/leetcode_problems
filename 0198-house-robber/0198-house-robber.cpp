class Solution {
    int recur(int index, vector<int>& nums, vector<int>& dp) {
        if(index==0) return nums[0];
        if(index==1) return max(nums[0],nums[1]);
        if(dp[index]!=-1) return dp[index];

        int robcurr=nums[index]+recur(index-2,nums,dp);
        int skip=recur(index-1,nums,dp);
        return dp[index]=max(skip,robcurr);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 
        if (n == 1) return nums[0];  

        vector<int> dp(n+1, -1);  
        return recur(n - 1, nums, dp); 
    }
};
