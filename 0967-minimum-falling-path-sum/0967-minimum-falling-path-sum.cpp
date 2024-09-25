class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        vector<vector<int>>dp=matrix;
        for(int i=n-2;i>=0;i--){
          for(int j=0;j<n;j++){
            int down=dp[i+1][j];
            int leftDia=(j>0)?dp[i+1][j-1]:INT_MAX;
            int rightDia=(j<n-1)?dp[i+1][j+1]:INT_MAX;
            dp[i][j]+=min({down,leftDia,rightDia});
          }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
          mini=min(mini,dp[0][j]);
        }
        return mini;
    }
};