#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent;
    
public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findparent(parent[node]);  // Path compression
    }

    void unionByRank(int u, int v) {
        int pt_u = findparent(u);
        int pt_v = findparent(v);

        if (pt_u == pt_v) return;  // They are already in the same component

        if (rank[pt_u] < rank[pt_v]) {
            parent[pt_u] = pt_v;
        } else if (rank[pt_u] > rank[pt_v]) {
            parent[pt_v] = pt_u;
        } else {
            parent[pt_v] = pt_u;
            rank[pt_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int extraEdges = 0;

        // Process all connections
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            if (ds.findparent(u) == ds.findparent(v)) {
                extraEdges++;  // This edge is extra
            } else {
                ds.unionByRank(u, v);  // Union the components
            }
        }

        // Count the number of components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findparent(i) == i) {
                components++;
            }
        }

        // We need (components - 1) edges to connect all components
        if (extraEdges >= components - 1) {
            return components - 1;
        } else {
            return -1;  // Not enough extra edges
        }
    }
};
