class Solution {
    void recursion(int i, vector<vector<int>>& ans, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            recursion(i + 1, ans, nums);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        recursion(0, ans, nums);
        sort(ans.begin(), ans.end());  // Sort before removing duplicates
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
