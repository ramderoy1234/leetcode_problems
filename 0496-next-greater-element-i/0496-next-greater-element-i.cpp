class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
          int ele=nums2[i];
          int num=-1;
          while(!st.empty() && st.top()<=ele){
            st.pop();
          }
          if(st.empty()){
            num=-1;
          }
          if(!st.empty()){
            num=st.top();
          }
          st.push(ele);
          mp.insert({ele,num});
        }
        vector<int>ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++){
          ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};