class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<set<char>, int> freqMap; // Map to store unique character sets and their frequency
        int count = 0;

        for (const string& word : words) {
            set<char> charSet(word.begin(), word.end()); // Convert word into a unique character set
            count += freqMap[charSet]; // Add pairs with same character set
            freqMap[charSet]++; // Increase frequency count
        }

        return count;
    }
};
