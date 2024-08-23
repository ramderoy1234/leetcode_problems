class Solution {
    // int recursion(vector<int>& nums1, vector<int>& nums2, int n, int m, vector<vector<int>>& dp, int& maxLength) {
    //     if (n == 0 || m == 0) return 0; 

    //     if (dp[n][m] != -1) return dp[n][m];  

    //     if (nums1[n - 1] == nums2[m - 1]) {
    //         dp[n][m] = 1 + recursion(nums1, nums2, n - 1, m - 1, dp, maxLength);
    //         maxLength = max(maxLength, dp[n][m]); 
    //     } else {
    //         dp[n][m] = 0;  
    //     }

    //     return dp[n][m];
    // }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 
        // int maxLength = 0; 
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         recursion(nums1, nums2, i, j, dp, maxLength);
        //     }
        // }
        // return maxLength; 
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       
        int maxi=0;
        for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
            if(nums1[i-1]==nums2[j-1]){
              dp[i][j]=dp[i-1][j-1]+1;
              maxi=max(maxi,dp[i][j]);
            }
            else{
              dp[i][j]=0;
            }
          }
        }
        return maxi;
    }
};
