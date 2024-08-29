class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        vector<vector<int>> dp = matrix;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int down = dp[i + 1][j];  // Directly below
                int left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;  // Diagonally left below
                int right = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;  // Diagonally right below

                dp[i][j] +=min({down, left, right});
            }
        }

        int min_path = INT_MAX;
        for (int j = 0; j < n; ++j) {
            min_path= std::min(min_path, dp[0][j]);
        }

        return min_path;
    }
};
