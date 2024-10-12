class Solution {
    vector<int> rank, parent;
public:
    Solution() {}
    Solution(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }
    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);

        if (parU != parV) {
            if (rank[parU] < rank[parV]) {
                parent[parU] = parV;
            } else if (rank[parU] > rank[parV]) {
                parent[parV] = parU;
            } else {
                parent[parV] = parU;
                rank[parU]++;
            }
        }
    }
    // Function to determine the minimum number of operations to make the network connected
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1; 
        }
        // Initialize union-find
        Solution dsu(n);
        int components = n;
        int redundant = 0;  
        for (const auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            if (dsu.findPar(u) != dsu.findPar(v)) {
                dsu.unionByRank(u, v);
                components--; 
            } else {
                redundant++;  
            }
        }
        if (redundant >= components - 1) {
            return components - 1;
        } else {
            return -1; 
        }
    }
};
