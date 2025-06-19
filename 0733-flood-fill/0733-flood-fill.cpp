class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q; // row col
        int initialColor=image[sr][sc];
        // If the initial color is already the target color, return the image as is
        if(initialColor==color) return image;

        image[sr][sc]=color;

        q.push({sr,sc});
        int drow[]={0,1,0,-1};
        int dcol[]={-1,0,1,0};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  && image[nrow][ncol]==initialColor){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};