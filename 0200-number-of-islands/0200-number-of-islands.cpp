class Solution {
  void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&visited,int drow[],int dcol[]){
    int n=grid.size();
    int m=grid[0].size();
    visited[row][col]=1;
    for(int i=0;i<4;i++){
      int nrow=drow[i]+row;
      int ncol=dcol[i]+col;
      if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1' ){
        dfs(nrow,ncol,grid,visited,drow,dcol);
      }
    }
  }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int drow[]={0,1,0,-1};
        int dcol[]={-1,0,1,0};
        int cnt=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]=='1'){
              cnt++;
              dfs(i,j,grid,visited,drow,dcol);
            }
          }
        }
        return cnt;
    }
};