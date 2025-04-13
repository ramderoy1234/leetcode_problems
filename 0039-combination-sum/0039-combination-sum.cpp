class Solution {
  void recursion(int i,vector<int>& candidates, int target,vector<int>&curr,vector<vector<int>>&ans){
    if(i==candidates.size()){
      if(target==0) ans.push_back(curr);
      return ;
    }

    if(candidates[i]<=target){
      curr.push_back(candidates[i]);
      recursion(i,candidates,target-candidates[i],curr,ans);
      curr.pop_back();
    }
    recursion(i+1,candidates,target,curr,ans);
  }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        recursion(0,candidates,target,curr,ans);
        return ans;
    }
};