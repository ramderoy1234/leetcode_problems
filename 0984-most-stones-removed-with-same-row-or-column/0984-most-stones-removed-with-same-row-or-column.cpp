class DisjointSet {
    vector<int> rank, parents;
public:
    DisjointSet(int n) {
        rank.resize(n, 0); // Initialize rank to 0
        parents.resize(n);  // Resize parents to size n
        for (int i = 0; i < n; i++) {
            parents[i] = i; // Initialize each node's parent to itself
        }
    }

    int findPar(int node) {
        if (parents[node] == node) {
            return node;
        }
        return parents[node] = findPar(parents[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);

        if (parU == parV) return; // Already in the same set

        // Union by rank
        if (rank[parU] < rank[parV]) {
            parents[parU] = parV;
        } else if (rank[parV] < rank[parU]) {
            parents[parV] = parU;
        } else {
            parents[parV] = parU;
            rank[parU]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxiRow = 0, maxiCol = 0;

        // Find the maximum row and column indices in the stones list
        for (auto& it : stones) {
            maxiRow = max(maxiRow, it[0]);
            maxiCol = max(maxiCol, it[1]);
        }

        // Initialize the disjoint set with enough space for all rows and columns
        DisjointSet ds(maxiRow + maxiCol + 2); // +1 for safety

        unordered_map<int, int> mp;

        // Union stones by their rows and columns
        for (auto& it : stones) {
            int row = it[0];
            int col = it[1] + maxiRow + 1; // Shift column index to avoid conflicts with row indices
            ds.unionByRank(row, col);
            mp[row] = 1;
            mp[col] = 1;
        }

        // Count the number of connected components
        int cnt = 0;
        for (auto& it : mp) {
            if (ds.findPar(it.first) == it.first) {
                cnt++;
            }
        }

        // Return the number of stones that can be removed
        return n - cnt;
    }
};
