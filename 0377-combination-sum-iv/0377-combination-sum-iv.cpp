class Solution {
  int recursion(vector<int>& nums, int target, vector<int>& dp) {
    if (target == 0) return 1;  
    if (target < 0) return 0;
    if (dp[target] != -1) return dp[target];  

    int cnt= 0;
    for (int num : nums) {  
       cnt+= recursion(nums, target - num, dp);  
    }

    return dp[target] =cnt; 
  }

public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, -1); 
    return recursion(nums, target, dp);
  }
};
