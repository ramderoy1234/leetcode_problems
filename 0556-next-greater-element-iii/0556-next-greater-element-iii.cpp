class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();

        int i = len - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;  // found less element
        }

        if (i < 0) {
            return -1;
        }

        // Step 2: Find the smallest digit on right side of i that is larger than s[i]
        int j = len - 1;
        while (s[j] <= s[i]) {
            j--;
        }
        // Step 3: Swap digits at i and j
        swap(s[i], s[j]);

        reverse(s.begin() + i + 1, s.end());
        long long result = stoll(s);

        return (result > INT_MAX) ? -1 :result; 
    }
};
