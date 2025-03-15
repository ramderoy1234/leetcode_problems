class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size(); // Number of voters
        vector<vector<int>> v(26, vector<int>(votes[0].size(), 0)); 
        // Stores the count of votes for each position

        // Count votes for each team at each rank
        for (int i = 0; i < n; i++) {   
            for (int j = 0; j < votes[0].size(); j++) {
                int x = votes[i][j] - 'A'; // Convert character to index
                v[x][j]++; // Increase count for the team at position j
            }
        }

        string res = votes[0]; // Start with initial order of teams
        // Sort teams based on ranking rules
        sort(res.begin(), res.end(), [&](char &a, char &b) {
            if (v[a - 'A'] != v[b - 'A']) { // Compare votes for each rank
                return v[a - 'A'] > v[b - 'A']; // Higher votes = higher rank
            }
            return a < b; // If votes are the same, sort alphabetically
        });

        return res; // Return sorted ranking
    }
};
