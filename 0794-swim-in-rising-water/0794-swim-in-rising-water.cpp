class DSU {
    vector<int> rank, parent;

public:
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    bool connected(int u, int v) {
        return findPar(u) == findPar(v);
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n * n);
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {-1, 0, 1, 0};

        vector<pair<int, pair<int, int>>> cells;
        for (int i = 0; i < n; ++i) {
           for (int j = 0; j < n; ++j) {
             cells.push_back({grid[i][j], {i, j}});
            }
        }
        
        sort(cells.begin(), cells.end());
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (auto& it : cells) {
            int h = it.first;
            int i = it.second.first;
            int j = it.second.second;
            visited[i][j] = true;
            int curr = i * n + j;

            for (int d = 0; d < 4; ++d) {
                int ni = i + drow[d];
                int nj = j + dcol[d];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && visited[ni][nj]) {
                    int neigh = ni * n + nj;
                    ds.unionByRank(curr, neigh);
                }
            }

            if (ds.connected(0, n * n - 1))
                return h;
        }

        return -1;
    }
};
