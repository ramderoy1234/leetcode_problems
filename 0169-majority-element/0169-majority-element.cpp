class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candi=0;
        int cnt=0;
        for(auto num:nums){
          if(cnt==0){
            candi=num;
            cnt=1;
          }
          else if(num==candi){
            cnt++;
          }
          else{
            cnt--;
          }
        }
        cnt=0;
        for(auto num:nums){
          if(candi==num) cnt++;
        }
        if(cnt > n/2) return candi;
        else return -1;
    }
};
