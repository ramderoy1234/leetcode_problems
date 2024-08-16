
class DSU {
    vector<int> rank, parent;   
public:
   DSU(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
      parent[i]=i;
     }
   }

    int findparent(int node) {
       if(parent[node]==node) return node;

       else{
         return parent[node]=findparent(parent[node]);
       }
    }

    void unionByRank(int u, int v){
      int p_u=findparent(u);
      int p_v=findparent(v);

      if(p_u==p_v) return ;
      else if(parent[p_u]<parent[p_v]){
        parent[p_u]=p_v;
      }
      else{
        parent[p_v]=p_u;
        
        
        rank[p_u]++;
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
