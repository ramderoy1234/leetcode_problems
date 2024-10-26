class Solution {
    void recursion(int i, vector<int>& nums, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums); 
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);     // Swap to create a new permutation
            recursion(i + 1, nums, ans);
            swap(nums[i], nums[j]);     // Backtrack to original configuration
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recursion(0, nums, ans); 
        return ans; 
    }
};
