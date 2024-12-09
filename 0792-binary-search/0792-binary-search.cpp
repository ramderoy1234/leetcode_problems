class Solution {
    int binarysearch(int s,int e, vector<int>&nums,int target){
        if(s>e) return -1;

        int mid=(s+e)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target){
            return binarysearch(mid+1,e,nums,target);
        }
        else{
            return binarysearch(s,mid-1,nums,target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        return binarysearch(s,e,nums,target);
    }
};