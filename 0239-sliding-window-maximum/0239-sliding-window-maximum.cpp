class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<n;i++){

         //  Remove indices that are out of current window
          while(!dq.empty() &&dq.front() <= i-k){
            dq.pop_front();
          }
          //  Remove elements from back which are smaller than current element
          while(!dq.empty() && nums[i]> nums[dq.back()] ){
             dq.pop_back();
          }
          dq.push_back(i);

          if(i>=k-1){
             ans.push_back(nums[dq.front()]);
          }
          
        }
        return ans;
    }
};