class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q; // row col time
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    cnt++;
                }
                else{
                    grid[i][j]=0;
                }
            }
        }

        int drow[]={0,1,0,-1};
        int dcol[]={-1,0,1,0};
        int maxi=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            maxi=max(maxi,time);
            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol]=2;
                    cnt--;
                }
            }
        }
        if(cnt!=0){
            return -1;
        }
        return maxi;
    }
};