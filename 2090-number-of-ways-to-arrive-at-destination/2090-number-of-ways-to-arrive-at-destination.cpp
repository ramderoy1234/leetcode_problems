class Solution {
public:
    const int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});  // {time, node}
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            long long time = pq.top().first;  
            int node = pq.top().second;      
            pq.pop();

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                if (time + edgeWt < dist[adjNode]) {
                    dist[adjNode] = time + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node]; 
                }
                else if (time + edgeWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;  
                }
            }
        }
        
        return ways[n - 1] % mod;
    }
};
