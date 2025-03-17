class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<int>prev=points[0];
        int cnt=1;
        for(int i=1;i<n;i++){
          int currSt=points[i][0];
          int currEnd=points[i][1];
          
          int prevSt=prev[0];
          int prevEnd=prev[1];
          if(currSt>prevEnd){  // not overlapping
             cnt++;
             prev=points[i];
          }
          else{   // overlapping 
               prev[0]=max(prevSt,currSt);
               prev[1]=min(prevEnd,currEnd);
          }
        }
        return cnt;
    }
};