class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
          int u=it[0];
          int v=it[1];
          int wt=it[2];
          adj[u].push_back({v,wt});
        }
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push({0,k}); // node dist
      vector<int>dist(n+1,INT_MAX);
      dist[k]=0;
      while(!pq.empty()){
        int time=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
          int adjNode=it.first;
          int edgWt=it.second;
          if(time+edgWt < dist[adjNode]){
            dist[adjNode]=edgWt+time;
            pq.push({edgWt+time,adjNode});
          }
        }
      }
      int maxi=0;
      for(int i=1;i<=n;i++){
        maxi=max(maxi,dist[i]);
      }
      return maxi==INT_MAX?-1:maxi;
    }
};