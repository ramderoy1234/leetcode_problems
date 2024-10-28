class Solution {
    bool dfs(int row, int col, int index, vector<vector<char>>& board, string& word) {
        if (index == word.size()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }
        char visited = board[row][col];
        board[row][col] = '1'; 
        bool found = dfs(row + 1, col, index + 1, board, word) ||
                     dfs(row - 1, col, index + 1, board, word) ||
                     dfs(row, col + 1, index + 1, board, word) ||
                     dfs(row, col - 1, index + 1, board, word);

        board[row][col] = visited;
        return found;         
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
