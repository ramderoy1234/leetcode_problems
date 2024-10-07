class Solution{ 
void bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited,int drow[], int dcol[]){
  int n=grid.size();
  int m=grid[0].size();
   visited[row][col]=1;
   queue<pair<int,int>>q;
   q.push({row,col});
   while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
     q.pop();
     for(int i=0;i<4;i++){
       int nrow=drow[i]+r;
       int ncol=dcol[i]+c;
       if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
          q.push({nrow,ncol});
          visited[nrow][ncol]=1;
       }
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
          if(!visited[0][i] && grid[0][i]==1 ){
            bfs(0,i,grid,visited,drow,dcol);
          }
          if(!visited[n-1][i] && grid[n-1][i]==1){
            bfs(n-1,i,grid,visited,drow,dcol);
          }
        }

        for(int j=0;j<n;j++){
          if(!visited[j][0] && grid[j][0]==1){
            bfs(j,0,grid,visited,drow,dcol);
          }
          if(!visited[j][m-1] && grid[j][m-1]==1){
            bfs(j,m-1,grid,visited,drow,dcol);
          }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]==1){
              cnt++;
            }
          }
        }
        return cnt;
    }
};