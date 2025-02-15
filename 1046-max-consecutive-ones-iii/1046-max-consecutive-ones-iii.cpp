class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int maxi=0;
        int zeroCnt=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                zeroCnt++;
            }
            while(zeroCnt>k){
                if(nums[i]==0){
                    zeroCnt--;
                }
                i++;
            }
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};