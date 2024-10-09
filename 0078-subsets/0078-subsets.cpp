class Solution {
public:
    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
        // Base case: if index reaches the end of the nums array
        if (index == nums.size()) {
            ans.push_back(current); // Add the current subset to the answer
            return;
        }

        // Exclude the current element and move to the next
        generateSubsets(index + 1, nums, current, ans);

        // Include the current element in the subset
        current.push_back(nums[index]);
        generateSubsets(index + 1, nums, current, ans);

        // Backtrack: remove the element after recursion
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        generateSubsets(0, nums, current, ans);  // Start the recursion
        return ans;
    }
};

