class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int>arrayrow(row);
        vector<int>arraycol(col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    arrayrow[i]=1;
                    arraycol[j]=1;
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(arrayrow[i]==1 || arraycol[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};