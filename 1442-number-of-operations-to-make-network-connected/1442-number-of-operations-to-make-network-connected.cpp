class DisjointSet{
  vector<int>rank,parents;
  public:
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

  void unionByrank(int u,int v){
    int ult_u=findPar(u);
    int ult_v=findPar(v);
    if(ult_u==ult_v) return ;
    if(rank[ult_u]<rank[ult_v]){
      parents[ult_u]=ult_v;
    }
    else if(rank[ult_v]<rank[ult_u]){
      parents[ult_v]=ult_u;
    }
    else{
      parents[ult_v]=ult_u;
      rank[ult_u]++;
    }
  }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt=0;
       for(auto it:connections){
        int u=it[0];
        int v=it[1];
         if(ds.findPar(u)==ds.findPar(v)){
           cnt++;
         }
         else{
          ds.unionByrank(u,v);
         }
       }

       int reqCon=0;
       for(int i=0;i<n;i++){
        if(ds.findPar(i)==i){
          reqCon++;
        }

       }
       int ans=reqCon-1;
       if(cnt>=ans){
         return ans;
       }
       return -1;
    }
};