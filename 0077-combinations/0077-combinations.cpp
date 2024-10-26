class Solution {
    void recursion(int i,int n,int k,vector<int>&arr,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(arr);
            return ;
        }
        if(i>n) return ;
        arr.push_back(i);
        recursion(i+1,n,k-1,arr,ans);
        arr.pop_back();
        recursion(i+1,n,k,arr,ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        vector<vector<int>>ans;
        recursion(1,n,k,arr,ans);
        return ans;
    }
};