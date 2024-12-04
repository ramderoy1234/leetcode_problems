class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int candi=0;
        for(auto it:nums){
            if(cnt==0){
                candi=it;
                cnt=1;
            }
            else if(it==candi){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candi;
    }
};