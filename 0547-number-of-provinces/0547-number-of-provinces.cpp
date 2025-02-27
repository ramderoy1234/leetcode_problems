class  DisjointSet{
   public:
   vector<int>rank,parents;
     DisjointSet(int n){
     rank.resize(n,0);
     parents.resize(n,0);
     for(int i=0;i<n;i++){
      parents[i]=i;
     }
    }
    int findPar(int node){
      if(node==parents[node]){
        return node;
      }
      return parents[node]=findPar(parents[node]);
    }
    void unionByrank(int u, int v) {
     int ult_u = findPar(u);
     int ult_v = findPar(v);
     if (ult_u == ult_v) return;

     if (rank[ult_u] > rank[ult_v]) {  
       parents[ult_v] = ult_u; 
     } 
     else if (rank[ult_v] > rank[ult_u]) {  
       parents[ult_u] = ult_v;  
     } 
     else {  
       parents[ult_v] = ult_u;  
       rank[ult_u]++; 
     }
   }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n=isConnected.size();
        DisjointSet ds(n);
        int cnt=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
              ds.unionByrank(i,j);
            }
          }
        }
        for(int i=0;i<n;i++){
          if(ds.parents[i]==i){
            cnt++;
          }
        }
        return cnt;
    }
};