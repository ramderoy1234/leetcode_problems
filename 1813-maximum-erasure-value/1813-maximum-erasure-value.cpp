class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> mp;
        int i = 0;
        int sum = 0;
        int maxSum = 0;
        for (int j = 0; j < nums.size(); j++) {
            while (mp.find(nums[j]) != mp.end()) {
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }
            
            mp.insert(nums[j]);
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
