class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];       
        int maxi = arrays[0].back();   
        int maxDist = 0;      

        for (int i = 1; i < arrays.size(); i++) {
            int currentMax = arrays[i].back();
            int currentMin = arrays[i][0];

            int dist1 = currentMax - mini; 
            int dist2 = maxi - currentMin;

            maxDist = max(maxDist, max(dist1, dist2));

            maxi = max(maxi, currentMax);
            mini = min(mini, currentMin);
        }

        return maxDist;
    }
};
