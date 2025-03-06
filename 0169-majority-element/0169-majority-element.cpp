class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int candi=0;
        for(auto it:nums){
            if(cnt==0){
                candi=it;
                cnt++;
            }
           else if(candi==it){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candi;
    }
};