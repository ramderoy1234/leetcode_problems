class Solution {
  int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    int drow[] = {0, 1, 0, -1};
    int dcol[] = {-1, 0, 1, 0};
    
    visited[row][col] = 1;
    int area = 1;  // Each call represents one land cell
    
    for (int i = 0; i < 4; i++) {
      int nrow = drow[i] + row;
      int ncol = dcol[i] + col;
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
         area += dfs(nrow, ncol, grid, visited);
      }
    }
    return area;
  }

public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          maxArea = max(maxArea, dfs(i, j, grid, visited));
        }
      }
    }
    return maxArea;
  }
};
