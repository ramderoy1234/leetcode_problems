class Solution {
// int recursion(int n,vector<int>&nums,int tar_sum,vector<vector<int>>&dp){
//     if(n==0) return 0;
//     if(tar_sum==0) return 1;
//     if(dp[n][tar_sum]!=-1) return dp[n][tar_sum];
//     if(nums[n-1]<=tar_sum){
//       dp[n][tar_sum]=recursion(n-1,nums,tar_sum-nums[n-1],dp)|| recursion(n-1,nums,tar_sum,dp);
//     }
//     else{
//       dp[n][tar_sum]=recursion(n-1,nums,tar_sum,dp);
//     }
//     return dp[n][tar_sum];
// }  
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
          sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int tar_sum=sum/2;
        // vector<vector<int>>dp(n+1,vector<int>(tar_sum+1,-1));
        // return recursion(n,nums,tar_sum,dp);

        vector<vector<int>>dp(n+1,vector<int>(tar_sum+1,0));
        for(int i=0;i<=n;i++){
          dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
          for(int j=1;j<=tar_sum;j++){
            if(nums[i-1]<=j){
              dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }else{
              dp[i][j]=dp[i-1][j];
            }
          }
        }
        return dp[n][tar_sum];
    }
};