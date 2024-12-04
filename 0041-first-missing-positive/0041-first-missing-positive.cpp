class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>mp;
        for(auto it:nums){
            if(it>0) mp.insert(it);
        }
        for(int i=1; ; i++){
            if(mp.find(i)==mp.end()){
                return i;
            }
        }
    }
};