#include <vector>
using namespace std;

class DSU {
    vector<int> rank, parent;
public:
    DSU(int n) {
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
    
    bool unionByRank(int x, int y) {
        int rootX = findPar(x);
        int rootY = findPar(y);
        
        if (rootX == rootY) return false;  // Cycle detected
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootY] < rank[rootX]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DSU dsu(n);
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            int left = leftChild[i];
            int right = rightChild[i];

            if (left != -1) {
                if (++inDegree[left] > 1) return false;  // Multiple parents
                if (!dsu.unionByRank(i, left)) return false;  // Cycle detected
            }

            // Process right child
            if (right != -1) {
                if (++inDegree[right] > 1) return false;  // Multiple parents
                if (!dsu.unionByRank(i, right)) return false;  // Cycle detected
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.findPar(i) == i) cnt++;
            if (cnt > 1) return false;  // More than one root found
        }
        
        return cnt== 1;
    }
};
