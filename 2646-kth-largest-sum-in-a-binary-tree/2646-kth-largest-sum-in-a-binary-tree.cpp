class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> ans;
        
        while (!q.empty()) {
            int n = q.size();
            long long sum = 0; 
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                
                sum += temp->val; 
            }
            
            ans.push_back(sum);  
        }
        sort(ans.begin(), ans.end(), greater<long long>());  
        if (k > ans.size()) return -1;
        return ans[k - 1]; 
    }
};
