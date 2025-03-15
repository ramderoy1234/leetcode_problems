 
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        // Binary search on capability
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            bool skip = false;

            // Check if it's possible to rob at least k houses with max money ≤ mid
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid && !skip) {
                    count++;
                    skip = true;  // Skip the next house to avoid adjacency
                } else {
                    skip = false;
                }
            }
 
            if (count >= k) {
                right = mid;  
            } else {
                left = mid + 1;  // Increase capability if we can't rob k houses
            }
        }

        return left;
    }
};
