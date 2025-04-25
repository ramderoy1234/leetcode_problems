class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> countMap;
        countMap[0] = 1;  // base case: when count is 0

        int currCnt = 0;
        long long res = 0;

        for (int num : nums) {
            // If current number satisfies the condition
            if (num % modulo == k) {
                currCnt++;
            }

            // Find required key
            int key = (currCnt - k + modulo) % modulo;

            // If that key was seen before, add its count
            if (countMap.count(key)) {
                res += countMap[key];
            }

            // Update current prefix count modulo
            countMap[currCnt % modulo]++;
        }

        return res;
    }
};
