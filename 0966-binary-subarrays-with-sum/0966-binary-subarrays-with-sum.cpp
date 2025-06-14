class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        int cnt=0;
        unordered_map<int,int>mp;
        for(int j=0;j<nums.size();j++){
          sum+=nums[j];
          if(sum==goal) cnt++;
          if(mp.find(sum-goal)!=mp.end()){
            cnt+=mp[sum-goal];
          }
          mp[sum]++;
        }
        return cnt;
    }
};