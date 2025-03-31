class Solution {
    bool dfs(int row,int col,int parentRow,int parentCol,vector<vector<char>>& grid,vector<vector<int>>&visited){
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        int drow[]={0,1,0,-1};
        int dcol[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&grid[nrow][ncol]==grid[row][col] ){
                if(!visited[nrow][ncol]){
                    if(dfs(nrow,ncol,row,col,grid,visited)) return true;
                }
                else if(nrow!=parentRow || ncol!=parentCol){
                     return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,grid,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};