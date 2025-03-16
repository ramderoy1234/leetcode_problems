class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle); //   finding `needle` inside `haystack`
        return (index != string::npos) ? index : -1; // Return index if found, else -1
    }
};
