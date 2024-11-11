class Solution {
    int recursion(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp) {
        if (n == 0) return grid[0][m];
        if (dp[n][m] != -1) return dp[n][m];
        int minCost = INT_MAX; 
        
        for (int j = 0; j < grid[0].size(); ++j) { // choose anyone in first row
            int fromCellValue = grid[n-1][j];   
            int costToMove = moveCost[fromCellValue][m];  
            int currentCost = recursion(n - 1, j, grid, moveCost, dp) + grid[n][m] + costToMove;
            minCost = min(minCost, currentCost);
        }
       return dp[n][m] = minCost; 
    }

public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int result = INT_MAX; 
        for (int j = 0; j < n; ++j) {
            result = min(result, recursion(m - 1, j, grid, moveCost, dp));
        }
    
        return result; 
    }
};
