class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited, queue<pair<int, int>>& que) {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || visited[row][col]) {
            return;
        }
        visited[row][col] = 1;
        que.push({row, col}); 

        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};

        for (int i = 0; i < 4; i++) {
            int nrow = row+ drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(grid, nrow, ncol, visited, que);
            }
        }
    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, queue<pair<int, int>>& que) {
        int level = 0;
        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};
        while (!que.empty()) {
            int L = que.size();
            while (L--) {
                auto [row, col] = que.front();
                que.pop();
                for (int i = 0;  i< 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol]) {
                        if (grid[nrow][ncol] == 1) {
                            return level;  // Found the second island
                        }
                        visited[nrow][ncol] = 1;
                        que.push({nrow, ncol});
                    }
                }
            }
            level++;
        }
        return level;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> que;
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <m; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, visited, que);  // Mark one island as visited and push boundary cells to queue
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        return bfs(grid, visited, que);
    }
};
