class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n=graph.size();
      vector<vector<int>>adj(n);
      vector<int>indegree(n,0);
      for(int i=0;i<n;i++){
        for(auto it:graph[i]){
          adj[it].push_back(i);
        }
      }
      
      for(int i=0;i<n;i++){
        for(auto it:adj[i]){
          indegree[it]++;
        }
      }

      queue<int>q;
      for(int i=0;i<n;i++){
        if(indegree[i]==0){
          q.push(i);
        }
      }
      vector<int>ans;

      while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto it:adj[node]){
          indegree[it]--;
          if(indegree[it]==0){
            q.push(it);
          }
        }
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};