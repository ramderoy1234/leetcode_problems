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
        int sum_tar = sum / 2;
        vector<vector<int>>dp(n+1,vector<int>(sum_tar+1,-1));
        if (sum % 2 != 0) return false;

        return recursion(nums, sum_tar, nums.size(),dp);
        // for(int i=0;i<=n;i++){
        //   dp[i][0]=true;
        // }

        // for(int i=1;i<=n;i++){
        //   for(int j=1;j<=sum_tar;j++){
        //     if(nums[i-1]<=j){
        //       dp[i][j]=dp[i-1][j]|| dp[i][j-nums[i-1]];
        //     }
        //     else{
        //       dp[i][j]=dp[i-1][j];
        //     }
        //   }
        // }
        // return dp[n][sum_tar];
    }
};
