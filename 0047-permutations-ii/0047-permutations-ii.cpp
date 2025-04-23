class Solution {
    void recursion(vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans,vector<bool>visited) {
        if(curr.size()==nums.size()){
          ans.push_back(curr);
          return ;
        }
        for(int i=0;i<nums.size();i++){
          if(visited[i]) continue;
          if(i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
          visited[i]=true;
          curr.push_back(nums[i]);
          recursion(nums,curr,ans,visited);
          curr.pop_back();
          visited[i]=false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Important to group duplicates
        vector<vector<int>>ans;
        vector<int> curr;
        vector<bool>visited(nums.size(), false);
        recursion(nums,curr,ans,visited);
        return ans;
    }
};
