class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }

    int findPar(int node) {
        if (parent[node] == node) 
            return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }

    void unionByrank(int u, int v) {
        int rootU = findPar(u);
        int rootV = findPar(v);
        if (rootU == rootV) return;

        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootV] > rank[rootU]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    bool connected(int u, int v) {
        return findPar(u) == findPar(v);
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU ds(n);
        vector<unsigned> cost(n, UINT_MAX);

        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            int rootU = ds.findPar(u);
            int rootV = ds.findPar(v);
            int newWt = cost[rootU] & cost[rootV] & w;
            ds.unionByrank(u, v);
            int rootNew = ds.findPar(u);
            cost[rootNew] = newWt; // Assign new minimum AND cost
        }

        // Process queries
        int m = query.size();
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++) {
            int s = query[i][0];
            int t = query[i][1];
            if (ds.connected(s, t))
                ans[i] = cost[ds.findPar(s)];
        }
        return ans;
    }
};

