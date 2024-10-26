class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int sum = nums[0];
        int total = nums[0]; 
        for (int i = 1; i < n; i++) {
            total += nums[i]; 
            sum = max(sum + nums[i], nums[i]); 
            maxSum = max(sum, maxSum); 
        }

    
        int minSum = nums[0];
        int sumMin = nums[0];
        for (int i = 1; i < n; i++) {
            sumMin = min(sumMin + nums[i], nums[i]); 
            minSum = min(sumMin, minSum);  
        }

        // where all elements are negative
        if (total == minSum) {
            return maxSum;  // If all elements are negative
        }

        return max(maxSum, total - minSum);
    }
};
