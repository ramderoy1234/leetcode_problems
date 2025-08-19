#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int i, j;

        // check upper-left diagonal ↖
        i = row; j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--; j--;
        }

        // check left side ←
        j = col;
        while (j >= 0) {
            if (board[row][j] == 'Q') return false;
            j--;
        }

        // check lower-left diagonal ↙
        i = row; j = col;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i++; j--;
        }
        return true; 
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';      
                solve(col + 1, board, ans, n);
                board[row][col] = '.';    
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};
