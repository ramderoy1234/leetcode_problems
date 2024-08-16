class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        int dist=0;

        for(int i=1;i<arrays.size();i++){
           int curr_mini=arrays[i][0];
           int curr_maxi=arrays[i].back();

           int dist1=curr_maxi-mini;
           int dist2=maxi-curr_mini;
           dist=max(dist,max(dist1,dist2));
           
           mini=min(curr_mini,mini);
           maxi=max(curr_maxi,maxi);
        }
        return dist;
    }
};
