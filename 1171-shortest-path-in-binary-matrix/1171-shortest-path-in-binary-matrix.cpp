class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;  // (length, (row, col))
    
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1; 
        q.push({1, {0, 0}});
        visited[0][0] = 1;
        if (n == 1 && m == 1) return 1;
        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        while (!q.empty()) {
            int length = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if (row == n - 1 && col == m - 1) {
                return length;
            }
            for (auto& dir : directions) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && !visited[nrow][ncol] && grid[nrow][ncol] == 0) {
                    q.push({length + 1, {nrow, ncol}});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
};
