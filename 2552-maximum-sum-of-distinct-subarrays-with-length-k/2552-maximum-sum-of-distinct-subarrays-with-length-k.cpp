class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0;
        long long sum=0;
        long long maxi=0;
        unordered_map<int,int>mp;
        for(int j=0;j<nums.size();j++){
           sum+=nums[j];
           mp[nums[j]]++;
            if(j-i+1>k){
             sum-=nums[i];
             mp[nums[i]]--;
             if(mp[nums[i]]==0) mp.erase(nums[i]);
             i++;
            }

            if(j-i+1==k && mp.size()==k){
                maxi=max(maxi,sum);
            }

        }
        return maxi;
    }
};