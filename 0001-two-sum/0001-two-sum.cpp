class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
      int n=nums.size();
      unordered_map<int,int>mp;
      int pre_sum=0;
      for(int i=0;i<n;i++){
        int sum=target-nums[i];
        if(mp.find(sum)!=mp.end()){
            return {mp[sum],i};
        }
        mp[nums[i]]=i;
      }
      return {};
    }
};