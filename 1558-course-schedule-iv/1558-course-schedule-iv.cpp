class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            int a=it[0];
            int b=it[1];
            adj[a].push_back(b);
            indegree[b]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        unordered_map<int,unordered_set<int>>mp;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nbr:adj[node]){
                mp[nbr].insert(node);
                for(auto pre:mp[node]){
                    mp[nbr].insert(pre);
                }

                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        vector<bool>result(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];

           bool reachable = mp[v].count(u); // count means contains 
            result[i]=reachable;
        }
        return result;
    }
};