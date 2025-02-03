class Solution {
    void recursion(int n, vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        if(n==0){
            return ans.push_back(curr);
        } 

        recursion(n-1,nums,curr,ans);
        curr.push_back(nums[n-1]);
        recursion(n-1,nums,curr,ans);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>curr;
        vector<vector<int>>ans;
        recursion(n,nums,curr,ans);
        return ans;
    }
};