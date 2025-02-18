class Solution {
    void dfs(int row,int col,vector<vector<char>>&board,vector<vector<int>>&visited,int drow[],int dcol[]){
        int n=board.size();
        int m=board[0].size();
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,visited,drow,dcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int drow[]={0,1,0,-1};
        int dcol[]={-1,0,1,0};

        for(int i=0;i<m;i++){
            if(!visited[0][i] && board[0][i]=='O'){
                dfs(0,i,board,visited,drow,dcol);
            }
            if(!visited[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,board,visited,drow,dcol);
            }
        }

        for(int j=0;j<n;j++){
            if(!visited[j][0] && board[j][0]=='O'){
                dfs(j,0,board,visited,drow,dcol);
            }
            if(!visited[j][m-1] && board[j][m-1]=='O'){
                dfs(j,m-1,board,visited,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};