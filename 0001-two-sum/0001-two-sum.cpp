class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
          int sum=target-nums[i];
          if(mp.find(sum)!=mp.end()){
            return {mp[sum],i};
          }
          else{
            mp[nums[i]]=i;
          }
        }
        return {};
    }
};