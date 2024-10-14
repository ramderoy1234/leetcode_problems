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
    if(parents[node]==node){
      return node;
    }
    return parents[node]=findPar(parents[node]);
  }
  void unionByrank(int u,int v){
    int altU=findPar(u);
    int altV=findPar(v);
    if(altU==altV) return ;
    if(rank[altU]<rank[altV]){
      parents[altU]=altV;
    }
    else if(rank[altV]<rank[altU]){
      parents[altV]=altU;
    }
    else{
      parents[altV]=altU;
      rank[altU]++;
    }
  }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      int n=accounts.size();
      DisjointSet ds(n);
      unordered_map<string,int>mailMp;
      for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
          string mail=accounts[i][j];
          if(mailMp.find(mail)==mailMp.end()){
            mailMp[mail]=i;
          }
          else{
            ds.unionByrank(mailMp[mail],i);
          }
        }
      }

      vector<string>merge[n];
      for(auto it:mailMp){
        string mail=it.first;
        int node=ds.findPar(it.second);
        merge[node].push_back(mail);
      }

      vector<vector<string>>ans;
      for(int i=0;i<n;i++){
        if(merge[i].empty()) continue;
        sort(merge[i].begin(),merge[i].end());
        vector<string>temp;
        temp.push_back(accounts[i][0]);
        for(auto it:merge[i]){
          temp.push_back(it);
        }
        ans.push_back(temp);
      }
      return ans;
    }
};