class Solution {
    void findcom(int i,vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&ds){
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return ;
        }
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            findcom(i,candidates,target-candidates[i],ans,ds);
            ds.pop_back();
        }

        findcom(i+1,candidates,target,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcom(0,candidates, target,ans,ds);
        return ans;
    }
};