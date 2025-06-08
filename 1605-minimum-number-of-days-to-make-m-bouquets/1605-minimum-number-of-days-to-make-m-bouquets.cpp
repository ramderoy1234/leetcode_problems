class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=0;
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){
          int mid=(s+e)/2;
          int bouq=0;
          int cnt=0;
          for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
              cnt++;
              if(cnt==k){
                bouq++;
                cnt=0;
              }
            }
            else{
              cnt=0;
            }
          }
          if(bouq>=m){
            ans=mid;
            e=mid-1;
          }
          else{
            s=mid+1;
          }
        }
        return ans;
    }
};