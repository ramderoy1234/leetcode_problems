class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
          int a=it[0];
          int b=it[1];
          adj[b].push_back(a);
          indegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
          if(indegree[i]==0){
            q.push(i);
          }
        }
        int cnt=0;
        vector<int>ans;
        while(!q.empty()){
          int node=q.front();
          ans.push_back(node);
          cnt++;
          q.pop();
          for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
              q.push(it);
            }
          }
        }
        if(cnt==numCourses) return ans;
        else return {};
    }
};