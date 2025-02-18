class Solution {
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited , int drow[],int dcol[] ){
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,visited,drow,dcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int drow[]={0,1,0,-1};
        int dcol[]={-1,0,1,0};
        
        for(int i=0;i<m;i++){
            if(!visited[0][i] && grid[0][i]==1){
                dfs(0,i,grid,visited,drow,dcol);
            }
            if(!visited[n-1][i] && grid[n-1][i]==1 ){
                dfs(n-1,i,grid,visited,drow,dcol);
            }
        }

        for(int j=0;j<n;j++){
            if(!visited[j][0] && grid[j][0]==1){
                dfs(j,0,grid,visited,drow,dcol);
            }
            if(!visited[j][m-1] && grid[j][m-1]==1){
                dfs(j,m-1,grid,visited,drow,dcol);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};