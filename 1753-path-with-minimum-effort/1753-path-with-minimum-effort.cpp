class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      int n=heights.size();
      int m=heights[0].size();
      vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
      dist[0][0]=0;
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
      pq.push({0,{0,0}}); // effort row col;

      int drow[]={0,1,0,-1};
      int dcol[]={-1,0,1,0};
      while(!pq.empty()){
        int effort=pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        pq.pop();
        if(row==n-1 && col==m-1){
          return effort;
        }
        for(int i=0;i<4;i++){
          int nrow=drow[i]+row;
          int ncol=dcol[i]+col;

          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
             int newEffort = max(effort, abs(heights[row][col] - heights[nrow][ncol]));

             if(newEffort < dist[nrow][ncol] ){
               dist[nrow][ncol]=newEffort;
               pq.push({newEffort,{nrow,ncol}});
             }
          }
        }

      }
      return 0;
    }
};