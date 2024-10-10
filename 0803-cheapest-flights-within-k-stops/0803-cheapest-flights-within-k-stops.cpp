class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
          int u=it[0];
          int v=it[1];
          int price=it[2];
          adj[u].push_back({v,price});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}}); // stops src dis
        while(!q.empty()){
          int stops=q.front().first;
          int node=q.front().second.first;
          int cost=q.front().second.second;
          q.pop();
          if(stops >k ) continue;
          for(auto it:adj[node]){
            int adjNode=it.first;
            int edgWt=it.second;
            if(cost+edgWt <dist[adjNode] && stops <=k ){
              dist[adjNode]=cost+edgWt;
              q.push({stops+1,{adjNode,cost+edgWt}});
            }
          }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};