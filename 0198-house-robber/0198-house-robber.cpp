class Solution {
  int recursion(int n, vector<int>&nums,vector<int>&dp){
    if(n==0) return 0;
    if(n==1) return nums[0];
    if(dp[n]!=-1) return dp[n];
    int skip=recursion(n-1,nums,dp);
    int add=nums[n-1]+recursion(n-2,nums,dp);
    return dp[n]=max(add,skip);
  }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return recursion(n,nums,dp);
    }
};