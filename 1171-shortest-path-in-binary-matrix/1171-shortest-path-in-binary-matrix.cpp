class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1}); // row col lenght;
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
       int drow[] = {-1, -1, -1, 0, 1, 1, 1, 0};  
       int dcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
       vector<vector<int>>visited(n,vector<int>(m,0));
       visited[0][0]=1;
       while(!q.empty()){
          int row=q.front().first.first;
          int col=q.front().first.second;
          int lenght=q.front().second;
          if(row==n-1 && col==m-1){
            return lenght;
          }
          q.pop();
          for(int i=0;i<8;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==0 ){
                q.push({{nrow,ncol},lenght+1});
                visited[nrow][ncol]=1;
            }
          }
       }
       return -1;
    }
};