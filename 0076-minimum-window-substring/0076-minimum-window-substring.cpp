class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> mpt;
        for (char c : t) mpt[c]++; // Store frequency of characters in t
        
        int i = 0, j = 0, minLen = INT_MAX, start = 0, required = t.size();
        unordered_map<char, int> mp;

        while (j < s.size()) {
            // If s[j] is in t, decrease the required count
            if (mpt[s[j]] > 0) {
                mp[s[j]]++;
                if (mp[s[j]] <= mpt[s[j]]) required--;
            }

            // When all characters of t are found in the window
            while (required == 0) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                // Try to shrink the window from left
                if (mpt[s[i]] > 0) {
                    mp[s[i]]--;
                    if (mp[s[i]] < mpt[s[i]]) required++;
                }

                i++; // Move left pointer
            }
            j++; // Move right pointer
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
