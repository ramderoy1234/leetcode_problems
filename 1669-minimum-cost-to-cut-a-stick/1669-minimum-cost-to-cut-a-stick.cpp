class Solution {
int recursion(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
  if(i>j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  int mini=INT_MAX;
   for (int k = i; k <= j; k++) { 
        int cost=recursion(i,k-1,cuts,dp) +recursion(k+1,j,cuts,dp) +cuts[j+1]-cuts[i-1]; 
        mini = min(mini, cost); 
    }
  return dp[i][j]=mini;
}  
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0); 
        cuts.push_back(n); 
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size(); 
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return recursion(1, m - 2, cuts, dp);
    }
};