class Solution {
  void subsets(int i,vector<int>&candi,int target,vector<int>&curr,vector<vector<int>>&ans){
    if(i==candi.size()){
      if(target==0)
        ans.push_back(curr);
      return ;
    }
    if(candi[i]<=target){
      curr.push_back(candi[i]);
      subsets(i,candi,target-candi[i],curr,ans);
      curr.pop_back();
    }
    subsets(i+1,candi,target,curr,ans);
  }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        subsets(0,candidates,target,curr,ans);
        return ans;
    }
};