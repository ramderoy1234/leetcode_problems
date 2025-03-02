class Solution {
  bool recursion(int n,vector<int>&nums,int sum,vector<vector<int>>&dp){
    if(sum==0) return true;
    if(n==0 || sum<0) return false;
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(nums[n-1]<=sum){
      dp[n][sum]=recursion(n-1,nums,sum-nums[n-1],dp) || recursion(n-1,nums,sum,dp);
    }
    else{
      dp[n][sum]=recursion(n-1,nums,sum,dp);
    }
    return dp[n][sum];
  }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
          sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return recursion(n,nums,target,dp);
    }
};