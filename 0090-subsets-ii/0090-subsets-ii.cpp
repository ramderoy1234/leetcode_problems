class Solution {
  void recursion(int start,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
    ans.push_back(curr);
    for(int i=start;i<nums.size();i++){
      if(i> start && nums[i]==nums[i-1]) continue;
      curr.push_back(nums[i]);
      recursion(i+1,nums,curr,ans);
      curr.pop_back();
    }
  }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        recursion(0,nums,curr,ans);
        return ans;
    }
};