class Solution {
  int recursion(int index,int buy, vector<int>&arr,vector<vector<int>>&dp){
    if(index >= arr.size()) return 0;
    if(dp[index][buy]!=-1) return dp[index][buy];
    int notpick=recursion(index+1,buy,arr,dp);
    int maxi=0;
    if(buy){
      int buy_today=-arr[index]+recursion(index+1,0,arr,dp);
      maxi=max(notpick,buy_today);
     
    }
    else{
       int sell=arr[index]+recursion(index+1,1,arr,dp);
       maxi=max(sell,notpick);
    }
    return dp[index][buy]=maxi;
  }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return recursion(0,1,prices,dp);
    }
};