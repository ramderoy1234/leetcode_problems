class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> validGenes(bank.begin(), bank.end()); 
        if (!validGenes.count(endGene)) return -1;
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        char choices[4] = {'A', 'C', 'G', 'T'}; 

        while (!q.empty()) {
            string first = q.front().first;  
            int second = q.front().second; 
            q.pop();

            if (first == endGene) return second;

            for (int i = 0; i < 8; i++) { 
                char original = first[i];

                for (char c : choices) {  
                    if (c == original) continue;  
                    first[i] = c;

                    if (validGenes.count(first)) { // If valid mutation
                        q.push({first, second + 1});
                        validGenes.erase(first); // Remove to avoid revisiting
                    }
                }
                first[i] = original; 
            }
        }
        return -1;
    }
};
