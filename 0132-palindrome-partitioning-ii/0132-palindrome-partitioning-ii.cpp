class Solution {
private:
    int recursion(int i, int j, string &s, vector<vector<int>>& dp) {
        if (i >= j) return 0; 
        if (dp[i][j] != -1) return dp[i][j];
        if (isPalindrome(s, i, j)) return dp[i][j] = 0;
        int mini = INT_MAX;
        for (int k = i; k < j; k++) {
            if (isPalindrome(s, i, k)) {
                int cost = 1 + recursion(k + 1, j, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i][j] = mini;
    }

    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recursion(0, n - 1, s, dp);
    }
};
