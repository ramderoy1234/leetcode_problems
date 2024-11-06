class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};   
        
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int maxi = INT_MIN; 
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                maxi = max(maxi, temp->val);
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            ans.push_back(maxi); 
        }
        
        return ans;
    }
};
