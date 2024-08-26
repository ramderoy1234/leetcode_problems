class Solution {
int  f(vector<int>&nums ,int n,vector<int>&dp){
  if(n==0) return 0;
  if(n==1) return nums[0];
  if(dp[n]!=-1) return dp[n];
  int skip=f(nums,n-1,dp);
  int add=nums[n-1]+f(nums,n-2,dp);
  return dp[n]=max(skip,add);
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(nums,n,dp);
    }
};