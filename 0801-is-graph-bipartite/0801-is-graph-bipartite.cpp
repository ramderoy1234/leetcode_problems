class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
      for(int i=0;i<n;i++){
        queue<int>q;
        q.push(i);
        while(!q.empty()){
          int node=q.front();
          q.pop();
          for(auto it:graph[node]){
            if(color[it]==-1){
              q.push(it);
              color[it]=!color[node];
            }
            else if(color[it]==color[node]){
              return false;
            }
          }
        }
      }
        return true;
    }
};