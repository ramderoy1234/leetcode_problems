class Solution {
  int check(vector<int>&piles,int h, int mid){
    int ans=0;
    for(int i=0;i<piles.size();i++){
      ans+=(piles[i]/mid);
      if(piles[i]%mid!=0){
        ans++;
      }
    }
    return ans<=h;
  }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<high){
          int mid=(low+high)/2;
          if(check(piles,h,mid)){
            high=mid;
          }
          else{
            low=mid+1;
          }
        }
        return low;
    }
};