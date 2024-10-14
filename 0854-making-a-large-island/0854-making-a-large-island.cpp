class DisjointSet {
public:
    vector<int> rank, parents, size;

    DisjointSet(int n) {
        rank.resize(n, 0);
        parents.resize(n);
        size.resize(n, 1);  // Initialize each component size to 1
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    int findPar(int node) {
        if (parents[node] == node) {
            return node;
        }
        return parents[node] = findPar(parents[node]);
    }

    void unionByrank(int u, int v) {
        int altU = findPar(u);
        int altV = findPar(v);
        if (altU == altV) return;
        if (rank[altU] < rank[altV]) {
            parents[altU] = altV;
            size[altV] += size[altU];  // Update size of the component
        }
        else if (rank[altV] < rank[altU]) {
            parents[altV] = altU;
            size[altU] += size[altV];  // Update size of the component
        }
        else {
            parents[altV] = altU;
            size[altU] += size[altV];  // Update size of the component
            rank[altU]++;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Union all adjacent land cells (1's)
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int drow[] = {0, 1, 0, -1};
                int dcol[] = {-1, 0, 1, 0};
                for (int i = 0; i < 4; i++) {
                    int nrow = drow[i] + row;
                    int ncol = dcol[i] + col;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                        int node = row * n + col;
                        int adjNode = nrow * n + ncol;
                        ds.unionByrank(node, adjNode);
                    }
                }
            }
        }
        // Step 2: Try flipping each 0 and calculate the largest possible island
        int ans = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int drow[] = {0, 1, 0, -1};
                int dcol[] = {-1, 0, 1, 0};
                set<int> comp;  // To avoid counting the same component twice
                int currentSize = 1;  // 1 for flipping the current 0 to 1
                for (int i = 0; i < 4; i++) {
                    int nrow = drow[i] + row;
                    int ncol = dcol[i] + col;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                        int root = ds.findPar(nrow * n + ncol);
                        comp.insert(root); 
                    }
                }
                
                for (auto root : comp) {
                    currentSize += ds.size[root];  
                }
                
                ans = max(ans, currentSize);
            }
        }
        // Step 3: Check if the grid is already full of 1's (edge case)
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    ans = max(ans, ds.size[ds.findPar(row * n + col)]);
                }
            }
        }
        return ans;
    }
};
