
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
         int n = nums.size();
    if (n == 0) return {};

    std::vector<int> left_max(n), right_max(n);
    
    // Precompute the max in each block from left to right
    for (int i = 0; i < n; ++i) {
        if (i % k == 0) {
            left_max[i] = nums[i]; // Start of a block
        } else {
            left_max[i] = std::max(left_max[i - 1], nums[i]);
        }
    }

    // Precompute the max in each block from right to left
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1 || (i + 1) % k == 0) {
            right_max[i] = nums[i]; // End of a block
        } else {
            right_max[i] = std::max(right_max[i + 1], nums[i]);
        }
    }

    std::vector<int> sliding_max;
    for (int i = 0; i <= n - k; ++i) {
        sliding_max.push_back(std::max(left_max[i + k - 1], right_max[i]));
    }

    return sliding_max;
    }
};

