class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp(nums.begin(),nums.end());
        int maxi=0;
        for(auto it:mp){
            if(mp.find(it-1)==mp.end()){
                int lenght=1;
                while(mp.find(it+lenght)!=mp.end()){
                    lenght++;
                }
                maxi=max(maxi,lenght);
            }
        }
        return maxi;
    }
};