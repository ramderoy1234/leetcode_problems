class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        // Count how many times each answer appears
        for (int ans : answers) {
            freq[ans]++;
        }

        int totalRabbits = 0;
        for (auto& [x, count] : freq) {
            int groupSize = x + 1; // each group can only have x+1 rabbits
            int numGroups = (count + groupSize - 1) / groupSize; // ceil(count / groupSize)
            totalRabbits += numGroups * groupSize; // total rabbits in all such groups
        }

        return totalRabbits;
    }
};
