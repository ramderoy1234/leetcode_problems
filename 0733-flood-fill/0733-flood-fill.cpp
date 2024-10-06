class Solution {
  void dfs(int row,int col,vector<vector<int>>&image,int oldColor,int newColor,vector<vector<int>>&visited){
     int n=image.size();
     int m=image[0].size();
     if(row<0 ||row>=n || col<0 || col>=m || visited[row][col]|| image[row][col]!=oldColor ){
       return ;
     }
     image[row][col]=newColor;
     visited[row][col]=1;
     dfs(row+1,col,image,oldColor,newColor,visited);
     dfs(row-1,col,image,oldColor,newColor,visited);
     dfs(row,col+1,image,oldColor,newColor,visited);
     dfs(row,col-1,image,oldColor,newColor,visited);

  }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int oldColor=image[sr][sc];
        dfs(sr,sc,image,oldColor,color,visited);
        return image;
    }
};