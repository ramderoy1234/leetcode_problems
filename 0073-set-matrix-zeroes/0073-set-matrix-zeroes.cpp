class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>arrayRow(n);
        vector<int>arrayCol(m);
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
              arrayRow[i]=1;
              arrayCol[j]=1;
            }
          }
        }

        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(arrayRow[i]==1 || arrayCol[j]==1){
              matrix[i][j]=0;
            }
          }
        }
        
    }
};