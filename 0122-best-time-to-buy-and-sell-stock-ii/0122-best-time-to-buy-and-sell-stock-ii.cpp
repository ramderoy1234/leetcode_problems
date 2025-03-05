class Solution {
    int recursion(int index,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int notPick=recursion(index+1,buy,prices,dp);
        int maxi=INT_MIN;
        if(buy){
            int buy_Stock=-prices[index]+recursion(index+1,0,prices,dp);
            maxi=max(notPick,buy_Stock);
        }
        else{
            int sell=prices[index]+recursion(index+1,1,prices,dp);
            maxi=max(notPick,sell);
        }
        return dp[index][buy]=maxi;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return recursion(0,1,prices,dp);
    }
};