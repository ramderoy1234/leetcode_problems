#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited, int drow[], int dcol[]) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1; // Mark the starting cell as visited

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                    visited[nrow][ncol] = 1; 
                    q.push({nrow, ncol}); 
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return; 
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        //  first and last row
        for (int i = 0; i < m; i++) {
            if (!visited[0][i] && board[0][i] == 'O') {
                bfs(0, i, board, visited, drow, dcol);
            }
            if (!visited[n - 1][i] && board[n - 1][i] == 'O') {
                bfs(n - 1, i, board, visited, drow, dcol);
            }
        }

        //  first and last column
        for (int j = 0; j < n; j++) {
            if (!visited[j][0] && board[j][0] == 'O') {
                bfs(j, 0, board, visited, drow, dcol);
            }
            if (!visited[j][m - 1] && board[j][m - 1] == 'O') {
                bfs(j, m - 1, board, visited, drow, dcol);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X'; 
                }
            }
        }
    }
};
