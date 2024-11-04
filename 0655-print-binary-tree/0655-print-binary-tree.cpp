class Solution {
    int getHeight(TreeNode* root) {
        if (!root) return -1;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);  
        int m = height + 1;  
        int n = pow(2, height + 1) - 1; 
        vector<vector<string>> res(m, vector<string>(n, ""));
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, (n - 1) / 2}}); 
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int row = pos.first;
            int col = pos.second;
            res[row][col] = to_string(node->val);

            if (node->left) {
                q.push({node->left, {row + 1, col - pow(2, height - row - 1)}});
            }
            if (node->right) {
                q.push({node->right, {row + 1, col + pow(2, height - row - 1)}});
            }
        }
        
        return res;
    }
};