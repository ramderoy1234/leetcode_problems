class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int row=matrix.size();
        int col=matrix[0].size();
        int s=0;
        int e=(row*col)-1;
        while(s<=e){
          int mid=(s+e)/2;
          int ele=matrix[mid/col][mid%col];
          if(ele==target){
            return true;
          }
          else if(ele>target){
            e=mid-1;
          }
          else{
            s=mid+1;
          }
        }
        return false;
    }
};