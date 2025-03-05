class Solution {
  int recursion(int index,int buy,int cnt,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
    if(index>=prices.size() || cnt==k) return 0;
    if(dp[index][cnt][buy]!=-1) return dp[index][cnt][buy];
    int notPick=recursion(index+1,buy,cnt,k,prices,dp);
    if(buy){
      int buy_stock=-prices[index]+recursion(index+1,0,cnt,k,prices,dp);
      dp[index][cnt][buy]=max(notPick,buy_stock);
    }
    else{
      int sell=prices[index]+recursion(index+1,1,cnt+1,k,prices,dp);
      dp[index][cnt][buy]=max(notPick,sell);
    }
    return dp[index][cnt][buy];
  }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(3,-1)));
        
        return recursion(0,1,0,k,prices,dp);
    }
};