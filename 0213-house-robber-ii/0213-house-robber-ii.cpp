class Solution {
  int recursion(int n,int start, vector<int>&nums,vector<int>&dp){
    if(n<start) return 0;
    if(n==start) return nums[start];
    if(dp[n]!=-1) return dp[n];
    int no=recursion(n-1,start,nums,dp);
    int add=nums[n]+recursion(n-2,start,nums,dp);
    return dp[n]=max(no,add);
  }
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==1) return nums[0];
      vector<int>dp1(n+1,-1);
      vector<int>dp2(n+1,-1);
      int no=recursion(n-1,1,nums,dp1);
      int add=recursion(n-2,0,nums,dp2);
      return max(no,add);
    }
};