class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v;
        vector<int>c;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) v.push_back(nums[i]);
            else c.push_back(nums[i]);
        }

        for(int i=0;i<nums.size()/2;i++){
            int pos=2*i;
            int neg=2*i+1;
            nums[pos]=v[i];
            nums[neg]=c[i];
        }
        return nums;
    }
};