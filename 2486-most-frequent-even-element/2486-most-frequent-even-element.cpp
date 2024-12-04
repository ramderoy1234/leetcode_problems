class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            if(it%2==0) mp[it]++;
        }
        int ans=-1;
        int maxi=0;
        for(auto c:mp){
            if(c.second>maxi || ( c.second==maxi && c.first <ans )){
                maxi=c.second;
                ans=c.first;
            }
        }
        return ans;
    }
};