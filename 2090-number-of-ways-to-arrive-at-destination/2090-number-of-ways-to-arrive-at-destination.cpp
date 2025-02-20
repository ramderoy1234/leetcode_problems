class Solution {
    const int mod=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long>ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0}); // time and start node
        while(!pq.empty()){
            long long time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgWt=it.second;
                if(time+edgWt < dist[adjNode]){
                    dist[adjNode]=time+edgWt;
                    pq.push({time+edgWt,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(edgWt+time ==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};