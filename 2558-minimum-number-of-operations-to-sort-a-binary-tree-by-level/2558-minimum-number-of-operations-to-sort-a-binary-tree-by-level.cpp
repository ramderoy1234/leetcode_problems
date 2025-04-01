class Solution {
public:
    int minSwapsToSort(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({arr[i], i});
        }

        sort(temp.begin(), temp.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        // Count cycles in the graph formed by index movements
        for (int i = 0; i < n; i++) {
            if (visited[i] || temp[i].second == i) continue;  // Already in place
            
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = temp[j].second;
                cycle_size++;
            }

            if (cycle_size > 1) swaps += (cycle_size - 1);
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int total_swaps = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<int> levelValues;

            // Process one level
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                levelValues.push_back(temp->val);

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            // Find min swaps to sort this level
            total_swaps += minSwapsToSort(levelValues);
        }
        return total_swaps;
    }
};
