class Solution {
  int find(vector<int>&weights,int cap){
    int days=1;
    int load=0;
    for(int i=0;i<weights.size();i++){
      if(weights[i]+load > cap){
        days++;
        load=weights[i];
      }
      else{
        load+=weights[i];
      }
    }
    return days;
  }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);
        while(s<=e){
          int cap=(s+e)/2;
          int shipcapacity=find(weights,cap);
          if(shipcapacity<=days){
            e=cap-1;
          }
          else{
            s=cap+1;
          }
        }
        return s;
    }
};