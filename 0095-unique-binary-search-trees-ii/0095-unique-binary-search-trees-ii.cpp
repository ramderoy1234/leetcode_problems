class Solution {
    map<pair<int, int>, vector<TreeNode*>>dp;
    vector<TreeNode*> solve(int start, int end) {
        if (start > end) return {nullptr};

        if (dp.count({start, end})) return dp[{start, end}];

        vector<TreeNode*> ans;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = solve(start, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);

            for (auto& leftBT : left) {
                for (auto& rightBT : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftBT;
                    root->right = rightBT;
                    ans.push_back(root);
                }
            }
        }

        return dp[{start, end}] = ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return solve(1, n);
    }
};
