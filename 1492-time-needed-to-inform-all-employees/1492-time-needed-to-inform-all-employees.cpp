class Solution {
  void dfs(vector<vector<int>>& adj, vector<int>& informTime, int& maxiTime, int curr_Emp, int curr_Time) {
      maxiTime = max(maxiTime, curr_Time);
      for (auto it : adj[curr_Emp]) {
          dfs(adj, informTime, maxiTime, it, curr_Time + informTime[curr_Emp]);
      }
  }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        int maxTime = 0;
        dfs(adj, informTime, maxTime, headID, 0);
        return maxTime;
    }
};
