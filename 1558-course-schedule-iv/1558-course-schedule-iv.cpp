class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            indegree[b]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<unordered_set<int>> prereq(numCourses); // Track prerequisites for each node

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int it : adj[node]) {
                prereq[it].insert(node);
                prereq[it].insert(prereq[node].begin(), prereq[node].end()); // Merge prerequisites
                
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        vector<bool> res;
        for (auto& q : queries) {
            res.push_back(prereq[q[1]].count(q[0]) > 0);
        }
        return res;
    }
};
